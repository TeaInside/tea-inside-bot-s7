
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

#include <inih/ini.h>

#include <icetea/icetea.h>
#include <icetea/server/server.h>

icetea_config cfg;

static inline bool load_config();

/**
 * Run the TeaBot server.
 */
uint8_t run_server()
{
    if (!load_config()) {
        return 1;
    }

    return 0;
}

static int config_handler(void* user, const char* section,
                            const char* name, const char* value)
{
    #define config (())


    if (!strcmp(section, "bot")) {
        if (!strcmp(name, "token")) {
            cfg.token = strdup(value);
            tea_log(3, "Loaded bot token");
        }
    }

    return 1;
}

/**
 * Load TeaBot config.
 */
static inline bool load_config()
{
    memset(&cfg, 0, sizeof(cfg));
    cfg.log_level = 3;

    if (ini_parse("config.ini", config_handler, NULL) < 0) {
        printf("Can't load \"config.ini\"\n");
        return 1;
    }

    return 0;
}


#ifdef __cplusplus
}
#endif
