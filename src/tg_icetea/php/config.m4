
PHP_ARG_ENABLE(tg_icetea,
  [Whether to enable the "tg_icetea" extension],
  [  --enable-tg_icetea        Enable "tg_icetea" extension support])

if test $PHP_TG_ICETEA != "no"; then
    PHP_NEW_EXTENSION(tg_icetea, src/tg_icetea_php.c, $ext_shared,, "-Wall -lpthread")
fi
