//
// Created by Jakub Górski on 02/08/2022.
//

#include "IP_VALIDATOR.h"

bool IP_VALIDATOR::isNumber(const std::string &str) {
    return !str.empty() && (str.find_first_not_of("[0123456789]") == std::string::npos);
}

std::vector<std::string> IP_VALIDATOR::split(const std::string &str, char delimiter) {
    auto i = 0;
    std::vector<std::string> list;

    auto pos = str.find(delimiter);

    while (pos != std::string::npos) {
        list.push_back(str.substr(i, pos - i));
        i = ++pos;
        pos = str.find(delimiter, pos);
    }
    list.push_back(str.substr(i, str.length()));
    return list;
}

bool IP_VALIDATOR::validateIP(std::string ip) {
    std::vector<std::string> list = split(ip, '.');

    if (list.size() != 4) {
        return false;
    }

    for (const std::string& str : list)
    {
        if (!isNumber(str) || stoi(str) > 255 || stoi(str) < 0) {
            return false;
        }
    }
    return true;
}
