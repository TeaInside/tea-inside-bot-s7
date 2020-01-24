
#ifndef __ICETEA__TEABOT__EXE_H
#define __ICETEA__TEABOT__EXE_H

#include <string>
#include <utility>
#include <json/json.hpp>

using nlohmann::json;

namespace TeaBot {

struct ExeRes
{
    bool is_error;
    std::string error;
    std::string output;
};

class Exe
{
public:
    static std::string cturl(const char *url);
    static std::string post(const char *method, json payload);
    static std::string get(const char *method, std::string param = "");
private:
    static void initUrl();
};

}

#endif
