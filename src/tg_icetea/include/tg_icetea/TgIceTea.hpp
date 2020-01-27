
#ifndef __TG_ICETEA__TGICETEA_HPP
#define __TG_ICETEA__TGICETEA_HPP

#define DEBUG_LEVEL 10
#define QUEUE_QUOTA 100

#include <cstdint>
#include <nlohmann/json.hpp>
#include <tg_icetea/UpdateQueue.hpp>

using json = nlohmann::json;

namespace tg_icetea {

class TgIceTea
{
public:
    UpdateQueue queues[QUEUE_QUOTA];
    TgIceTea(char *token, char *bot_username);
    void processUpdate(char *json_string);

private:
    
    char token[64];
    char username[64];
    uint8_t log_level = 0;

    uint32_t addQueue(json &&in);
    void dispatch(uint32_t index_queue);
};

} // namespace tg_icetea

extern "C" uint8_t __internal_debug_log(const char *msg, ...);

#ifdef ICETEA_DEBUG
#define tea_log(log_lvl, ...) \
    if (log_lvl <= DEBUG_LEVEL) (__internal_debug_log(__VA_ARGS__))
#else
#define tea_log(log_lvl, ...)
#endif

#endif
