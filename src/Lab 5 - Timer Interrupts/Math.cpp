/*
 * Authors : Bibek Koirala, Rodrigo Baranda
 * Description : Calculates two's complement of parameters of function and returns the least significant bit
 */ 

  int checkBit(int voltage){
	  volatile int voltages = ( ~voltage ) + 1; // two's complement
	  volatile int lsb = voltages & 1; // lsb
	  return lsb;
  }