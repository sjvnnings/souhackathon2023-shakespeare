//
// Created by sammy on 3/28/2023.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_COMMAND_H
#define SOUHACKATHON2023_SHAKESPEARE_COMMAND_H
#include <iostream>

class Command {
protected:
    std::string params;
public:
    void set_params(std::string params);
    virtual void execute() = 0;
};


#endif //SOUHACKATHON2023_SHAKESPEARE_COMMAND_H
