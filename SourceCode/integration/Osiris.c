#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 15

void plot_pixel(int x, int y, short int line_color);  // plots one pixel
void clear_screen();                                  // clears whole screen
void draw_line(int x0, int y0, int x1, int y1, short int color);
void swap(int *x, int *y);
void wait_for_vsync();
void draw_initial();
void draw();
void draw_boxes(int x, int y, int color);
int x_box[N];
int y_box[N];
int dx[N];
int dy[N];
short int color[6] = {0xffff, 0xf800, 0x07e0, 0x001f, 0x07ff, 0xf81f};
short int color_box[N];

volatile int pixel_buffer_start;  // global variable
short int Buffer1[240][512];      // 240 rows, 512 (320 + padding) columns
short int Buffer2[240][512];
int board[4][4] = {{1,2,3,0},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int selected;

int main(void) {
  srand(time(NULL));
  volatile int *pixel_ctrl_ptr = (int *)0xFF203020;
  // declare other variables(not shown)
  // initialize location and direction of rectangles(not shown)
  /* set front pixel buffer to Buffer 1 */

  *(pixel_ctrl_ptr + 1) = (int)&Buffer1;  // first store the address in the
                                          // back buffer
  /* now, swap the front/back buffers, to set the front buffer location */
  wait_for_vsync();
  /* initialize a pointer to the pixel buffer, used by drawing functions */
  pixel_buffer_start = *pixel_ctrl_ptr;
  clear_screen();  // pixel_buffer_start points to the pixel buffer
                   /* set back pixel buffer to Buffer 2 */
  *(pixel_ctrl_ptr + 1) = (int)&Buffer2;
  pixel_buffer_start = *(pixel_ctrl_ptr + 1);  // we draw on the back buffer clear_screen(); //
                              // pixel_buffer_start points to the pixel buffer
  wait_for_vsync();  // swap front and back buffers on VGA vertical sync
  pixel_buffer_start = *(pixel_ctrl_ptr + 1);  // new back buffer }
  selected = 5;
  while (1) {
    /* Erase any boxes and lines that were drawn in the last iteration */
    //...
    // code for drawing the boxes and lines (not shown)
    // code for updating the locations of boxes (not shown)

    draw();

    wait_for_vsync();  // swap front and back buffers on VGA vertical sync
    pixel_buffer_start = *(pixel_ctrl_ptr + 1);  // new back buffer }
  }
}
// code for subroutines (not shown)

void plot_pixel(int x, int y, short int line_color) {
  volatile short int *one_pixel_address;

  one_pixel_address = pixel_buffer_start + (y << 10) + (x << 1);

  *one_pixel_address = line_color;
}

void clear_screen() {
  int y, x;

  for (x = 0; x < 320; x++)
    for (y = 0; y < 240; y++) plot_pixel(x, y, 0);
}

void draw_line(int x0, int y0, int x1, int y1, short int color) {
  bool is_steep = abs(y1 - y0) > abs(x1 - x0);
  int y_step;
  if (is_steep) {
    swap(&x0, &y0);
    swap(&x1, &y1);
  }
  if (x0 > x1) {
    swap(&x0, &x1);
    swap(&y0, &y1);
  }

  int deltax = x1 - x0;
  int deltay = abs(y1 - y0);
  int error = -(deltax / 2);
  int y = y0;
  if (y0 < y1) {
    y_step = 1;
  } else {
    y_step = -1;
  }

  for (int i = x0; i < x1; i++) {
    if (is_steep) {
      plot_pixel(y, i, color);
    } else {
      plot_pixel(i, y, color);
    }
    error = error + deltay;
    if (error > 0) {
      y = y + y_step;
      error = error - deltax;
    }
  }
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void wait_for_vsync() {
  volatile int *pixel_ctrl_ptr = (int *)0xFF203020;

  int status;

  *pixel_ctrl_ptr = 1;
  status = *(pixel_ctrl_ptr + 3);
  while ((status & 0x01) != 0) {
    status = *(pixel_ctrl_ptr + 3);
  }
}

void draw() {
  int color =0xf800;
  for(int i = 0;i<4;i++){
    for(int j = 0;j<4;j++){
	if(board[i][j]==0){
        	color = 0;
      }
      draw_boxs_background(i*57,j*57,color);
      draw_each_number(board[i][j],i*57+5,j*57+5);
	  color = 0xf800;
    }
  }


}

void draw_boxs_background(int x, int y, int color) {
  for(int i =0;i<50;i++){
    for(int j=0;j<50;j++){
      plot_pixel(x+i, y+j, color);
    }
  }
}

void draw_I(int starting_point_x, int starting_point_y, int color){
  draw_line(starting_point_x,starting_point_y,starting_point_x,starting_point_y+35,color);
}

void draw_X(int starting_point_x, int starting_point_y, int color){
  draw_line(starting_point_x,starting_point_y,starting_point_x+20,starting_point_y+35,color);
  draw_line(starting_point_x+20,starting_point_y,starting_point_x,starting_point_y+35,color);
}

void draw_V(int starting_point_x, int starting_point_y,int color){
  draw_line(starting_point_x,starting_point_y,starting_point_x+10,starting_point_y+35,color);
  draw_line(starting_point_x+20,starting_point_y,starting_point_x+10,starting_point_y+35,color);
}

void draw_each_number(int number, int starting_point_x, int starting_point_y){
    int color = 0x07e0;
    if(selected == number){
      color = 0x07ff;
    }
    if(number == 1||number == 2|| number ==3){
      for(int i =0;i<number;i++){
        draw_I(starting_point_x+i*5,starting_point_y,color);
      }
    }
    if(number ==4||number == 9){
     draw_I(starting_point_x,starting_point_y,color);
      if(number == 4){
        draw_V(starting_point_x+5,starting_point_y,color);
      }
      if(number == 9){
        draw_X(starting_point_x+5,starting_point_y,color);
      }
    }
    if(number == 5||number == 6|| number ==7||number ==8){
      draw_V(starting_point_x, starting_point_y,color);
      for(int i=1;i<number-5+1;i++){
        draw_I(starting_point_x+26+i*5,starting_point_y,color);
      }
    }
    if(number== 10||number == 11|| number == 12|| number==13||number == 14|| number ==15|| number == 16){
      draw_X(starting_point_x,starting_point_y,color);
      for(int i=1;i<number-10+1;i++){
        if(number!=14&&number!=15&&number!=16){
          draw_I(starting_point_x+26+i*5,starting_point_y,color);
        }
      }
      if(number == 14){
        draw_I(starting_point_x+25,starting_point_y,color);
        draw_V(starting_point_x+30,starting_point_y,color);
      }
      if(number == 15||number == 16){
        draw_V(starting_point_x+23,starting_point_y,color);
        if(number == 16){
          draw_I(starting_point_x+45,starting_point_y,color);
        }
      }
    }
}