// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       FloppaBox.ino
    Created:	17.03.2022 19:26:19
    Author:     LAPTOP-DPUVHQB5\juliu
*/

// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts

//#include <Servo.h>
//#include "LedController.h"

#include "SpaceBeaconController.h"
//FlopDisplay display = FlopDisplay(2, 3, 4, 5, 6, 7, 8, 9);
//Servo myservo;
SpaceBeaconController beacon;
void setup()
{
  Serial.begin(115200); 
  Serial.println("yeet111");
  beacon.initialize();
  
   // myservo.attach(A0);
    //myservo.write(50);//160 and 50
   // display.drawCustom(false, false, false, false, false, false, true);
}

void loop()
{  
  beacon.update();
}