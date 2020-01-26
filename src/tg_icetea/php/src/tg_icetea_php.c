
#include "tg_icetea_php.h"

/**
 * @author Ammar Faizi <ammarfaizi2@gmail.com> https://www.facebook.com/ammarfaizi2
 * @license MIT
 * @version 7.0
 */
#ifdef COMPILE_DL_TEABOT
    #ifdef ZTS
        ZEND_TSRMLS_CACHE_DEFINE()
    #endif
    ZEND_GET_MODULE(tg_icetea)
#endif

ZEND_DECLARE_MODULE_GLOBALS(tg_icetea);

zend_class_entry *tg_icetea_ce;

/**
 * Method list of TgIceTea\TgIceTea.
 */
const zend_function_entry tg_icetea_methods[] = {
    PHP_ME(TgIceTea_TgIceTea, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(TgIceTea_TgIceTea, process_update, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

/**
 * Extension Init.
 */
static PHP_MINIT_FUNCTION(tg_icetea)
{
    zend_class_entry ce1;
    INIT_NS_CLASS_ENTRY(ce1, "TgIceTea", "TgIceTea", tg_icetea_methods);
    tg_icetea_ce = zend_register_internal_class(&ce1 TSRMLS_CC);
    REGISTER_INI_ENTRIES();
    return SUCCESS;
}

/**
 * Extension Shutdown.
 */
static PHP_MSHUTDOWN_FUNCTION(tg_icetea)
{
    UNREGISTER_INI_ENTRIES();
    return SUCCESS;
}

/**
 * Extension Global Init.
 */
static PHP_GINIT_FUNCTION(tg_icetea)
{
    #if defined(COMPILE_DL_ASTKIT) && defined(ZTS)
        ZEND_TSRMLS_CACHE_UPDATE();
    #endif
}

/**
 * PHP Module Entry.
 */
zend_module_entry tg_icetea_module_entry = {
    STANDARD_MODULE_HEADER,
    "tg_icetea",
    NULL, /* functions */
    PHP_MINIT(tg_icetea),
    PHP_MSHUTDOWN(tg_icetea),
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
    TG_ICETEA_PHP_VERSION,
    PHP_MODULE_GLOBALS(tg_icetea),
    PHP_GINIT(tg_icetea),
    NULL, /* GSHUTDOWN */
    NULL, /* RPOSTSHUTDOWN */
    STANDARD_MODULE_PROPERTIES_EX
};

ZEND_GET_MODULE(tg_icetea)
