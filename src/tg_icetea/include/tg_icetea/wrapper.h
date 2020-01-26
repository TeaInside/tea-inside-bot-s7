
#ifndef __TG_ICETEA__WRAPPER_H
#define __TG_ICETEA__WRAPPER_H

#ifdef __cplusplus
#include <tg_icetea/TgIceTea.hpp>
using namespace tg_icetea;
extern "C" {
#endif

typedef struct {
#ifdef __cplusplus
    TgIceTea *handler;
#else
    void *handler;
#endif
} tg_icetea_obj;

typedef struct {
    char *token;
    char *username;
} tg_icetea_opt;

tg_icetea_obj *tg_icetea_init(tg_icetea_opt *opt);
void tg_icetea_destroy(tg_icetea_obj *tgic);
void tg_icetea_process_update(tg_icetea_obj *tgic, char *json);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
