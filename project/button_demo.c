#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
#include "led.h"
#include "draw_shapes.h"
#include "buzzer.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 


char redraw_screen = 1;
u_int backgroundColor = COLOR_BLUE;
 
void
update_text(void)
{
  const u_char text_row = 20;
  const u_char text_col = 40;
  const u_char char_width = 12;
  static u_char blue = 31, green = 16, red = 31;
  u_int on_color  =                (green << 5) | red;
  u_int off_color = (blue << 11)                | red;
  
 
    //drawChar5x7(text_col, text_row, '1',on_color, backgroundColor);

   //drawChar5x7(text_col + char_width, text_row, '2',on_color, backgroundColor);
    

}



void main(void)
{
  
  configureClocks();
  led_init();
  switch_p2_init();
  lcd_init();
  buzzer_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  

}

    
    
