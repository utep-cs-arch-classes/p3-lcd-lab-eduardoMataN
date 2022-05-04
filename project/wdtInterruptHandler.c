#include <msp430.h>
#include "libTimer.h"
#include "draw_shapes.h"
#include "buzzer.h"
#include "stateMachines.h"
#include "buzzer.h"

int turn=0;

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  int second_limit = 250;
  static int second_count = 0;
  static int count=0;

 
  if(turn==0){
    if(second_count==0){
      waitState();
      buzzer_set_period(1000);
    }
    second_count++;
    if(second_count==150){
      buzzer_set_period(6000);
    }
    if(second_count==250){
      buzzer_set_period(3000);
    }
    if(second_count==380){
      buzzer_set_period(2200);
    }
    if(second_count>600){
      buzzer_set_period(0);
    }
  }
  if(turn==1){
    count++;
    movingTower();
    if(count==3750){
      turn=5;
    }
  }
  if(turn==2){
    count++;
    movingTree();
    if(count==3750){
      turn=5;
    }
  }
  if(turn==3){
    count++;
    movingSnowman();
    if(count==3750){
      turn=5;
    }
  }
  if(turn==4){
    turn=5;
  }
  if(turn==5){
    second_count=0;
    count=0;
    turn=0;
  }
  
} 

