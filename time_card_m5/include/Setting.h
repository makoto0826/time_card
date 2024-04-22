#ifndef _SETTING_H_
#define _SETTING_H_

#include <Arduino.h>
#include <Preferences.h>

static Preferences pref;

class Setting
{
public:
  String ssid;
  String password;
  String ip;
  String subnet;
  String gateway;
  String dns1;
  String dns2;
  String apiKey;
  String baseEndpoint;

  Setting(
      String ssid,
      String password,
      String ip,
      String subnet,
      String gateway,
      String dns1,
      String dns2,
      String apiKey,
      String baseEndpoint)
  {
    this->ssid = ssid;
    this->password = ssid;
    this->ip = ip;
    this->subnet = subnet;
    this->gateway = gateway;
    this->dns1 = dns1;
    this->dns2 = dns2;
    this->apiKey = apiKey;
    this->baseEndpoint = baseEndpoint;
  }

  static Setting *load()
  {
    pref.begin("setting");
    pref.end();

    return nullptr;
  }

  static void save(Setting *setting)
  {
    pref.begin("setting");
    pref.putString("ssid", setting->ssid);
    pref.putString("password", setting->password);
    pref.putString("ip", setting->ip);
    pref.putString("subnet", setting->subnet);
    pref.putString("gateway", setting->gateway);
    pref.putString("dns1", setting->dns1);
    pref.putString("dns2", setting->dns2);
    pref.putString("apikey", setting->apiKey);
    pref.putString("baseEndpoint", setting->baseEndpoint);
    pref.end();
  }
};

#endif