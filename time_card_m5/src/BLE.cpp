#include <M5Dial.h>
#include <ArduinoJson.h>
#include "BLE.h"

#define BLE_NAME "TIME-CARD"
#define SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

BLE *BLE::instance = nullptr;

class AppServerCallbacks : public BLEServerCallbacks
{
  void onConnect(BLEServer *pServer)
  {
    BLE::getInstance()->connected = true;
  }

  void onDisconnect(BLEServer *pServer)
  {
    BLE::getInstance()->connected = false;
  }
};

class AppSettingCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    auto device = BLE::getInstance();
    auto value = pCharacteristic->getValue();

    for (int i = 0; i < value.length(); i++)
    {
      USBSerial.print(value[i]);
    }

    JsonDocument doc;
    auto error = deserializeJson(doc, value.c_str());

    if (error.code() != DeserializationError::Ok)
    {
      USBSerial.println("json parse error");
      device->settingCallback(new BLE::SettingCallbackResult(nullptr, false));
      device->txCharacteristic->setValue("{ 'status' : '400.1'}");
      device->txCharacteristic->notify();
      return;
    }

    bool hasError = false;
    const char *ssid = doc["ssid"];
    const char *password = doc["password"];
    const char *ip = doc["ip"];
    const char *subnet = doc["subnet"];
    const char *gateway = doc["gateway"];
    const char *dns1 = doc["dns1"];
    const char *dns2 = doc["dns2"];
    const char *apiKey = doc["apiKey"];
    const char *baseEndpoint = doc["baseEndpoint"];

    if (!ssid)
      hasError = true;
    if (!password)
      hasError = true;
    if (!ip)
      hasError = true;
    if (!subnet)
      hasError = true;
    if (!gateway)
      hasError = true;
    if (!dns1)
      hasError = true;
    if (!dns2)
      hasError = true;
    if (!apiKey)
      hasError = true;
    if (!baseEndpoint)
      hasError = true;

    if (hasError)
    {
      USBSerial.println("setting parameter error");
      device->settingCallback(new BLE::SettingCallbackResult(nullptr, false));
      device->txCharacteristic->setValue("{ 'status' : '400.2'}");
      device->txCharacteristic->notify();
      return;
    }

    auto setting = new Setting(
        String(ssid),
        String(password),
        String(ip),
        String(subnet),
        String(gateway),
        String(dns1),
        String(dns2),
        String(apiKey),
        String(baseEndpoint));

    device->settingCallback(new BLE::SettingCallbackResult(setting, true));
    device->txCharacteristic->setValue("{ 'status' : 200}");
    device->txCharacteristic->notify();
  }
};

class AppSecurityCallbacks : public BLESecurityCallbacks
{
  String passkey;

  bool onConfirmPIN(uint32_t pin)
  {
    return false;
  }

  uint32_t onPassKeyRequest()
  {
    return 123456;
  }

  void onPassKeyNotify(uint32_t pass_key)
  {
    USBSerial.println("onPassKeyNotify");
    BLE::getInstance()->passKeyCallback(new BLE::PasskeyCallbackResult(String(pass_key)));
  }

  bool onSecurityRequest()
  {
    return true;
  }

  void onAuthenticationComplete(esp_ble_auth_cmpl_t cmpl)
  {
    auto ble = BLE::getInstance();

    if (cmpl.success)
    {
      ble->authCallback(new BLE::AuthCallbackResult(true));
      USBSerial.println("onAuthenticationComplete success");
    }
    else
    {
      ble->authCallback(new BLE::AuthCallbackResult(false));
      USBSerial.println("onAuthenticationComplete failure");
    }
  }
};

void BLE::setup()
{
  BLEDevice::init(BLE_NAME);

  BLEDevice::setEncryptionLevel(ESP_BLE_SEC_ENCRYPT_MITM);
  BLEDevice::setSecurityCallbacks(new AppSecurityCallbacks());

  this->server = BLEDevice::createServer();
  this->server->setCallbacks(new AppServerCallbacks());
  this->service = this->server->createService(SERVICE_UUID);

  auto pSecurity = new BLESecurity();
  pSecurity->setAuthenticationMode(ESP_LE_AUTH_BOND);
  pSecurity->setCapability(ESP_IO_CAP_OUT);
  pSecurity->setInitEncryptionKey(ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK);

  this->txCharacteristic = this->service->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
  this->txCharacteristic->setCallbacks(new AppSettingCallbacks());
  this->txCharacteristic->addDescriptor(new BLE2902());

  auto pRxCharacteristic = this->service->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
  pRxCharacteristic->setCallbacks(new AppSettingCallbacks());

  auto advertising = this->server->getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID);
}

void BLE::start()
{
  this->service->start();
  this->server->getAdvertising()->start();
}

void BLE::stop()
{
  this->service->stop();
  this->server->getAdvertising()->stop();
}