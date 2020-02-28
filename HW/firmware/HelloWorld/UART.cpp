#include <Arduino.h>
#include "UART.h"
char lorem[] = "Lorem ipsum dolor sit amet, consectetur cras amet.";

char summerschool[] = "SS2020 - Akademija FERI in zimska šola telekomunikacij, IoT naprava in mobilna aplikacija. \n Univerza v Mariboru, Fakulteta za elektrotehniko, računalništvo in informatiko \n" ;

/*
 * Opis:
 * Nastavitev Baudove hitrosti za prenos podatkov prek UART
 * Opis argumentov:
 * (int baud) - Baud rate za UART (default 9600)
 */
void UART::UARTInit(int baud){
	Serial.begin(baud);
}

/*
 * Opis:
 * Izpis Lorem ipsum na UART
 */
void UART::UARTTXLorem(){
	UARTTX(lorem);  
}

/*
 * Opis:
 * Izpis pozdravni napis za poletno šolo na UART
 */
void UART::UARTTXSS2018(){
  UARTTX(summerschool);  
}

/*
 * Opis:
 * Izpis poljubnega teskta v obliki char string [] = ""
 * Opis argumentov:
 * (char* data) - vnos poljubnega teksta
 */
void UART::UARTTX(char* data){
	Serial.println(data);
}

