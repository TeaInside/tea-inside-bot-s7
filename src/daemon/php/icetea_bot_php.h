

#ifndef ICETEA_BOT_H
#define ICETEA_BOT_H

    #define ICETEA_BOT_VERSION "7.0"

    #include "php.h"

    #ifdef HAVE_CONFIG_H
        #include "config.h"
    #endif

    #ifdef ZTS
        #include "TSRM.h"
    #endif

    PHP_INI_BEGIN()
    PHP_INI_END()

    extern zend_module_entry icetea_bot_module_entry;

    PHP_METHOD(TeaBot_Daemon, __construct);
    PHP_METHOD(TeaBot_Daemon, run);

    ZEND_BEGIN_MODULE_GLOBALS(icetea_bot)
    ZEND_END_MODULE_GLOBALS(icetea_bot)
    ZEND_EXTERN_MODULE_GLOBALS(icetea_bot)
    #define PHPNASMG(v) ZEND_MODULE_GLOBALS_ACCESSOR(icetea_bot, v)


    #if defined(ZTS) && defined(COMPILE_DL_SAMPLE)
        ZEND_TSRMLS_CACHE_EXTERN()
    #endif

    #define phpext_icetea_bot_ptr &icetea_bot_module_entry
#endif
