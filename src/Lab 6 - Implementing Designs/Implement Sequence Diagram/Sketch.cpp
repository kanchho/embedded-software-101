
/*
 * Authors : Bibek Koirala, Rodrigo Baranda
 * Description : Entry point of the program
 */ 

#include <Arduino.h>
#include <time.h>
#include <stdlib.h>
#include "Thermistor.h"
#include "Led.h"
#include "Math.h"
 
#define THERM_PIN A0   
#define GREEN_LED 5
#define RED_LED 4



void setup(void) {

  pinMode(THERM_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);


  srand(time(NULL));
   
}

void loop(void) {
  volatile float celsius = getTemperature();
  volatile int celsiusModTen = getMod10((int) celsius);
  if ( celsiusModTen < 5 ){
      redLedOn(celsiusModTen);
  }
  else if (celsiusModTen >= 5) {
     redLedBlink(celsiusModTen);
  }

  delay(2000);

  volatile int randNumber = getRandomNumber(celsiusModTen);
  for (int seq=0; seq < randNumber; seq++){
     morseSOS();
  }
}

