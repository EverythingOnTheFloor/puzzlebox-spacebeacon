#include "MpuController.h"

MpuController::MpuController()
{
}
void MpuController::zeroAccel(){
    mpu.CalibrateAccel(6);
}
void MpuController::zeroGyro(){
    mpu.CalibrateGyro(6);
}
void MpuController::initalize(){
    mpu = MPU6050();
    mpu.initialize();
    devStatus = mpu.dmpInitialize();

    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); // 1688 factory default for my test chip

    // make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        // Calibration Time: generate offsets and calibrate our MPU6050
        mpu.CalibrateAccel(6);
        mpu.CalibrateGyro(6);
        mpu.setDMPEnabled(true);
        dmpReady = true;
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
    }
}

void MpuController::getGyro(float &x, float &y, float &z){
    x = ypr[0] * 180/M_PI;
    y = ypr[1] * 180/M_PI;
    z = ypr[2] * 180/M_PI;
}

void MpuController::getAccel(int &x, int &y, int &z){
    x = aaReal.x;
    y = aaReal.y;
    z = aaReal.z;
}

void MpuController::read(){
     if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) { // Get the Latest packet 
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            // display real acceleration, adjusted to remove gravity
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetAccel(&aa, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
    }
}
