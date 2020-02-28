#include <Arduino.h>
#include "LED.h"

/*
 * Opis: 
 * Nastavi začetne vrednosti periferije
 * Opis argumentov: 
 * (int led) - Arduino GPIO številka zaporedne LED (glej tabelo na shemi), 
 * (int state) - status periferije (izhod - OUTPUT, vhod - INPUT)
 */
void LED::LEDInit(int led, int state){
	pinMode(led, state);	
}

/*
 * Opis:
 * Prireditev vrednosti na izhodu
 * Opis argumentov:
 * (int led) - Arduino GPIO številka zaporedne LED (glej tabelo na shemi), 
 * (int state) - status izhoda, 1 (HIGH) /0 (LOW) 
 */
void LED::LEDState(int led, int state){
	digitalWrite(led, state);    	
}

/*
 * Opis:
 * Prilagajanje stanja izhoda v vmesno vrednost med 0 in 1
 * Opis argumentov:
 * (int led) - Arduino GPIO številka zaporedne LED (glej tabelo na shemi), 
 * (int PWM) - vrednost PWM števca 0-1023 
 */
void LED::LEDPWM(int led, int PWM){
  analogWrite(led, PWM);     
}


