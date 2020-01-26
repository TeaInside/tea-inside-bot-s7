#!/usr/bin/env bash

cc -shared \
php/src/.libs/tg_icetea_php.o \
-Wl,-R \
-Wl,/home/ammarfaizi2/project/now/bot-s7/src/tg_icetea \
\-Wl,-soname \
-Wl,icetea_bot.so \
-o php/modules/tg_icetea.so -ltg-icetea-s7 -L/home/ammarfaizi2/project/now/bot-s7/src/tg_icetea
