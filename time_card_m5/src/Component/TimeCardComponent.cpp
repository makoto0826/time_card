#include <M5Dial.h>
#include "Component/TimeCardComponent.h"

/**
 * @brief TimeCardComponent の実行関数です。
 *
 * この関数は、TimeCardComponent の動作を開始します。
 */
void TimeCardComponent::run()
{
  while (1)
  {
    M5Dial.update();

    if (M5Dial.BtnA.pressedFor(1000))
    {
      M5Dial.BtnA.setRawState(0, false);
      break;
    }

    int newPosition = M5Dial.Encoder.read();

    if (newPosition != this->position)
    {
      int diff = abs(newPosition - this->position);

      if (diff >= 3)
      {
        this->state.tabState = this->state.tabState == 1 ? 2 : 1;
        M5Dial.Speaker.tone(8000, 20);
        M5Dial.Encoder.readAndReset();
        this->position = 0;
      }
    }

    if (M5Dial.Rfid.PICC_IsNewCardPresent() && M5Dial.Rfid.PICC_ReadCardSerial())
    {
      uint8_t piccType = M5Dial.Rfid.PICC_GetType(M5Dial.Rfid.uid.sak);

      String uid = "";
      for (byte i = 0; i < M5Dial.Rfid.uid.size; i++)
      {
        Serial.printf("%02X ", M5Dial.Rfid.uid.uidByte[i]);
        uid += String(M5Dial.Rfid.uid.uidByte[i], HEX);
      }
    }

    struct tm timeinfo;
    getLocalTime(&timeinfo);

    char buffer[30];
    sprintf(buffer, "%04d/%02d/%02d", timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday);
    this->state.date = String(buffer);
    sprintf(buffer, "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
    this->state.time = String(buffer);

    if (this->state == this->oldState)
    {
      continue;
    }

    this->oldState.date = this->state.date;
    this->oldState.time = this->state.time;
    this->oldState.tabState = this->state.tabState;

    this->canvas->fillRect(0, 0, M5Dial.Display.width(), 120, BLACK);
    this->canvas->setTextColor(WHITE);
    this->canvas->setTextDatum(textdatum_t::middle_center);
    this->canvas->drawString(state.date, M5Dial.Display.width() / 2, M5Dial.Display.height() * 0.1);
    this->canvas->drawString(state.time, M5Dial.Display.width() / 2, M5Dial.Display.height() * 0.2);

    switch (state.tabState)
    {
    case 1:
      this->canvas->fillRect(0, M5Dial.Display.height() / 2, M5Dial.Display.width(), M5Dial.Display.height() / 2, RED);
      break;
    case 2:
      this->canvas->fillRect(0, M5Dial.Display.height() / 2, M5Dial.Display.width(), M5Dial.Display.height() / 2, BLUE);
      break;
    default:
      break;
    }

    this->canvas->pushSprite(&M5Dial.Display, 0, 0);
  }
}

void TimeCardComponent::dispose()
{
}