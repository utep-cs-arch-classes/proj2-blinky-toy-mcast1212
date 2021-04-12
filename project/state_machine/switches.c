#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed;

static char
switch_update_interrupt_sense(){
  char p1val= P2IN;
  P2IES |= (p1val & SWITCHES);
  P2IES &= (p1val | ~SWITCHES);
  return p1val;
}

void
switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler(){
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1;
  switch_state_changed = 1;
  led_update();
}
