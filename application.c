/*
 * application.c
 * 
 * A simple example of using cairo with c on the Raspberry Pi
 * 
 * Copyright 2016  rricharz
 * 
 * Replace the code labelled "example" with your own code
 * 
 */


#include <math.h>
#include <stdio.h>

#include "main.h"
#include "application.h"

int counter;             // example

void application_init()
// put any code here to initialize the application
{
	printf("application_init called\n");
	
	counter = 0;         // example
	
}

int application_on_timer_event()
// if TIMER_INTERVAL in application.h is larger than zero, this function
// is called every TIMER-INTERVAL milliseconds
// if the function returns 1, the window is redrawn by calling application_draw
{
	printf("application_on_timer_event called\n");
	
	counter++;           // example
	
	return 1;
}
 
int application_clicked(int button, int x, int y)
// is called if a mouse button is clicked in the window
// button = 1: means left mouse button; button = 3 means right mouse button
// x and y are the coordinates
// if the function returns 1, the window is redrawn by calling application_draw
{
	printf("application_clicked called, button %d, x = %d, y= %d\n", button, x, y);
	
	counter = 0;                      // Example
	
	return 1;
}

void application_quit()
// is called if the main window is called bevore the applcation exits
// put any code here which needs to be called on exit
{
	printf("application quit called\n");
}

void application_draw(cairo_t *cr, int width, int height, int first)
// draw onto the main window using cairo
// width is the actual width of the main window
// height is the actual height of the main window
// first is TRUE if application_draw is called the first time

{	
	printf("application_draw called\n");
	
// start of example

    if (first || (counter == 0)) {
		srand(15);
		
		// draw a large rectangle in black
		cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
		cairo_set_line_width (cr, 6);
		cairo_rectangle (cr, 12, 12, width - 26, height - 26);
		cairo_stroke_preserve(cr);
		
		// fill the interiour of the rectangle in white
		cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
		cairo_fill(cr);
		
		// display text "click to erase"
		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);
		cairo_select_font_face(cr, "Purisa", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
		cairo_set_font_size(cr, 24);
		cairo_move_to(cr, 20, 50);
		cairo_show_text(cr, "click to erase");
		cairo_stroke (cr);
		
	}

	// display counter at random position
	cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    cairo_select_font_face(cr, "Purisa", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size(cr, 24);
	cairo_move_to(cr, (rand() % (width - 80)) + 25, (rand() % (height - 80)) + 50);
	char s[16];
	sprintf(s, "%d", counter);
	cairo_show_text(cr, s);
	
	cairo_stroke (cr);
	
// end of example

}
