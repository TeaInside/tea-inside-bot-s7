
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <tg_icetea/wrapper.h>
#include <tg_icetea/TgIceTea.hpp>

#define STH(tgic) (tgic)->handler

extern "C" {

tg_icetea_obj *tg_icetea_init(tg_icetea_opt *opt)
{
    tg_icetea_obj *tgic = (tg_icetea_obj *)malloc(sizeof(tg_icetea_obj));
    STH(tgic) = new TgIceTea(opt->token, opt->bot_username);
    return tgic;
}

void tg_process_update(tg_icetea_obj *tgic, char *json)
{
    STH(tgic)->processUpdate(json);
}

void tg_icetea_destroy(tg_icetea_obj *tgic)
{
    delete STH(tgic);
    free(tgic);
    printf("Destroyed!\n");
}

} // extern "C"
