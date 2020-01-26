
#ifndef __TG_ICETEA__QUEUES_HPP
#define __TG_ICETEA__QUEUES_HPP

#include <tg_icetea/QueueData.hpp>

#define QUEUE_AMOUNT 100

namespace tg_icetea {

class Queues
{
public:
    QueueData queues[QUEUE_AMOUNT];

    Queues();

    uint32_t addQueue(json &&in_json)
    {
        uint32_t i;

        for (i = 0; i < QUEUE_AMOUNT; ++i) {
            if (!this->queues[i].busy) {
                this->queues[i].plug(std::move(in_json));
                break;
            }
        }

        return i;
    }
};

} // namespace tg_icetea

#endif
