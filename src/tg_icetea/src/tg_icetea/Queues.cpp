
#include <tg_icetea/Queues.hpp>

namespace tg_icetea {

uint32_t Queues::addQueue(json &&in_json)
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

} // namespace tg_icetea
