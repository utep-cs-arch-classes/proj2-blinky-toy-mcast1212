#include <msp430.h>
#include "led.h"

int main(void){
  P1DIR = 0xff;
  for(;;){
    if(P2IN == 0x0E){
      P1OUT = 0x01;
    }
    if(P2IN == 0x0D){
      P1OUT = 0x40;
    }
    if(P2IN = 0x0B){
      P1OUT = 0x41;
    }
    if(P2IN = 0x07){
      P1OUT 0x00;
    }
  }
}
