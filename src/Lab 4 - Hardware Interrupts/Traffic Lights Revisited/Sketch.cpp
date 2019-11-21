/*
 * Title: Traffic lights with interrupts
 
 * Authors: Rodrigo Baranda, Bibek Koirala.
 
 * Description: Traffic lights is simulated with LEDs when button is pressed
*/

#include <Arduino.h>

#define RED 10  
#define YELLOW 9  
#define GREEN 8 
#define BUTTON 2

void onlyRed();
void redAndYellow();
void onlyGreen();
void onlyYellow();
void buttonState();

volatile bool isButtonPressed = false;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  pinMode(BUTTON,INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonState, CHANGE);

}

void loop() {
  onlyRed();
 
 if (isButtonPressed == true) {
  redAndYellow();
  delay(2000);
  
  onlyGreen();
  delay(2000);
  
  onlyYellow();
  delay(2000);
 }
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
	
  isButtonPressed = false;
}

void buttonState(){
	isButtonPressed = !isButtonPressed;
	
}