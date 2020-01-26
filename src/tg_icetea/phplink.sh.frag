#!/usr/bin/env bash

cc -shared \
php/src/.libs/tg_icetea_php.o \
-Wl,-R \
-Wl,~$$BASEDIR$$~ \
\-Wl,-soname \
-Wl,icetea_bot.so \
-o php/modules/tg_icetea.so -ltg-icetea-s7 -L~$$BASEDIR$$~
