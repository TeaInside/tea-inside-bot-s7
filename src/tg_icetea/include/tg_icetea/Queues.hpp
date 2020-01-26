
#ifndef __TG_ICETEA__QUEUES_HPP
#define __TG_ICETEA__QUEUES_HPP

#include <cstdint>
#include <tg_icetea/QueueData.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#define QUEUE_AMOUNT 100

namespace tg_icetea {

class Queues
{
public:
    QueueData queues[QUEUE_AMOUNT];

    Queues();
    uint32_t addQueue(json &&in_json);
};

} // namespace tg_icetea

#endif
