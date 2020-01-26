
#ifndef __TG_ICETEA__QUEUEDATA_HPP
#define __TG_ICETEA__QUEUEDATA_HPP

#include <cstdint>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace tg_icetea {

class QueueData
{
public:
    bool busy = false;

    json &in;
    int64_t &chat_id;
    uint64_t &user_id;

    QueueData();
    void plug(json &&in);
};

} // namespace tg_icetea

#endif
