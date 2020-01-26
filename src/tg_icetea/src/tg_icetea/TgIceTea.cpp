
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
    this->in = json::parse(json_string);
    printf("json: %s\n", this->in.dump().c_str());
}

} // namespace tg_icetea
