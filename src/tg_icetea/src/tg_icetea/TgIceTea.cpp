
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
    this->dispatch(
        this->qw.addQueue(std::move(json::parse(json_string))));
}

/**
 * Dispatch process.
 *
 * @param uint32_t index_queue
 */
void TgIceTea::dispatch(uint32_t index_queue)
{
    printf("test abc: %s", this->qw.queues[index_queue].in.dump().c_str());
}

} // namespace tg_icetea
