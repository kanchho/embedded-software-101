/*
 * Authors : Bibek Koirala, Rodrigo Baranda
 * Description : Calculates celsius from resistance measured by thermistor and returns it
 */ 
 

 #include <Arduino.h>
 #include "Thermistor.h"

 #define THERM_PIN A0

 // Look Up table as arrays for mapping ADC to Celsius
 static const int adcList [32] = {250, 275, 300, 325, 350, 375, 400, 425, 450, 475, 500, 525, 550, 575, 600, 625,
 650, 675, 700, 725, 750, 775, 784, 825, 850, 875, 900, 925, 937, 950, 975, 1000};

 static const float celsiusList [32] = { 1.4, 4.0, 6.4, 8.8, 11.1, 13.4, 15.6, 17.8, 20.0,  22.2, 24.4, 26.7,
	 29.0, 31.3, 33.7, 36.1, 38.7, 41.3, 44.1, 47.1, 50.2, 53.7, 55.0, 61.5,
 66.2, 71.5, 77.9, 85.7, 90.3, 96.0, 111.2, 139.5};

 float getTemperature(){
	 volatile float reading = 0.0;
	 float quotient = 0.0;
	 int roundedQuotient = 0;
	 volatile int roundedReading = 0;
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

 int getVoltage() {
	 int reading = analogRead(THERM_PIN);
	 return reading;

 }