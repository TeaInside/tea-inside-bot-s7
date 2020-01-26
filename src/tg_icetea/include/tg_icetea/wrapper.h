
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
    char *bot_username;
} tg_icetea_opt;

tg_icetea_obj *tg_icetea_init(tg_icetea_opt *opt);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
