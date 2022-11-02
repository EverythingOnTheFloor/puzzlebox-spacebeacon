#ifndef SpaceBeaconController_h
#define SpaceBeaconController_h
#include <Servo.h>
#include "LedController.h"
#include <AceButton.h>
#include "MpuController.h"
#include "FlopDisplay.h"
#define TICKSPEED 50

/*---PINS---*/
#define SERVO_CARD_DOOR_PIN  A0
#define SERVO_END_DOOR_PIN   A1
#define BUTTON_SELECT_PIN     1
#define BUTTON_ENTER_PIN      2
#define ANTENNA_PIN           7

/*---DISPLAYMODES---*/
#define DISPLAYMODE_NUMBER    0
#define DISPLAYMODE_ANIMATION 1

/*---SERVO PRESETS---*/
#define SERVO_CARD_DOOR_OPEN 0
#define SERVO_CARD_DOOR_CLOSED 100
#define SERVO_END_DOOR_OPEN 0
#define SERVO_END_DOOR_CLOSED 100
/*---CARD NUMBER PRESETS*/
#define CARD_NUMBER_1 2
#define CARD_NUMBER_2 3
#define CARD_NUMBER_3 9


/*---GAMESTATES---*/
#define GAMESTATE_INITIALIZE                  0
#define GAMESTATE_STARTUP_ANIMATION           1
#define GAMESTATE_UNLOCK_BOX                  2
#define GAMESTATE_ROLL_PERIODE                3
#define GAMESTATE_ENTER_NUMBER                4
#define GAMESTATE_ENTER_CORRECT_NUMBER        5
#define GAMESTATE_WRONG_NUMBER                6
#define GAMESTATE_ENTERED_ALL_NUMBERS         7
#define GAMESTATE_CARD_BOX_OPEN               8
#define GAMESTATE_ENTER_CARD_NUMBER           9
#define GAMESTATE_ENTERED_ALL_CARD_NUMBERS   10
#define GAMESTATE_ENTER_CORRECT_CARD_NUMBER  11
#define GAMESTATE_WRONG_CARD_NUMBER          12
#define GAMESTATE_INSERT_ANTENNA             13
#define GAMESTATE_ZERO_GYRO                  14
#define GAMESTATE_ALIGN_TO_SATELITE          15
#define GAMESTATE_IS_ALIGNED                 16
#define GAMESTATE_LOST_CONNECTION            17
#define GAMESTATE_CONNECTION_SUCCESS         18
#define GAMESTATE_OPEN_END_BOX               19

#define lmillis() ((long)millis())

using namespace ace_button;

class SpaceBeaconController
{
  public:
    SpaceBeaconController();
    void initialize();
    void update();
    void SpaceBeaconController::displayLoadingAnimation(long tick,int speed);

  private:
  int _currentGameState       =  0;
  long lastMillis             =  0;
  long currentTick            =  0;
  int ammountOfCorrectNumbers =  0;
  int currentSelectedNumber   =  0;
  int currentNumber;
  int selectedCardNumbers[3] = {-1,-1,-1};
  int displayMode = DISPLAYMODE_ANIMATION;
  LedController _ledController;
  FlopDisplay display;
  Servo _cardDoor;
  Servo _endDoor;
  bool _enterButtonIsPressed  = false;
  bool _selectButtonIsPressed = false;
  bool _antennaIsInserted = false;
  MpuController mpu;
};

#endif