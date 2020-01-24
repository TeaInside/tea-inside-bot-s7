
PHP_ARG_ENABLE(icetea_bot,
  [Whether to enable the "icetea_bot" extension],
  [  --enable-icetea_bot        Enable "icetea_bot" extension support])

if test $PHP_icetea_bot != "no"; then
  PHP_SUBST(SAMPLE_SHARED_LIBADD)
  PHP_NEW_EXTENSION(icetea_bot, icetea_bot_php.c,, "-Wall")
fi
