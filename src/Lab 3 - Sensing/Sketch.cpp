/*
 * Title: Room Temperature on 7-Segment Display
 
 * Authors: Rodrigo Baranda, Bibek Koirala.
 
 * Description: Program displays the room temperature measured by NTC thermistor on 7-Segment Display
   Final demo should do : 
			   a) 7-seg blinks 3-E three times
			   b) Delay 2 seconds
			   C) 7-seg shows 1st digit of room temperature
			   d) Delay 2 seconds
			   e) 7-seg shows 2nd digit of room temperature
			   f) Delay 2 seconds
			   g) 7-seg makes three circles clockwise
			   h) Delay 2 secs
			   Repeat.
*/

#include <Arduino.h>

// Pin configurations. A - G are segments of 7-seg-display
#define A 2 
#define B 8 
#define C 6
#define D 5 
#define E 4
#define F 3
#define G 7 
#define THERM_PIN A0  

// "Look Up table" as arrays for mapping ADC to Celsius
 static const int adcList [32] = {250, 275, 300, 325, 350, 375, 400, 425, 450, 475, 500, 525, 550, 575, 600, 625,
                                  650, 675, 700, 725, 750, 775, 784, 825, 850, 875, 900, 925, 937, 950, 975, 1000};
                                  
 static const float celsiusList [32] = { 1.4, 4.0, 6.4, 8.8, 11.1, 13.4, 15.6, 17.8, 20.0,  22.2, 24.4, 26.7,
                                        29.0, 31.3, 33.7, 36.1, 38.7, 41.3, 44.1, 47.1, 50.2, 53.7, 55.0, 61.5,
                                        66.2, 71.5, 77.9, 85.7, 90.3, 96.0, 111.2, 139.5};

/* function declarations */
float detectCelsius();
int binarySearch(int valueToSearch, const int *array, int sizeOfArray);
void showCelsius(int celsius);
int countDigits(int number);
void displayDigit(int digit);

void zero();
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();
void threeAndE();
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
  delay(2000);

  float celsius = detectCelsius();
  showCelsius( (int) celsius);
  delay(2000);

  clockwiseCircle();
  turnAllSegmentsOff();
  delay(2000);
  
}

float detectCelsius(){
  float reading = 0.0;
  float quotient = 0.0;
  int roundedQuotient = 0;
  int roundedReading = 0;
  int index = -1;
  float celsius = 0.0;

  
  reading = analogRead(THERM_PIN);
  quotient = (reading / 25 ) * 1.0 ;       // dividing ADC reading by 25 since lookup table ADC values are multiple of 25.
  roundedQuotient = int (quotient + 0.5);  // Rounding the quotient of float type to nearest integer.
  roundedReading = 25 * roundedQuotient;   // Multiplying the rounded quotient to get the ADC value in lookup table.

  index = binarySearch(roundedReading, adcList, 32 );  // Searching the index of ADC in lookup table to map the corresponding celsius.

  celsius = celsiusList[index];
  return celsius;
}

int binarySearch(int valueToSearch, const int *array, int sizeOfArray) {
    int lower = 0;
    int upper = sizeOfArray; 
    int mid = -1 ;
    
    while (lower + 1 < upper) {
        mid = (lower + upper) / 2;
        if (valueToSearch < array[mid]) {
            upper = mid;
        } else {
            lower = mid;
        }
    }
    if (array[lower] <= valueToSearch) return lower;
    return (int) -1;
}

int countDigits (int number) {
 int count = 0;
 int index = 0;
 int num = number;
 while (num != 0){
    num /= 10;
    count++;
 }
 return count; 
}

void showCelsius(int celsius){
  int digitOne = 0;
  int digitTwo = 0;
  int count = countDigits(celsius);    
   
 int digits[2] = {0, 0};
 int index = 0;

 while (celsius != 0){
      digits[index] = celsius % 10;
      celsius /= 10;
      index++;
   }
   
  if (count == 1){
    digitOne = digits[0];
    displayDigit(digitOne);
  }

  else if (count == 2) {
    digitTwo = digits[0];
    digitOne = digits[1];
    displayDigit(digitOne);
    delay(1000);
    turnAllSegmentsOff();
    delay(2000);
    displayDigit(digitTwo);
    delay(1000);
    turnAllSegmentsOff();
    
    }

   else {
   }   
}


void displayDigit( volatile int digit){
  switch(digit) {
    
      case 0 : zero(); break;
      case 1 : one(); break;
      case 2 : two(); break;
      case 3 : three(); break;
      case 4 : four(); break;
      case 5 : five(); break;
      case 6 : six(); break;
      case 7 : seven(); break;
      case 8 : eight(); break;
      case 9 : nine(); break;

      default : break;
     
    }
  }

void zero () {
   digitalWrite(A,LOW);  
   digitalWrite(B,LOW);
   digitalWrite(C,LOW);
   digitalWrite(D,LOW);
   digitalWrite(E,LOW);
   digitalWrite(F,LOW);
}


void one () {
   digitalWrite(B,LOW);
   digitalWrite(C,LOW);
}

void two () {
   digitalWrite(A,LOW);  
   digitalWrite(B,LOW);
   digitalWrite(D,LOW);
   digitalWrite(E,LOW);
   digitalWrite(G,LOW);
}

void three () {
   digitalWrite(A,LOW);  
   digitalWrite(B,LOW);
   digitalWrite(C,LOW);
   digitalWrite(D,LOW);
   digitalWrite(G,LOW);
}

void four () {
   
   digitalWrite(B,LOW);
   digitalWrite(C,LOW);
   digitalWrite(F,LOW);
   digitalWrite(G,LOW);
}

void five () {
   digitalWrite(A,LOW);  
   digitalWrite(C,LOW);
   digitalWrite(D,LOW);
   digitalWrite(F,LOW);
   digitalWrite(G,LOW);
}

void six () {
   digitalWrite(A,LOW);  
   digitalWrite(C,LOW);
   digitalWrite(D,LOW);
   digitalWrite(E,LOW);
   digitalWrite(F,LOW);
   digitalWrite(G,LOW);
}

void seven () {
   digitalWrite(A,LOW);  
   digitalWrite(B,LOW);
   digitalWrite(C,LOW);
   delay(1000); 
}

void eight () {
   digitalWrite(A,LOW);   
   digitalWrite(B,LOW);
   digitalWrite(C,LOW);
   digitalWrite(D,LOW);
   digitalWrite(E,LOW);
   digitalWrite(F,LOW);
   digitalWrite(G,LOW);
}

void nine () {
   digitalWrite(A,LOW);  
   digitalWrite(B,LOW);
   digitalWrite(C,LOW);
   digitalWrite(D,LOW);
   digitalWrite(F,LOW);
   digitalWrite(G,LOW);
   
   
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
