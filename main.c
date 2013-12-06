#include "Sensors.h"

unsigned int leftSensorValue, rightSensorValue;
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
      initializeADC10();
      P1DIR |= BIT0; //Set P1.0 and P1.6 to output
      P1DIR |= BIT6;

      for(;;){
    	  leftSensorValue = getLeftSensorValue();

    	  if(leftSensorValue < 0x200){
    		  P1OUT &= ~BIT0;
    	  }
    	  else{
    		  P1OUT |=BIT0;
    	  }

    	  rightSensorValue = getRightSensorValue();
    	  if(rightSensorValue < 0x200){
    		  P1OUT &= ~BIT6;
    	  }
    	  else{
    		  P1OUT |= BIT6;
    	  }
      }

      return 0;
    }

#pragma vector = ADC10_VECTOR //ADC10 interrupt service routine
__interrupt void ADC10_ISR(void){
	__bic_SR_register_on_exit(CPUOFF);
}
