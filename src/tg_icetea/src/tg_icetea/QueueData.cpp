
#include <tg_icetea/QueueData.hpp>

namespace tg_icetea {

void QueueData::plug(json &&in)
{
    this->in = std::move(in);
    this->chat_id = this->in["message"]["chat"].value("id", 0LL);
    this->user_id = this->in["message"]["from"].value("id", 0LL);
}

} // namespace tg_icetea
