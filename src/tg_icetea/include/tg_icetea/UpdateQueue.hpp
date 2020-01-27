
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
    json in;
    int hx;
    int64_t chat_id;
    int64_t user_id;
    update_msg_type msg_type;

    void plug(json &in);
};

}; // namespace tg_icetea

#endif
