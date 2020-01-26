
/**
 * IceTea-S7
 *
 * @author Ammar Faizi <ammarfaizi2@gmail.com>
 * @license MIT
 * @version 7.0.0
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include <icetea/server/server.h>

int icetea_bot_daemon_init()
{
    init_daemon();
    return 0;
}

void icetea_bot_update_handler(char *json)
{
    printf("Data: %s\n", json);
}

#ifdef __cplusplus
}
#endif
