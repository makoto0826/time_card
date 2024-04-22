#ifndef _TIME_CARD_COMPONENT_H_
#define _TIME_CARD_COMPONENT_H_

#include <M5Dial.h>
#include <esp_sntp.h>
#include <sntp.h>

class TimeCardComponent
{
public:
  struct TimeCardState
  {
    String date;
    String time;
    int tabState;

    bool operator==(const TimeCardState &rhs) const
    {
      return (date == rhs.date && time == rhs.time && tabState == rhs.tabState);
    }
  };

  TimeCardComponent(M5Canvas *canvas)
  {
    this->canvas = canvas;
  }

  ~TimeCardComponent() = default;

  void run();

  void dispose();

private:
  M5Canvas *canvas;
  TimeCardState state;
  TimeCardState oldState;
  int position;
};

#endif