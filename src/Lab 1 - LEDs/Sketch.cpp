/*
 * Title: Traffic Light Simulator
 
 * Authors: Bibek Koirala, Rodrigo Baranda,.
 
 * Description: RED, GREEN and YELLOW LEDs are connected to 3 digital pins of Arduino
                Lights  follow the pattern :
				RED -> RED & YELLOW -> GREEN -> YELLOW -> RED
*/



#include <Arduino.h>

#define RED 10	      //pin number 10
#define YELLOW 9	 //pin number 9
#define GREEN 8	    //pin number 8


void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
}


void onlyRed(){
	digitalWrite(RED, HIGH);
	digitalWrite(YELLOW, LOW);
}

void redAndYellow() {
	digitalWrite(YELLOW, HIGH);  // RED is still HIGH, so both RED and YELLOW light up
}

void onlyGreen (){
	digitalWrite(RED, LOW);
	digitalWrite(YELLOW, LOW);
	digitalWrite(GREEN, HIGH);
	
}

void onlyYellow(){
	digitalWrite(GREEN, LOW);
	digitalWrite(YELLOW, HIGH);
}

void loop() {
  	onlyRed();
	delay(3000);
	
	redAndYellow();
	delay(2000);
	
	onlyGreen();
	delay(3000);
	
	onlyYellow();
    delay(2000);
}


