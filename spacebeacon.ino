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

#include <Adafruit_NeoPixel.h>
//#include <Servo.h>
#include "LedController.h"
//#include "FlopDisplay.h"
//FlopDisplay display = FlopDisplay(2, 3, 4, 5, 6, 7, 8, 9);
LedController led;
int i = 0;
bool up = false;
//Servo myservo;
void setup()
{
  Serial.begin(115200); 
  led.initialize();
   // myservo.attach(A0);
    //myservo.write(50);//160 and 50
   // display.drawCustom(false, false, false, false, false, false, true);
}

void loop()
{
    if(i >= 255 ||i <= 0){
          up = !up;
      }

  if(up)
    i++;
  else
   i--;

  led.setRed(i);
  delay(10);
}