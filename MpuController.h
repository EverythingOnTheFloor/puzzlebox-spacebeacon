#ifndef MpuController_h
#define MpuController_h

#include "MPU6050_6Axis_MotionApps20.h"

class MpuController
{
public:
    MpuController();
    void initalize();
    void read();
    void zeroAccel();
    void zeroGyro();
    void getAccel(int &x, int &y, int &z);
    void getGyro(float &x, float &y, float &z);

    MPU6050 mpu;



private:
    bool dmpReady = false;
    uint8_t devStatus;
    uint16_t fifoCount;
    uint8_t fifoBuffer[64];
    Quaternion q;
    VectorInt16 aa;
    VectorInt16 aaReal;
    VectorFloat gravity;
    float ypr[3];
    char* toStr(int16_t value);

};

#endif