#ifndef _API_H_
#define _API_H_
#include <list.h>
#include "Setting.h"

class Api
{
public:
    class TimeCardRequest
    {
    };

    class UsersResult
    {
    };

    Api(Setting* setting) {
        this->setting = setting;
    }

    ~Api() = default;

    void sendTimeCard(TimeCardRequest *request);

    UsersResult *getUsers();

private:
    Setting *setting;
};

#endif
