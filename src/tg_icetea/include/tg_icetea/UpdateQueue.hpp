
#ifndef __TG_ICETEA__UPDATEQUEUE_HPP
#define __TG_ICETEA__UPDATEQUEUE_HPP

#include <stdint.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace tg_icetea {

typedef enum {
    msg_text = 1,
    msg_image = 2,
    msg_video = 3,
    msg_sticker = 4,
} update_msg_type;

class UpdateQueue
{
public:
    bool busy = false;
    bool is_bot;
    json in;
    int hx;
    uint64_t date;
    int64_t chat_id;
    uint64_t user_id;
    uint64_t update_id;
    std::string chat_title;
    std::string first_name;
    std::string last_name;
    std::string username;
    std::string text;
    update_msg_type msg_type;

    #ifdef ICETEA_DEBUG
    void debugDump();
    #endif

    void plug(json &in);
    void buildGeneralData(json &in);
};

}; // namespace tg_icetea

#endif
