/*
 * Title: Controlling LEDs with interrupts.
 
 * Authors:  Bibek Koirala, Rodrigo Baranda
 
 * Description: - Green and 'RedGreen': Green and RedGreen blink simultaneously at the interval of 1 sec.
                  Yellow and 'RedYellow': Yellow and RedYellow blink at the interval of half sec.
				
*/

#include <Arduino.h>
#define GREEN 2
#define YELLOW 3
#define RED_GREEN 4
#define RED_YELLOW 6

void controlRedGreen();
void controlRedYellow();

void setup() {
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(RED_GREEN, OUTPUT);
	pinMode(RED_YELLOW, OUTPUT);

	attachInterrupt(digitalPinToInterrupt(GREEN), controlRedGreen, CHANGE );
	attachInterrupt(digitalPinToInterrupt(YELLOW), controlRedYellow, CHANGE );
	
}

void loop() {
	
    static unsigned long previousMillisGreen = 0;
	static unsigned long previousMillisYellow = 0;
	
   	static int ledStateGreen = LOW;
	static int ledStateYellow = LOW;

	unsigned long currentMillisGreen = millis();
	if (currentMillisGreen - previousMillisGreen >= 1000){
		ledStateGreen = !ledStateGreen;
		digitalWrite(GREEN, ledStateGreen);
		previousMillisGreen = currentMillisGreen;
	}

	unsigned long currentMillisYellow = millis();
	if (currentMillisYellow - previousMillisYellow >= 500){
		ledStateYellow = !ledStateYellow;
		digitalWrite(YELLOW, ledStateYellow);
		previousMillisYellow = currentMillisYellow;
	}
}

void controlRedGreen(){
	digitalWrite(RED_GREEN, digitalRead(GREEN));
}


void controlRedYellow(){
	digitalWrite(RED_YELLOW, !digitalRead(YELLOW));
}