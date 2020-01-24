#!/usr/bin/env bash

cc -shared \
php/.libs/icetea_bot_php.o \
php/classes/.libs/TeaBot_Daemon.o \
-Wl,-R \
-Wl,/home/ammarfaizi2/project/now/bot-s7/src/daemon \
\-Wl,-soname \
-Wl,icetea_bot.so \
-o php/modules/icetea_bot.so -licetea-s7 -L.
