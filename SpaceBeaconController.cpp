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
    mpu.initalize();    
    display = FlopDisplay(0,1,2,3,4,5,6,7);
    displayMode = DISPLAYMODE_ANIMATION;
}
void SpaceBeaconController::update(){
    mpu.read();
    long m = lmillis();
    if(m >= lastMillis + tickSpeed){
        lastMillis = m;
        ++currentTick;
    }
}
