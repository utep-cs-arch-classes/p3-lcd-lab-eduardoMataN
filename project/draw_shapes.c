#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"

void
draw_rectangle(int rowIn, int heightIn, int widthIn, int blueIn)
{
  int height = heightIn;
  int width  = widthIn;
  int row = rowIn, col = screenWidth / 2;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int blue = 16, green = 0, red = 31;
  u_int color = (blue << blueIn) | (green << 5) | red;

  fillRectangle(left_col, row, width, height, color);
}


void
draw_triangle(int rowIn)
{
  int height = 40;
  int row = rowIn, col = screenWidth / 2;

  int step = 0;

  int blue = 16, green = 0, red = 31;

  u_int color = (blue << 11) | (green << 5) | red;

  // draw a n equilateral triangle
  // starts at the top and works down
  // at the first row the width is 1, second 2 and so on
  for (step = 0; step < height; step++) {
    // left side of triangle
    u_char start_col = col - (step / 2);
    // right side of triangle
    u_char end_col   = col + (step / 2);
    u_char width     = end_col - start_col;
    fillRectangle(col - (step / 2), row+step, width, 1, color);
  }
}

void
draw_back_triangle(int rowIn){
  int height = 40;
  int row=rowIn, col = screenWidth / 2;

  int step=0;

  int blue = 0, green = 31, red = 0;

  u_int color = (blue << 11) | (green << 5) | red;

  for (height = 40; height >= step; height--){
    u_char start_col = col - (height / 2);

    u_char end_col = col + (height / 2);
    u_char width = end_col - start_col;
    fillRectangle(col - (height / 2), row+height, width, 1, color);
  }
}
void
drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR)
{
  u_int length = x_end - x_start;
  // set the draw area from the start of the line to the end
  // height is 1 since its a line
  lcd_setArea(x_start, y, x_end, y);
  for (u_int i = 0; i < length; i++) {
    lcd_writeColor(colorBGR);
  }
  
}

void
drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color)
{
  // bottom
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord + y_point, color);
  // top
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord - y_point, color);
  // and the middle two
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord + x_point, color);
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord - x_point, color);
					  
}

void
draw_circle(int ycoord, int rIn)
{
  int x_coord = screenWidth / 2;
  int y_coord = ycoord;
  int r = rIn;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

  u_int color = COLOR_WHITE;

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}
  

