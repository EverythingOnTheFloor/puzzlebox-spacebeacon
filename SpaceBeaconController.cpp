#include "SpaceBeaconController.h"

SpaceBeaconController::SpaceBeaconController()
{
}

void SpaceBeaconController::displayLoadingAnimation(long tick,int speed){
    int index = tick % 6 *  speed;
    if(index >= 5 * speed){
        display.drawCustom(true,false,false,false,false,false,false);
    }else if (index >= 4 * speed)
    {
        display.drawCustom(false,true,false,false,false,false,false);
    }
    else if (index >= 3 * speed)
    {
        display.drawCustom(false,false,true,false,false,false,false);
    }
    else if (index >= 2 * speed)
    {
        display.drawCustom(false,false,false,true,false,false,false);
    }
    else if (index >= 1 * speed)
    {
        display.drawCustom(false,false,false,false,true,false,false);
    }
    else if (index >=0)
    {
        display.drawCustom(false,false,false,false,false,true,false);
    }
}
void SpaceBeaconController::initialize(){
    //mpu.initalize();   
    pinMode(BUTTON_ENTER_PIN, INPUT);
    pinMode(BUTTON_SELECT_PIN, INPUT);
    _cardDoor.attach(SERVO_CARD_DOOR_PIN);
    _endDoor.attach(SERVO_END_DOOR_PIN);
    _cardDoor.write(SERVO_CARD_DOOR_CLOSED);
    _endDoor.write(SERVO_END_DOOR_CLOSED);
    display.setEnabled(true);
    _currentGameState = GAMESTATE_STARTUP_ANIMATION;
    Serial.println("Initialization Done!");
}
void SpaceBeaconController::update(){
    switch (_currentGameState) {
        case GAMESTATE_INITIALIZE:
        if(Serial.available())
            Serial.println("[ERROR] Box has not been correctly initialized!");
            break;
        case GAMESTATE_STARTUP_ANIMATION:
            //ANIMATION CODE HERE
            _currentGameState = GAMESTATE_UNLOCK_BOX;
            break;
        case GAMESTATE_UNLOCK_BOX:
            if(_enterButtonIsPressed || _selectButtonIsPressed)
                _currentGameState = GAMESTATE_ROLL_PERIODE;
            break;
        case GAMESTATE_ROLL_PERIODE:
            //SELECT RANDOM NUMBER AND ANIMATION
            _currentGameState = GAMESTATE_ENTER_NUMBER;
            break;
        case GAMESTATE_ENTER_NUMBER:
            if(_selectButtonIsPressed){
                currentSelectedNumber++;
                if(currentNumber > 9){
                    currentSelectedNumber = 0;
                }
            }
            else if (_enterButtonIsPressed)
            {
                if(currentNumber == currentSelectedNumber){
                    _currentGameState = GAMESTATE_ENTER_CORRECT_CARD_NUMBER;
                }else{
                    _currentGameState = GAMESTATE_WRONG_CARD_NUMBER;
                }
            }
            break;
        case GAMESTATE_ENTER_CORRECT_NUMBER:
            //PLAY ANIMATION
            ammountOfCorrectNumbers++;
            if(ammountOfCorrectNumbers >= 3){
                _currentGameState = GAMESTATE_ENTERED_ALL_NUMBERS;
            }
            break;
        case GAMESTATE_WRONG_NUMBER:
            //PLAY ANIMATION
            ammountOfCorrectNumbers = 0;
            _currentGameState = GAMESTATE_ROLL_PERIODE;
            break;
        case GAMESTATE_ENTERED_ALL_NUMBERS:
            //PLAY ANIMATION
            _currentGameState = GAMESTATE_CARD_BOX_OPEN;
            break;
        case GAMESTATE_CARD_BOX_OPEN:
            _cardDoor.write(SERVO_CARD_DOOR_OPEN);
            _currentGameState = GAMESTATE_ENTER_CARD_NUMBER;
            ammountOfCorrectNumbers = 0;
            break;
        case GAMESTATE_ENTER_CARD_NUMBER:
         if(_selectButtonIsPressed){
                currentSelectedNumber++;
                if(currentNumber > 9){
                    currentSelectedNumber = 0;
                }
            }
            else if (_enterButtonIsPressed)
            {
                if(selectedCardNumbers[0] == -1){
                    selectedCardNumbers[0] == currentSelectedNumber;
                    currentSelectedNumber = 0;
                }
                else if(selectedCardNumbers[1] == -1)
                {
                    selectedCardNumbers[1] == currentSelectedNumber;
                    currentSelectedNumber = 0;
                }
                else if (selectedCardNumbers[2] == -1)
                {
                    selectedCardNumbers[2] == currentSelectedNumber;
                    _currentGameState = GAMESTATE_ENTERED_ALL_CARD_NUMBERS;
                }
            }
            break;
        case GAMESTATE_ENTERED_ALL_CARD_NUMBERS:
            if(selectedCardNumbers[0] == CARD_NUMBER_1 && selectedCardNumbers[1] == CARD_NUMBER_2 && selectedCardNumbers[2] == CARD_NUMBER_3){
                _currentGameState = GAMESTATE_ENTER_CORRECT_CARD_NUMBER;
            }else{
                _currentGameState = GAMESTATE_WRONG_CARD_NUMBER;
            }
            break;
        case GAMESTATE_ENTER_CORRECT_CARD_NUMBER:
            // PLAY ANIMATION
            break;
        case GAMESTATE_WRONG_CARD_NUMBER:
            // PLAY ANIMATION
            _currentGameState = GAMESTATE_ENTER_CARD_NUMBER;
            selectedCardNumbers[0] = -1;
            selectedCardNumbers[1] = -1;
            selectedCardNumbers[2] = -1;
            break;
        case GAMESTATE_INSERT_ANTENNA:
            if(_antennaIsInserted){
                _currentGameState = GAMESTATE_ALIGN_TO_SATELITE;
            }
            break;
        case GAMESTATE_ZERO_GYRO:
        // PLACE BOX ON TABLE AND PRESS BUTTON;
        if(_enterButtonIsPressed ||_selectButtonIsPressed){
            mpu.zeroGyro();
            mpu.zeroAccel();
            _currentGameState = GAMESTATE_ALIGN_TO_SATELITE;
        }
            break;
        case GAMESTATE_ALIGN_TO_SATELITE:
        // PLAY ANIMATION
        /*
        if(GYRONUMBERS MATCH selected vector){

        }
        */
       _currentGameState = GAMESTATE_IS_ALIGNED;
            break;
        case GAMESTATE_IS_ALIGNED:
        //PLAY ANIMATINON
            break;
        case GAMESTATE_LOST_CONNECTION:
            break;
        case GAMESTATE_CONNECTION_SUCCESS:
            break;
        case GAMESTATE_OPEN_END_BOX:
        _endDoor.write(SERVO_END_DOOR_OPEN);
            break;
  default:
    // Statement(s)
    break; // Wird nicht benötigt, wenn Statement(s) vorhanden sind
}
    //mpu.read();
    long m = lmillis();
    if(m >= lastMillis + TICKSPEED){
        lastMillis = m;
        ++currentTick;
    }
      _enterButtonIsPressed = digitalRead(BUTTON_ENTER_PIN);
      _selectButtonIsPressed = digitalRead(BUTTON_ENTER_PIN);
      _antennaIsInserted = digitalRead(ANTENNA_PIN);
}


