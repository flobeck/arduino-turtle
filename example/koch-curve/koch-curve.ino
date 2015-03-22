#include <string.h>
#include "U8glib.h"
#include <turtle.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);
Turtle t = Turtle(100, 60, PI);

int init_x = t._x;
int init_y = t._y;
float init_angle = t._angle;

char instruction[] =
  "F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+"
  "F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-"
  "F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-"
  "F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+"
  "F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F";


void setup(void) {}


void draw(void) {
  for (int i = 0; i < 10; i++) {
    t.set(init_x, init_y, init_angle);
    //t.run(koch_curve);

    for (int i = 0; i < strlen(instruction); i++) {
      if (instruction[i] == 'F'){
        t.forward(3);
        u8g.drawLine(t._xold, t._yold, t._x, t._y);
      }
      else if (instruction[i] == '+')
        t.turn(PI / 2);
      else if (instruction[i] == '-')
        t.turn(-PI / 2);
    }

  }
}


void loop(void) {
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );
  delay(5);
}




