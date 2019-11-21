/*
 * Title: Interfacing 7-Segment Display with Arduino Uno
 
 * Authors: Bibek Koirala, Rodrigo Baranda,
 
 * Description: Program   a) displays 3 and E (x3)
                          b) displays circle in counter-clockwise direction (x3)
						  c) turns all LEDs on and off one by one thrice (x3)
						  d) displays circle in clockwise direction (x3)
*/



#include <Arduino.h>

// Pins of 7-seg-display's each segment connected to arduino pins
#define A 2	
#define B 8	
#define C 6
#define D 5	
#define E 4
#define F 3
#define G 7	


void threeAndE();
void counterClockwiseCircle();
void onAndOff();
void clockwiseCircle();
void turnAllSegmentsOff ();
	
void setup() {
	
  pinMode(A, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
	threeAndE();
	turnAllSegmentsOff();
	counterClockwiseCircle();
	onAndOff();
	clockwiseCircle();
	
}


void threeAndE () {
	for(int i = 0; i < 3 ; i++) {
	  digitalWrite(F,HIGH);  // Turning LEDS which aren't common in the sequence off.
	  digitalWrite(E,HIGH);
	
	 digitalWrite(A,LOW);   // In common-anode, LOW is ON
	 digitalWrite(B,LOW);
	 digitalWrite(C,LOW);
	 digitalWrite(D,LOW);
	 digitalWrite(G,LOW);
	
	 delay(1000);
	
	 digitalWrite(B,HIGH);   // Turning LEDS which aren't common in the sequence off.
	 digitalWrite(C,HIGH);
	
	 digitalWrite(F,LOW);
	 digitalWrite(E,LOW);
	
	 delay(1000);
   
  }
}

	
	
void counterClockwiseCircle(){
	for(int i = 0; i < 3 ; i++) {
	 digitalWrite(A,LOW);
	 delay(250); 
	 digitalWrite(F,LOW);
	 delay(250); 
	 digitalWrite(E,LOW);
	 delay(250); 
	 digitalWrite(D,LOW);
	 delay(250); 
	 digitalWrite(C,LOW);
	 delay(250); 
	  digitalWrite(B,LOW);
	 delay(250);
	 
	 turnAllSegmentsOff();
	 delay(500);
	}
}

void onAndOff(){
	int pinsInClockwiseSequence[7] = {A, B, C, D , E, F, G}; 
		
	for(int i = 0; i < 3 ; i++) {
		
		 for (int j = 0; j < 7 ; j++){
		     digitalWrite(pinsInClockwiseSequence[j], LOW); 
		    }
			
	     delay(500);
		
	     for (int j = 0; j < 7 ; j++){
			   digitalWrite(pinsInClockwiseSequence[j], HIGH);
			   delay(250);
		 }
	 }
 }

void clockwiseCircle(){
	for(int i = 0; i < 3 ; i++) {
	 digitalWrite(A,LOW);
	 delay(250); 
	 digitalWrite(B,LOW);
	 delay(250); 
	 digitalWrite(C,LOW);
	 delay(250); 
	 digitalWrite(D,LOW);
	 delay(250); 
	 digitalWrite(E,LOW);
	 delay(250); 
	  digitalWrite(F,LOW);
	 delay(250);
	 
	 turnAllSegmentsOff();
	 delay(500);
	}
}
	
void turnAllSegmentsOff () {
	
	 digitalWrite(A,HIGH);   
	 digitalWrite(B,HIGH);
	 digitalWrite(C,HIGH);
	 digitalWrite(D,HIGH);
	 digitalWrite(E,HIGH);  
	 digitalWrite(F,HIGH);
	 digitalWrite(G,HIGH); 
}