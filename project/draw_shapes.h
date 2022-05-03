#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

/* draws a rectangle */
void draw_rectangle(int rowIn, int heightIn, int widthIn);
/* draws an equaleral triangle by starting at the top with a 
   width of 1 and increasing the width by 1
   for every row */
void draw_triangle(int rowIn);
void draw_back_triangle(int rowIn);
/* draws a circle using bresenham's algorithm */
void draw_circle(int ycoord);

#endif // _DRAW_SHAPES_H_
