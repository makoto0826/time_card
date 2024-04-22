#ifndef _INIT_COMPONENT_H_
#define _INIT_COMPONENT_H_

#include <M5Dial.h>

class InitComponent
{
public:
  InitComponent(M5Canvas *canvas)
  {
    this->canvas = canvas;
  }

  ~InitComponent() = default;

  void run();

  void dispose();
private:
  M5Canvas *canvas;
};

#endif