
#include <stdio.h>
#include <stdlib.h>

#include "../icetea_bot_php.h"
#include "../../include/icetea/bridge.h"

/**
 * @package \TeaBot
 * @author Ammar Faizi <ammarfaizi2@gmail.com>
 * @license MIT
 */

extern zend_class_entry *icetea_bot_daemon_ce;

PHP_METHOD(TeaBot_Daemon, __construct)
{
    icetea_bot_daemon_init();
}

PHP_METHOD(TeaBot_Daemon, run)
{
    char *json;
    size_t length;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(json, length)
    ZEND_PARSE_PARAMETERS_END();

    icetea_bot_update_handler(json);
}
