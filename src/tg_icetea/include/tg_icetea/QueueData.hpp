
#ifndef __TG_ICETEA__QUEUEDATA_HPP
#define __TG_ICETEA__QUEUEDATA_HPP


namespace tg_icetea {

class QueueData
{
public:
    bool busy = false;

    json &in;
    int64_t &chat_id;
    uint64_t &user_id;

    QueueData();

    void plug(json &&in) {
        this->in = std::move(in);
        this->chat_id = this->in["message"]["chat"].value("id", 0LL);
        this->user_id = this->in["message"]["from"].value("id", 0LL);
    }
};

} // namespace tg_icetea

#endif
