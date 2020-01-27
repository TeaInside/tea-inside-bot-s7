
#include <cstdio>
#include <cstring>
#include <tg_icetea/TgIceTea.hpp>

namespace tg_icetea {

using json = nlohmann::json;

/**
 * Constructor.
 *
 * @param char *token (Bot token)
 * @param char *username (Bot username which belongs to bot token)
 */
TgIceTea::TgIceTea(char *token, char *username)
{
    tea_log(3, "Initializing TgIceTea...");

    strncpy(this->token, token, 64);
    strncpy(this->username, username, 64);

    tea_log(5, "Bot token: %s", this->token);
    tea_log(5, "Bot username: %s", this->username);
}

/**
 * Process update from Telegram server.
 *
 * @param char *json_string
 */
void TgIceTea::processUpdate(char *json_string)
{
    this->dispatch(this->addQueue(std::move(json::parse(json_string))));
}

/**
 * Add json to queue.
 *
 * @param json &&in
 * @return uint32_t
 */
uint32_t TgIceTea::addQueue(json &&in)
{
    uint32_t i = 0;

    for (; i < QUEUE_QUOTA; ++i) {
        if (!this->queues[i].busy) {
            this->queues[i].plug(in);
            break;
        }
    }

    return i;
}

/**
 * Dispatch process.
 *
 * @param uint32_t index_queue
 */
void TgIceTea::dispatch(uint32_t index_queue)
{
    printf("Index queue: %d\n", index_queue);
    this->queues[index_queue].debugDump();
    printf("JSON: %s\n", this->queues[index_queue].in.dump().c_str());

}

} // namespace tg_icetea
