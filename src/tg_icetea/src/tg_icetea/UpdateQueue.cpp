
#include <iostream>
#include <tg_icetea/UpdateQueue.hpp>

namespace tg_icetea {

void UpdateQueue::plug(json &in)
{
    #define PLUGP(A, B, C) \
        if (this->B != nullptr) { \
            this->A = std::move(this->B.get_ref<C>()); \
        } else { \
            printf("Won't plug: "#B"\n"); \
        }

    this->busy = true;
    this->in = std::move(in);

    try {
        PLUGP(hx, in["qwe"]["asd"]["zxc"], json::number_integer_t&);
        PLUGP(chat_id, in["message"]["chat"]["id"], json::number_integer_t&);
        PLUGP(user_id, in["message"]["from"]["id"], json::number_integer_t&);
    } catch (json::type_error& ex) {
        printf("JSON parse error:");
        std::cout << ex.what() << '\n';
        this->busy = false;
    }
}

} // namespace tg_icetea
