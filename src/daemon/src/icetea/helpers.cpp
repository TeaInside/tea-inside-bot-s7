
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

#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

uint8_t __internal_debug_log(const char *msg, ...)
{
    va_list argp;
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char *time = asctime(timeinfo);
    time[24] = '\0';

    va_start(argp, msg);
    fprintf(stdout, "[%s]: ", time);
    vfprintf(stdout, msg, argp);
    fprintf(stdout, "\n");
    va_end(argp);
    fflush(stdout);

    return 0;
}

#ifdef __cplusplus
}
#endif
