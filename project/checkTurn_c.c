#include <msp430.h>
#include "libTimer.h"
#include "stateMachines.h"

int checkState(void)
{
  switch(turn){
  case 0:
    return 0;
    break;
  case 1:
    return 1;
    break;
  case 2:
    return 2;
    break;
  case 3:
    return 3;
    break;
  case 4:
    return 4;
    break;
  default:
    return 5;
  }
}
