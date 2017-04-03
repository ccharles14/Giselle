/*
 * 	Georges.h
 *
 *	Author: Corentin CHARLES & Renji ZHANG
 *
 *	Version 1.0
 *	Blabla
 */


#include "Giselle.h"



unsigned char valeur = 0xff;

int main(void)
{
	  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer

	  InitSPI();

	  _BIS_SR(LPM0_bits + GIE);             // Enter LPM0 w/ interrupt

  while(1);


}

// USI interrupt service routine
#pragma vector=USI_VECTOR
__interrupt void universal_serial_interface(void)
{
	valeur = SPIdata();
}
