
#ifndef __ICETEA__ICETEA_H
#define __ICETEA__ICETEA_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    char *token;
    char *basepath;
    char *storage_path;
    char *telegram_storage_path;

    struct {
        char *host;
        char *user;
        char *pass;
        char *dbname;
        uint16_t port;
    } db;

    uint64_t *sudoers;
    uint16_t log_level;
    uint8_t sudoer_count;
} icetea_config;

uint8_t __internal_debug_log(const char *msg, ...);

#define tea_log(log_lvl, ...) \
    (log_lvl <= cfg.log_level) && (__internal_debug_log(#__VA_ARGS__))

#endif
