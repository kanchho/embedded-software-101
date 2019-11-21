/*
 * Authors : Bibek Koirala, Rodrigo Baranda
 * Description :Contains function declarations for Led.cpp
 */ 


#ifndef LED_H
#define LED_H


void redLedOn(int seconds);
void redLedBlink(volatile int times);
void flash(int duration);
void morseSOS();

#endif 