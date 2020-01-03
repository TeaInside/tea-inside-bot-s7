
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
#include <string.h>
#include <icetea/server/server.h>

static inline int load_config();

/**
 * Run the TeaBot server.
 */
uint8_t run_server()
{
    load_config();

    return 0;
}

static int load_config_handler(
    void* user, const char* section,
    const char* name, const char* value)
{
    #define config (())


    if (!strcmp(section, "bot")) {
        if (!strcmp(name, "token")) {

        }
    }

    return 1;
}

/**
 * Load TeaBot config.
 */
int load_config()
{
    configuration config;

    if (ini_parse("test.ini", load_config_handler, &config) < 0) {
        printf("Can't load 'test.ini'\n");
        return 1;
    }
    printf("Config loaded from 'test.ini': version=%d, name=%s, email=%s\n",
        config.version, config.name, config.email);
    return 0;
}


#ifdef __cplusplus
}
#endif