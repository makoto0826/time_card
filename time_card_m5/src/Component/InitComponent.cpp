#include <M5Dial.h>
#include "BLE.h"
#include "Component/InitComponent.h"

/**
 * @brief 初期化処理を実行します。
 *
 * この関数は、InitComponentクラスのインスタンスが作成された後に呼び出されます。
 * 初期化処理は、各コンポーネントの初期化を行うためのメソッドです。
 * この関数を呼び出すことで、コンポーネントの初期化が行われます。
 */
void InitComponent::run()
{
  bool completedSetting = false;
  bool oldConnected = false;
  String passKey;

  auto ble = BLE::getInstance();
  ble->settingCallback = [&](BLE::SettingCallbackResult *result)
  {
    if (result->successed)
    {
      completedSetting = true;
    }
  };

  ble->authCallback = [&](BLE::AuthCallbackResult *result)
  {
    passKey = "";
    
    if (result->successed)
    {
      USBSerial.println("auth success");
    }
    else
    {
      USBSerial.println("auth failed");
    }
  };

  ble->passKeyCallback = [&](BLE::PasskeyCallbackResult *result)
  {
    passKey = result->passKey;
  };

  ble->start();

  while (1)
  {
    M5Dial.update();

    if (!ble->connected && oldConnected)
    {
      ble->start();
      USBSerial.println("bluetooth start");
      oldConnected = ble->connected;
    }

    if (ble->connected && !oldConnected)
    {
      oldConnected = ble->connected;
    }

    this->canvas->fillRect(0, 0, M5Dial.Display.width(), M5Dial.Display.height(), BLACK);
    this->canvas->drawString("初期設定", M5Dial.Display.width() / 2, M5Dial.Display.height() * 0.1);

    if (completedSetting)
    {
      this->canvas->drawString("設定が完了しました", M5Dial.Display.width() / 2, M5Dial.Display.height() / 2);
      this->canvas->drawString("再起動してください", M5Dial.Display.width() / 2, M5Dial.Display.height() / 2 + canvas->fontHeight() + 5);
    }
    else
    {
      if (passKey.isEmpty())
      {
        this->canvas->drawString("接続を待っています...", M5Dial.Display.width() / 2, M5Dial.Display.height() / 2);
      }
      else
      {
        this->canvas->drawString("PIN:" + passKey, M5Dial.Display.width() / 2, M5Dial.Display.height() / 2);
      }
    }

    this->canvas->pushSprite(0, 0);
  }
}

/**
 * @brief 初期化コンポーネントを破棄します。
 *
 * この関数は、初期化コンポーネントを破棄するために使用されます。
 * 破棄処理は、初期化コンポーネントのリソースを解放し、関連するオブジェクトをクリーンアップします。
 *
 * @note この関数は、初期化コンポーネントの使用が終了した後に呼び出す必要があります。
 */
void InitComponent::dispose()
{
  BLE::getInstance()->stop();
}