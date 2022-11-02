#ifndef SpaceBeaconController_h
#define SpaceBeaconController_h
#include <Servo.h>
#include "LedController.h"
#include <AceButton.h>
#include "MpuController.h"
#include "FlopDisplay.h"

#define CARD_DOOR 2
#define END_DOOR 3
#define DISPLAYMODE_NUMBER 0
#define DISPLAYMODE_ANIMATION 1

#define lmillis() ((long)millis())

using namespace ace_button;

class SpaceBeaconController
{
  public:
    SpaceBeaconController();
    void initialize();
    void update();
    void openDoor(String door);
    void closeDoor(String door);
    void SpaceBeaconController::displayLoadingAnimation(long tick,int speed);

  private:
  int tickSpeed = 50; // in ms
  long lastMillis = 0;
  long currentTick = 0;
  int currentNumber = 0;
  int displayMode;
  LedController _ledController;
  FlopDisplay display;
  Servo _cardDoor;
  Servo _endDoor;
  AceButton _buttonSelect;
  AceButton _buttonEnter;
  MpuController mpu;
};

#endif