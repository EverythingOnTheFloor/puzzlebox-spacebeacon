#ifndef SpaceBeaconController_h
#define SpaceBeaconController_h
#include <Servo.h>
#include "LedController.h"
#include <AceButton.h>
#include "MpuController.h"
using namespace ace_button;

class SpaceBeaconController
{
  public:
    SpaceBeaconController();
    void initialize();
    void update();
    void openDoor(String door);
    void closeDoor(String door);
  private:
  LedController _ledController;
  Servo _cardDoor;
  Servo _endDoor;
  AceButton _buttonSelect;
  AceButton _buttonEnter;
  MpuController mpu;
};

#endif