
#ifndef __TG_ICETEA__TGICETEA_HPP
#define __TG_ICETEA__TGICETEA_HPP

#include <cstdint>

namespace tg_icetea {

class TgIceTea
{
public:
    TgIceTea(char *token, char *bot_username);
    void processUpdate(char *json);

private:
    char token[64];
    char bot_username[64];

    uint8_t log_level = 0;
};

} // namespace tg_icetea

uint8_t __internal_debug_log(const char *msg, ...);

#ifdef ICETEA_DEBUG
#define tea_log(log_lvl, ...) \
    if (log_lvl <= this->log_level) (__internal_debug_log(__VA_ARGS__))
#else
#define tea_log(log_lvl, ...)
#endif

#endif
