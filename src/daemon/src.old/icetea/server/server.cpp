
/**
 * IceTea-S7
 *
 * @author Ammar Faizi <ammarfaizi2@gmail.com>
 * @license MIT
 * @version 7.0.0
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <icetea/teabot/Exe.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <inih/ini.h>
#include <icetea/icetea.h>
#include <icetea/server/server.h>

icetea_config cfg;

static bool config_err = false;
static inline bool load_config();

/**
 * Run the TeaBot server.
 */
uint8_t init_daemon()
{
    if (!load_config()) {
        return 1;
    }

    // Initialize baseurl to telegram API.
    TeaBot::Exe::initUrl();

    return 0;
}

static int config_handler(void* user, const char* section, const char* name, const char* value)
{
    if (config_err) {
        return 1;
    }

    if (!strcmp(section, "bot")) {
        if (!strcmp(name, "token")) {
            cfg.token = strdup(value);
            tea_log(5, "Loaded bot token");
            debug_log("Bot token \"%s\"", cfg.token);
        }
    } else if (!strcmp(section, "database")) {

        #define DBMC(A) \
            if (!strcmp(name, #A)) { \
                cfg.db.A = strdup(value); \
                tea_log(5, "Loaded database "#A); \
                debug_log("Database "#A " \"%s\"", cfg.db.A); \
            }

        DBMC(host) else
        DBMC(user) else
        DBMC(pass) else
        DBMC(dbname) else
        if (!strcmp(name, "port")) {
            cfg.db.port = atoi(value);
            tea_log(5, "Loaded database port");
            debug_log("Database port %d", cfg.db.port);
        } else {
            tea_log(0,
                "Parse error: invalid key \"%s\" on section \"%s\"",
                name, section);
            config_err = true;
        }

        #undef DBMC
    }

    return 1;
}

/**
 * Load TeaBot config.
 */
static inline bool load_config()
{
    memset(&cfg, 0, sizeof(cfg));
    cfg.log_level = 4;

    tea_log(0, "Loading config...");

    if (ini_parse("config.ini", config_handler, NULL) < 0) {
        printf("Can't load \"config.ini\"\n");
        return false;
    }

    if (config_err) {
        return false;
    }

    return true;
}


#ifdef __cplusplus
}
#endif
