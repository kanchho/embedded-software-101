/*
 * Authors : Bibek Koirala, Rodrigo Baranda
 * Description : Controls different LEDs depending on the conditional logic in Sketch.cpp
 */ 

 #include <Arduino.h>
 #define YELLOW_LED 7
 #define GREEN_LED 5
 #define RED_LED 4


 void greenLedOn(){
	 digitalWrite(GREEN_LED, HIGH);
 }

 void redLedOn() {
	 digitalWrite(RED_LED, HIGH);
 }


 void yellowLedBlink( int ms){
	 for(int i = 0; i < 5; i++){
		 digitalWrite(YELLOW_LED, HIGH);
		 delay(ms);
		 digitalWrite(YELLOW_LED, LOW);
		 delay(ms);
	 }
 }