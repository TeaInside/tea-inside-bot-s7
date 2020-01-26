
#include <cstdio>
#include <iostream>
#include <icetea/icetea.h>
#include <icetea/teabot/Exe.h>

extern icetea_config cfg;
static char baseUrl[1024] = {0};

namespace TeaBot {

/**
 * Static URL initializer.
 */
void Exe::initUrl()
{
    if (baseUrl[0] == '\0') {
        sprintf(baseUrl, "https://api.telegram.org/bot%s/", ::cfg.token);
    }
}

std::string Exe::cturl(const char *url)
{
}

std::string Exe::get(const char *method, std::string param)
{
}

std::string Exe::post(const char *method, json payload)
{
    return "";
}

} // namespace TeaBot
