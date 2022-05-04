#include "stateMachines.h"
#include "led.h"
#include "draw_shapes.h"
#include "lcdutils.h"
#include "lcddraw.h"
static int variableLimit  = 5;
u_int background=COLOR_BLUE;

// limit to create a variable number of events every second
// starts off at 50 (250 / 5) events per second

void waitState(void){
  clearScreen(background);
  drawChar5x7(2, 140, 'L', (16<<5)|31, background);
  drawChar5x7(38, 140, 'M', (16<<5)|31, background);
  drawChar5x7(70, 140, 'H', (16<<5)|31, background);
  drawChar5x7(115, 140, 'C', (16<<5)|31, background);
}

void movingTower(void)
{
  const int duration=2500;
  static int recCount=0;
  static int recRow=0;

  recCount++;
  if(recCount==250){
    clearScreen(background);
    if(recRow>=160){
      recRow=0;
    }
    recRow+=20;
    draw_rectangle(recRow, 40, 40, 11);
    draw_triangle(recRow-40);
    draw_rectangle(recRow, 20, 5, 6);
    recCount=0;
  }
}

void movingTree(void)
{
  
  static int triCount=0;
  static int triRow=0;

  triCount++;
  if(triCount==150){
    clearScreen(background);
    if(triRow>=160){
      triRow=0;
    }
    triRow+=20;
    draw_back_triangle(triRow);
    draw_back_triangle(triRow+20);
    draw_rectangle(triRow+60, 30, 10, 20);
    triCount=0;
  }
}
void movingSnowman(void)
{
  static int circleCount=0;
  static int circleY=0;

  circleCount++;
  if(circleCount==100){
    clearScreen(background);
    if(circleY>=160){
      circleY=0;
    }
    circleY+=20;
    draw_circle(circleY, 25);
    draw_circle(circleY-35,20);
    draw_circle(circleY-65, 15);
    draw_rectangle(circleY-98, 20, 15, 5);
    draw_rectangle(circleY-82, 5, 20, 5);
    circleCount=0;
  }
}
