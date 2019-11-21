/*
 * Authors : Bibek Koirala, Rodrigo Baranda
 * Description : Calculate modulo-10 of Celsius and generate random number with it set as upper limit
 */ 

#include <stdlib.h>
#include <time.h>

  int getMod10(int celsius){
	return celsius % 10;
  }

  int getRandomNumber(int max){
	int randNumber = rand() % (max + 1); 
	return randNumber;
  }