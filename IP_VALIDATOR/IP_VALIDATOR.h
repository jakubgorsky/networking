//
// Created by Jakub Górski on 02/08/2022.
//

#ifndef NETWORKING_IP_VALIDATOR_H
#define NETWORKING_IP_VALIDATOR_H

#include <vector>
#include <string>

class IP_VALIDATOR {
private:
    bool isNumber(const std::string &str);
    std::vector<std::string> split(const std::string &str, char delimiter);
public:
    bool validateIP(std::string ip);
};


#endif //NETWORKING_IP_VALIDATOR_H
