/*
@author: Bibek Koirala, Rodrigo Baranda.
@description: Implementation of the diagram. Depending on the brightness read by the LDR, different LEDs light up.
*/
#include <Arduino.h>

#define LED1 4
#define LED2 3
#define GREEN_LED 7
#define LDR A0

void turnLedOn(int ledPin);
void turnBothLedOff();
void turnGreenLedOn();
void turnGreenLedOff();

volatile int isGreenLedOn = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(LDR, INPUT);

  attachInterrupt(digitalPinToInterrupt(LED2), turnGreenLedOn, RISING);
}

void loop() {
   volatile int reading = analogRead(LDR);
   volatile int brightness = map(reading, 0, 1023, 0, 255);

   if (brightness <= 85){
     turnLedOn(LED1);
	 turnLedOn(LED2);
   }
   else if (brightness > 85 && brightness <= 170){
     turnLedOn(LED1);
   }
   else{
    turnBothLedOff();
	turnBothLedOff();
   }
   
   if(isGreenLedOn == 1){
     delay(1000);
	 turnGreenLedOff();
   }
   delay(2000);
   turnBothLedOff();
   delay(3000);
   
}


void turnLedOn(int ledPin){
  digitalWrite(ledPin, HIGH);
}

void turnBothLedOff(){
	digitalWrite(LED1, LOW);
	digitalWrite(LED2, LOW);
}

// ISR
void turnGreenLedOn(){
	digitalWrite(GREEN_LED, HIGH);
	isGreenLedOn = 1;
}

void turnGreenLedOff(){
   digitalWrite(GREEN_LED, LOW);
}