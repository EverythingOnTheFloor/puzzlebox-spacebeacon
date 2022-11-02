// 
// 
// 
/*
-AAA-
F---B
F---B
F---B
-GGG-
E---C
E---C
E---C
-DDD-
      DP

*/
#include "FlopDisplay.h"

FlopDisplay::FlopDisplay(int pin_a, int pin_b, int pin_c, int pin_d, int pin_e, int pin_f, int pin_g, int pin_dp)
{
	pinMode(pin_a, OUTPUT);
	this->pin_a = pin_a;
	pinMode(pin_b, OUTPUT);
	this->pin_b = pin_b;
	pinMode(pin_c, OUTPUT);
	this->pin_c = pin_c;
	pinMode(pin_d, OUTPUT);
	this->pin_d = pin_d;
	pinMode(pin_e, OUTPUT);
	this->pin_e = pin_e;
	pinMode(pin_f, OUTPUT);
	this->pin_f = pin_f;
	pinMode(pin_g, OUTPUT);
	this->pin_g = pin_g;
	pinMode(pin_dp, OUTPUT);
	this->pin_dp = pin_dp;
}

void FlopDisplay::drawDot(bool isOn)
{
	if (isOn) 
	{
		digitalWrite(pin_dp, HIGH);
	}
	else 
	{
		digitalWrite(pin_dp, LOW);
	}

}

void FlopDisplay::drawCustom(int status_pin_a, int status_pin_b, int status_pin_c, int status_pin_d, int status_pin_e, int status_pin_f, int status_pin_g)
{
	digitalWrite(pin_a, status_pin_a);
	digitalWrite(pin_b, status_pin_b);
	digitalWrite(pin_c, status_pin_c);
	digitalWrite(pin_d, status_pin_d);
	digitalWrite(pin_e, status_pin_e);
	digitalWrite(pin_f, status_pin_f);
	digitalWrite(pin_g, status_pin_g);
}

void FlopDisplay::drawNumber(int number)
{
	if (number < 0 || number > 9) return;

	digitalWrite(pin_a, LOW);
	digitalWrite(pin_b, LOW);
	digitalWrite(pin_c, LOW);
	digitalWrite(pin_d, LOW);
	digitalWrite(pin_e, LOW);
	digitalWrite(pin_f, LOW);
	digitalWrite(pin_g, LOW);

	switch (number) {
	case 0:
	{
		digitalWrite(pin_a, HIGH);
		digitalWrite(pin_b, HIGH);
		digitalWrite(pin_c, HIGH);
		digitalWrite(pin_d, HIGH);
		digitalWrite(pin_e, HIGH);
		digitalWrite(pin_f, HIGH);
	}
	break;
	case 1: 
	{
		digitalWrite(pin_b, HIGH);
		digitalWrite(pin_c, HIGH);
	} 
		break;       
	case 2: 
	{
		digitalWrite(pin_a, HIGH);
		digitalWrite(pin_b, HIGH);
		digitalWrite(pin_d, HIGH);
		digitalWrite(pin_e, HIGH);
		digitalWrite(pin_g, HIGH);
	}
		break;
	case 3:
	{
		digitalWrite(pin_a, HIGH);
		digitalWrite(pin_b, HIGH);
		digitalWrite(pin_c, HIGH);
		digitalWrite(pin_d, HIGH);
		digitalWrite(pin_g, HIGH);
	}
	break;
	case 4:
	{
		digitalWrite(pin_b, HIGH);
		digitalWrite(pin_c, HIGH);
		digitalWrite(pin_f, HIGH);
		digitalWrite(pin_g, HIGH);
	}
	break;
	case 5:
	{
		digitalWrite(pin_a, HIGH);
		digitalWrite(pin_c, HIGH);
		digitalWrite(pin_d, HIGH);
		digitalWrite(pin_f, HIGH);
		digitalWrite(pin_g, HIGH);
	}
	break;
	case 6:
	{
		digitalWrite(pin_a, HIGH);
		digitalWrite(pin_c, HIGH);
		digitalWrite(pin_d, HIGH);
		digitalWrite(pin_e, HIGH);
		digitalWrite(pin_f, HIGH);
		digitalWrite(pin_g, HIGH);
	}
	break;
	case 7:
	{
		digitalWrite(pin_a, HIGH);
		digitalWrite(pin_b, HIGH);
		digitalWrite(pin_c, HIGH);
	}
	break;
	case 8:
	{
		digitalWrite(pin_a, HIGH);
		digitalWrite(pin_b, HIGH);
		digitalWrite(pin_c, HIGH);
		digitalWrite(pin_d, HIGH);
		digitalWrite(pin_e, HIGH);
		digitalWrite(pin_f, HIGH);
		digitalWrite(pin_g, HIGH);
	}
	break;
	case 9:
	{
		digitalWrite(pin_a, HIGH);
		digitalWrite(pin_b, HIGH);
		digitalWrite(pin_c, HIGH);
		digitalWrite(pin_d, HIGH);
		digitalWrite(pin_f, HIGH);
		digitalWrite(pin_g, HIGH);
	}
	break;
	}
}
