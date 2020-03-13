#include <msp430.h>
#include "buttons.h"
#include "stateMachines.h"
#include "led.h"
#include "catch_red.h"


/* Switch on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2() {
  if (P2IFG & BUTTONS) {
    P2IFG &= ~BUTTONS;
    if (game_num == 1) {
      game_one_interrupt_handler();
    }
    else if (game_num == 2) {
      frequency_recovery();
    }
    else if (game_num == 3) {
      light_speed = game_three_interrupt_handler(light_speed);
    }
    else {
      game_four_interrupt_handler();
    }
    buttons_update_interrupt_sense();
  }
}