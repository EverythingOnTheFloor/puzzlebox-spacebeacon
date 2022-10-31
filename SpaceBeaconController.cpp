#include "SpaceBeaconController.h"

SpaceBeaconController::SpaceBeaconController()
{

}

void SpaceBeaconController::initialize(){
    mpu.initalize();
}
void SpaceBeaconController::update(){
    mpu.read();
}
