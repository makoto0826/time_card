#ifndef _TIME_CARD_APP_DEVICE_H_
#define _TIME_CARD_APP_DEVICE_H_

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "Setting.h"

class BLE
{
public:
    class SettingCallbackResult
    {
    public:
        Setting *setting;
        bool successed;

        SettingCallbackResult(Setting *setting, bool successed)
        {
            this->setting = setting;
            this->successed = successed;
        }
    };

    class PasskeyCallbackResult
    {
    public:
        String passKey;

        PasskeyCallbackResult(String passKey)
        {
            this->passKey = passKey;
        }
    };  

    class AuthCallbackResult
    {
    public:
        bool successed;

        AuthCallbackResult(bool successed)
        {
            this->successed = successed;
        }
    };

    BLEServer *server;
    BLEService *service;
    BLECharacteristic *txCharacteristic;
    bool connected;

    std::function<void(SettingCallbackResult *)> settingCallback = nullptr;
    std::function<void(AuthCallbackResult *)> authCallback = nullptr;
    std::function<void(PasskeyCallbackResult *)> passKeyCallback = nullptr;

    static BLE *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new BLE();
            instance->setup();
        }

        return instance;
    }

    void start();

    void stop();

private:
    BLE() = default;
    ~BLE() = default;

    static BLE *instance;

    void setup();
};

#endif