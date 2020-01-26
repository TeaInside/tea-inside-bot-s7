#!/usr/bin/env bash

cc -shared \
php/.libs/icetea_bot_php.o \
php/classes/.libs/TeaBot_Daemon.o \
-Wl,-R \
-Wl,~$$BASEDIR$$~ \
\-Wl,-soname \
-Wl,icetea_bot.so \
-o php/modules/icetea_bot.so -ltg-icetea-s7 -L~$$BASEDIR$$~
