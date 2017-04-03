/*
 * 	SPI.c
 * 	SPI configuré en mode Slave
 *
 *	Author: Corentin CHARLES
 *
 *	Version 1.0
 *
 */
#include "Giselle.h"

void InitSPI(void)
{
	  P1OUT =  BIT4;                        // P1.4 set, else reset
	  P1REN |= BIT4;                        // P1.4 pullup
	  P1DIR = BIT0;                         // P1.0 output, else input
	  USICTL0 |= USIPE7 + USIPE6 + USIPE5 + USIOE; // Port, SPI slave
	  USICTL1 |= USIIE;                     // Counter interrupt, flag remains set
	  USICTL0 &= ~USIMST;
	  USICTL0 &= ~USISWRST;                 // USI released for operation
	  USISRL = 0x11;                        // init-load data
	  USICNT = 8;                           // init-load counter
}

unsigned char SPIdata(void)
{
	unsigned char reception = 0xff;

	USICNT = 8;

	return reception;
}
