// FlopDisplay.h

#ifndef _FLOPDISPLAY_h
#define _FLOPDISPLAY_h

class FlopDisplay
{
public:
    FlopDisplay(int pin_a, int pin_b, int pin_c, int pin_d, int pin_e, int pin_f, int pin_g, int pin_dp );
    FlopDisplay();
    void drawNumber(int number);
    void drawDot(bool isOn);
    void drawCustom(int status_pin_a, int status_pin_b, int status_pin_c, int status_pin_d, int status_pin_e, int status_pin_f, int status_pin_g);
private:
    int pin_a;
    int pin_b;
    int pin_c;
    int pin_d;
    int pin_e;
    int pin_f;
    int pin_g;
    int pin_dp;
};
#endif

