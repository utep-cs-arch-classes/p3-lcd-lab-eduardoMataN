#include "stateMachines.h"
#include "led.h"
#include "draw_shapes.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "libTimer.h"
static int variableLimit  = 5;
u_int background=COLOR_BLUE;

static char timesPlayed=0;

// limit to create a variable number of events every second
// starts off at 50 (250 / 5) events per second

void waitState(void){
  clearScreen(background);
  char toDisplay[]="Choose a speed.";
  char toDisplay2[]="C for Credits.";
  drawString5x7(10, 70, toDisplay, (16<<5)|31, background);
  drawString5x7(10, 80, toDisplay2, (16<<5)|31, background);
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
  timesPlayed++;

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
  timesPlayed++;

  triCount++;
  if(triCount==100){
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
  timesPlayed++;

  circleCount++;
  if(circleCount==50){
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

void displayCredits(void){
 
  static int credCount=0;
  static int rowCred=140;
  credCount++;
  
  char message1[]="Graphics by: Eduardo M.";
  char message2[]="Music By: Eduardo M.";
  char message3[]="Script By: Eduardo M.";
  char message4[]="Class: Computer Arch.";
  char message5[]="Professor: David P.";
  char message6[]="TA: Briana C.";
  char message7[]="IA: Nathan G.";
  
  if(credCount==250){
    clearScreen(background);
    drawString5x7(5, rowCred, message1,(16<<5)|31, background);
    drawString5x7(5, rowCred+10, message2, (16<<5)|31, background);
    drawString5x7(5, rowCred+20, message3, (16<<5)|31, background);
    drawString5x7(5, rowCred+30, message4, (16<<5)|31, background);
    drawString5x7(5, rowCred+40, message5, (16<<5)|31, background);
    drawString5x7(5, rowCred+50, message6, (16<<5)|31, background);
    drawString5x7(5, rowCred+60, message7, (16<<5)|31, background);
    rowCred-=5;
    if(rowCred==-80){
      turn=5;
    }
    credCount=0;
   
  }
}
