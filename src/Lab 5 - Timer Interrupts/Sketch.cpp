
/*
 * Authors : Bibek Koirala, Rodrigo Baranda
 * Title : Working with Timer Interrupts
 * Description : Entry point of the program. Program implements sequence diagram
 */ 

#include <Arduino.h>

#include "Thermistor.h"
#include "Led.h"
#include "Math.h"

ISR(TIMER1_COMPA_vect );
 
#define THERM_PIN A0   
#define GREEN_LED 5
#define RED_LED 4
#define YELLOW_LED 7

#define LOAD 0;
#define COMP 15624;


void setup(void) {

  pinMode(THERM_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
   
  cli();
   
  TCCR1A = 0;
  TCCR1B = 0;

  TCCR1B |= (1 << CS12) | (1 << CS10); 

  TCNT1 = LOAD;
  OCR1A = COMP;
  TIMSK1 = ( 1 << OCIE1A);
 
  sei();
}

void loop(void) {
   
  volatile float celsius = getTemperature();

  if ( (int) celsius >= 25 ){
      redLedOn();
  }
  else {
      greenLedOn();
  }

  delay(2000);
  
  volatile int volts = getVoltage();
  int lsb = checkBit(volts);

  if (lsb == 1){
    yellowLedBlink(1000);
  }
  else if (lsb == 0) {
    yellowLedBlink(200);
  }
}


ISR(TIMER1_COMPA_vect){
 TCNT1 = LOAD;
 digitalWrite(RED_LED, LOW);
 digitalWrite(GREEN_LED, LOW);
}
