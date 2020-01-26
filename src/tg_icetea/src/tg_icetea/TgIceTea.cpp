
#include <cstdio>
#include <cstring>
#include <tg_icetea/TgIceTea.hpp>

namespace tg_icetea {

/**
 * Constructor.
 */
TgIceTea::TgIceTea(char *token, char *bot_username)
{
    tea_log(4, "Initializing TgIceTea...");

    strcpy(this->token, token);
    strcpy(this->bot_username, bot_username);
}


} // namespace