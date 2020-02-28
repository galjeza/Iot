#ifndef LED_h
#define LED_h

class LED{
    public:     
      void LEDInit(int led, int state);
      void LEDState(int led, int state); 
      void LEDPWM(int led, int PWM);
};
#endif
