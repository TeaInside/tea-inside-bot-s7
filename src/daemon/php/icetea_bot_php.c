
#include "icetea_bot_php.h"

/**
 * @author Ammar Faizi <ammarfaizi2@gmail.com> https://www.facebook.com/ammarfaizi2
 * @license MIT
 * @version 7.0
 */
#ifdef COMPILE_DL_TEABOT
    #ifdef ZTS
        ZEND_TSRMLS_CACHE_DEFINE()
    #endif
    ZEND_GET_MODULE(icetea_bot)
#endif


ZEND_DECLARE_MODULE_GLOBALS(icetea_bot);

zend_class_entry *icetea_bot_daemon_ce;

/**
 * TeaBot\Daemon
 */
const zend_function_entry icetea_bot_daemon_class_methods[] = {
    PHP_ME(TeaBot_Daemon, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(TeaBot_Daemon, run, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};


/**
 * Init.
 */
static PHP_MINIT_FUNCTION(icetea_bot)
{
    zend_class_entry ce1;

    INIT_NS_CLASS_ENTRY(ce1, "TeaBot", "Daemon",
        icetea_bot_daemon_class_methods);
    icetea_bot_daemon_ce = zend_register_internal_class(&ce1 TSRMLS_CC);

    REGISTER_INI_ENTRIES();

    return SUCCESS;
}

/**
 * Shutdown.
 */
static PHP_MSHUTDOWN_FUNCTION(icetea_bot)
{
    UNREGISTER_INI_ENTRIES();
    return SUCCESS;
}

/**
 * Global init.
 */
static PHP_GINIT_FUNCTION(icetea_bot)
{
    #if defined(COMPILE_DL_ASTKIT) && defined(ZTS)
        ZEND_TSRMLS_CACHE_UPDATE();
    #endif
}

zend_module_entry icetea_bot_module_entry = {
    STANDARD_MODULE_HEADER,
    "icetea_bot",
    NULL, /* functions */
    PHP_MINIT(icetea_bot),
    PHP_MSHUTDOWN(icetea_bot),
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
    ICETEA_BOT_VERSION,
    PHP_MODULE_GLOBALS(icetea_bot),
    PHP_GINIT(icetea_bot),
    NULL, /* GSHUTDOWN */
    NULL, /* RPOSTSHUTDOWN */
    STANDARD_MODULE_PROPERTIES_EX
};

ZEND_GET_MODULE(icetea_bot)
