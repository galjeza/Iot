#include "LED.h"
#include "UART.h"
LED cloud_led;
UART esp_uart;

/*
 * Define for LED's
*/
#define LED_RED       16 
#define LED_GREEN     2
#define LED_ORANGE    0
#define NUMBER_OF_LED 3
#define DELAY_LED     100
#define DELAY_UART    500
#define PWM_RANGE     PWMRANGE
int LEDS[] = {LED_RED, LED_ORANGE, LED_GREEN};

/*
    Define for UART
*/
#define BAUD_RATE     9600

/*
   Setup function for inititalization of peripheral hardware.
*/
void setup() {
  esp_uart.UARTInit(BAUD_RATE);
  for (int i = 0; i <= (NUMBER_OF_LED - 1); i++) {
    cloud_led.LEDInit(LEDS[i], OUTPUT);
  }
  esp_uart.UARTTXSS2018();
}
void loop() {
  PWM_LED(3,100);
}
/*
 *  LED se prižigajo ena za drugim, prav tako tudi ugašajo.
*/
void Bar_LED(int dly) {
  for (int i = 0; i <= (NUMBER_OF_LED - 1); i++) {
    delay(dly);
    cloud_led.LEDState(LEDS[i], HIGH);    
  }
  for (int j = (NUMBER_OF_LED - 1); j >= 0; j--) {
    delay(dly);
    cloud_led.LEDState(LEDS[j], LOW);    
  }
}

/*
 * Knightrider efekt
 */

void Knightrider_LED(int dly) {
  for (int i = 0; i <= (NUMBER_OF_LED - 1); i++) {
    delay(dly);
    cloud_led.LEDState(LEDS[i], HIGH);
    delay(dly);
    cloud_led.LEDState(LEDS[i], LOW);
  }
  for (int j = (NUMBER_OF_LED - 1); j >= 0; j--) {
    delay(dly);
    cloud_led.LEDState(LEDS[j], HIGH);
    delay(dly);
    cloud_led.LEDState(LEDS[j], LOW);
  }
}

/*
 * Blink all LED on board "at once"
 */
void Blinking_LED(int dly) {
  for (int i = 0; i <= (NUMBER_OF_LED - 1); i++) {
    cloud_led.LEDState(LEDS[i], HIGH);
  }
  delay(dly);
  for (int j = (NUMBER_OF_LED - 1); j >= 0; j--) {
    cloud_led.LEDState(LEDS[j], LOW);
  }
  delay(dly);
}

/*
 * PWM drive LED
 */
void PWM_LED(int num_of_led, int dly) {
  for (int i = 0; i <= (PWM_RANGE - 1); i++) {
    cloud_led.LEDPWM(LEDS[num_of_led], i);
    delay(dly);
  }  
  for (int j = (PWM_RANGE - 1); j >= 0; j--) {
    cloud_led.LEDPWM(LEDS[num_of_led], j);
    delay(dly);
  }  
}
