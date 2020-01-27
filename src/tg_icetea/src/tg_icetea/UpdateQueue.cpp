
#include <string>
#include <iostream>
#include <tg_icetea/UpdateQueue.hpp>

namespace tg_icetea {

#define PLUGP(A, B, C, D) \
    if (this->B != nullptr) { \
        this->A = std::move(this->B.get_ref<C>()); \
    } else { \
        printf("Won't plug: "#B"\n"); \
        this->A = D; \
    }

#define PLUGPV(A, B, C, D) \
    if (this->B != nullptr) { \
        this->A = std::move(this->B.value(C, D)); \
    } else { \
        printf("Won't plug: "#B"\n"); \
        this->A = D; \
    }

/**
 * Plug new update.
 *
 * @param json &in
 */
void UpdateQueue::plug(json &in)
{
    this->busy = true;
    this->in = std::move(in);

    try {

        PLUGP(text, in["message"]["text"], json::string_t&, "");

        if (this->in["message"]["text"] != nullptr) {
            this->msg_type = msg_text;
            this->buildGeneralData(in);
        }

    } catch (json::type_error& ex) {
        printf("JSON parse error:");
        std::cout << ex.what() << '\n';
        this->busy = false;
    }
}

/**
 * Build general update info from JSON.
 *
 * @param json &in
 */
void UpdateQueue::buildGeneralData(json &in)
{
    PLUGP(update_id, in["update_id"], json::number_integer_t&, 0);
    PLUGP(chat_id, in["message"]["chat"]["id"], json::number_integer_t&, 0);
    PLUGP(user_id, in["message"]["from"]["id"], json::number_integer_t&, 0);
    PLUGP(chat_title, in["message"]["chat"]["title"], json::string_t&, "");
    PLUGP(date, in["message"]["date"], json::number_integer_t&, 0);
    PLUGP(first_name, in["message"]["from"]["first_name"], json::string_t&, "");
    PLUGP(last_name, in["message"]["from"]["last_name"], json::string_t&, "");
    PLUGP(username, in["message"]["from"]["username"], json::string_t&, "");
    PLUGPV(is_bot, in["message"]["from"], "is_bot", false);
}

#undef PLUGP

#ifdef ICETEA_DEBUG
void UpdateQueue::debugDump()
{
    printf("user_id: %ld\n", this->user_id);
    printf("chat_id: %ld\n", this->chat_id);
    printf("chat_id: %s\n", this->chat_title.c_str());
    printf("first_name: %s\n", this->first_name.c_str());
    printf("last_name: %s\n", this->last_name.c_str());
    printf("username: %s\n", this->username.c_str());
    printf("date: %ld\n", this->date);
    printf("is_bot: %d\n", this->is_bot);
}
#endif

} // namespace tg_icetea
