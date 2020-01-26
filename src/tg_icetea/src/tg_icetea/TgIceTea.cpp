
#include <cstdio>
#include <cstring>
#include <tg_icetea/TgIceTea.hpp>

namespace tg_icetea {

/**
 * Constructor.
 *
 * @param char *token (Bot token)
 * @param char *bot_username (Bot username which belongs to bot token)
 */
TgIceTea::TgIceTea(char *token, char *bot_username)
{
    tea_log(4, "Initializing TgIceTea...");

    strcpy(this->token, token);
    strcpy(this->bot_username, bot_username);
}

/**
 * Process update from Telegram server.
 *
 * @param char *json
 */
void TgIceTea::processUpdate(char *json)
{
    
}

} // namespace tg_icetea
