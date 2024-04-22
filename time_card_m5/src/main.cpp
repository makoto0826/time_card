#include <M5Dial.h>
#include <Wifi.h>
#include <Arduino.h>
#include "Setting.h"
#include "Component/InitComponent.h"
#include "Component/TimeCardComponent.h"

#define APP_VERSION "0.0.1"
#define NTP_TIMEZONE "JST-9"
#define NTP_SERVER1 "ntp.nict.jp"
#define NTP_SERVER2 "ntp.jst.mfeed.ad.jp"

M5Canvas canvas(&M5Dial.Display);
uint changedCount = 0;
bool deviceInitialized = true;

void setup()
{
  auto cfg = M5.config();
  M5Dial.begin(cfg, true, true);

  USBSerial.begin(115200);

  canvas.setColorDepth(8);
  canvas.setTextColor(WHITE);
  canvas.setTextDatum(textdatum_t::middle_center);
  canvas.setFont(&fonts::lgfxJapanGothic_20);
  canvas.createSprite(M5Dial.Display.width(), M5Dial.Display.height());
  canvas.drawString("Startup...", M5Dial.Display.width() / 2, M5Dial.Display.height() / 2);
  canvas.pushSprite(0, 0);

  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);

  auto setting = Setting::load();

  if (setting == nullptr)
  {
    bool deviceInitialized = false;
    return;
  }

  WiFi.config(ip, gw, subnet, dns, dns);
  WiFi.begin(ssid, password);

  if (!M5Dial.Rtc.isEnabled())
  {
    USBSerial.println("RTC not found.");
  }

  while (WiFi.status() != WL_CONNECTED)
  {
    USBSerial.print('.');
    delay(500);
  }

  USBSerial.println("WiFi Connected.");
  configTzTime(NTP_TIMEZONE, NTP_SERVER1, NTP_SERVER2);
}

void loop()
{
  if (!deviceInitialized)
  {
    auto init = new InitComponent(&canvas);
    init->run();
    init->dispose();
  }

  M5Dial.update();

  if (M5Dial.BtnA.pressedFor(1000))
  {
    changedCount++;
    M5Dial.BtnA.setRawState(0, false);
  }

  auto componentIndex = changedCount % 2;

  switch (componentIndex)
  {
  case 0:
  {
    auto init = new InitComponent(&canvas);
    init->run();
    init->dispose();
  }
  break;
  case 1:
  {
    auto timeCard = new TimeCardComponent(&canvas);
    timeCard->run();
    timeCard->dispose();
  }
  break;
  }

  changedCount++;
}