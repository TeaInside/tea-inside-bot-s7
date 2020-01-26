
#ifndef __TG_ICETEA__TGICETEA_HPP
#define __TG_ICETEA__TGICETEA_HPP

namespace tg_icetea {

class TgIceTea
{
public:
    TgIceTea(char *token, char *bot_username);

private:
    char token[64];
    char bot_username[64];
};

} // namespace

#define tea_log(log_lvl, ...) \
    if (log_lvl <= cfg.log_level) (__internal_debug_log(__VA_ARGS__))

#endif
