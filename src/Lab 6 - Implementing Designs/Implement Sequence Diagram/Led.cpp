/*
 * Authors : Bibek Koirala, Rodrigo Baranda
 * Description : Controls different LEDs depending on the conditional logic in Sketch.cpp
 */ 

 #include <Arduino.h>
 #include "Led.h"
 #define GREEN_LED 5
 #define RED_LED 4

 void redLedOn(volatile int seconds) {
     
	 digitalWrite(RED_LED, HIGH);
	 delay(seconds * 1000);
	 digitalWrite(RED_LED, LOW);
 }

 void redLedBlink(volatile int times) {
	int seq = 0;
	for(seq; seq < times; seq++){
 digitalWrite(RED_LED, HIGH);
	 delay(250);
	 digitalWrite(RED_LED, LOW);
	 delay(250);
	}
 }



void flash(int ms){
digitalWrite(GREEN_LED, HIGH);
delay(ms);
digitalWrite(GREEN_LED, LOW);
delay(ms);

}

void morseSOS(){
flash(200); flash(200); flash(200);  // S
delay(300);                          //using  500 - 200 = 300 so that S and O don't light up simultaneously

flash(500); flash(500); flash(500);  // O

flash(200); flash(200); flash(200); // S

delay(1000);
}