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

void movingRectangles(void)
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
    draw_rectangle(recRow, 10, 60);
    recCount=0;
  }
}

void movingTriangles(void)
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
    draw_triangle(triRow);
    draw_back_triangle(triRow+20);
    draw_rectangle(triRow+50, 30, 10);
    triCount=0;
  }
}
void movingCircles(void)
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
    draw_circle(circleY);
    circleCount=0;
  }
}
