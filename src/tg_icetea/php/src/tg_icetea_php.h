
#ifndef TG_ICETEA_PHP_H
#define TG_ICETEA_PHP_H

    #define TG_ICETEA_PHP_VERSION "7.0"

    #include "php.h"

    #ifdef HAVE_CONFIG_H
        #include "config.h"
    #endif

    #ifdef ZTS
        #include "TSRM.h"
    #endif

    PHP_INI_BEGIN()
    PHP_INI_END()

    extern zend_module_entry tg_icetea_module_entry;

    PHP_METHOD(TgIceTea_TgIceTea, __construct);
    PHP_METHOD(TgIceTea_TgIceTea, process_update);

    ZEND_BEGIN_MODULE_GLOBALS(tg_icetea)
    ZEND_END_MODULE_GLOBALS(tg_icetea)
    ZEND_EXTERN_MODULE_GLOBALS(tg_icetea)
    #define PHPNASMG(v) ZEND_MODULE_GLOBALS_ACCESSOR(tg_icetea, v)


    #if defined(ZTS) && defined(COMPILE_DL_SAMPLE)
        ZEND_TSRMLS_CACHE_EXTERN()
    #endif

    #define phpext_tg_icetea_ptr &tg_icetea_module_entry
#endif
