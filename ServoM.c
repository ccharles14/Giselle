/*
 * 	ServoM.c
 *
 *	Author: Renji ZHANG
 *
 *	Version 1.0
 *
 */

#include "Giselle.h"

void InitServo(void) {

    P2SEL |= BIT4;//timer
    P2SEL2 &= ~(BIT4);
    P2DIR |= BIT4;

    //TA1CCTL1 |= OUTMOD_7; // activation mode de sortie TA1.1
    TA1CCTL2 |= OUTMOD_7; //TA1.2
    TA1CTL = TASSEL_2 | MC_1 |ID_0; // source SMCLK pour TimerA , mode comptage Up
    TA1CCR0 = 20000;
    TA1CCR2 = 500;
}

void nord_east(void){
    TA1CCR2 = 1000;
}

void nord(void){
    TA1CCR2 = 1500;
}

void nord_west(void){
    TA1CCR2 = 2000;
}

void west(void){
    TA1CCR2 = 1000;
}
