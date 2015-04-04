#include <string.h>
#include "U8glib.h"
#include <turtle.h>
#include <lsys.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

// initialize Turtle
int init_x = 100;
int init_y = 60;
float init_angle = PI; 

Turtle t = Turtle(init_x, init_y, init_angle);

// initialize Lindenmayer System
String axiom = "F";
String vars  = "F";
String rules = "F:F+F-F-F+F";  //rules must be in this form

Lsys l = Lsys(axiom, vars, rules, 1);



void setup(void) {
  Serial.begin(9600);
  l.parse(3);
}  

int go = 0;

void draw(void) {
    t.set(init_x, init_y, init_angle);
    
    for (int i = 0; i < go; i++) {
      if (l._res.charAt(i) == 'F') {
        t.forward(3);
        u8g.drawLine(t._xold, t._yold, t._x, t._y);
      }
      else if (l._res.charAt(i) == '+')
        t.turn(PI / 2);
      else if (l._res.charAt(i) == '-')
        t.turn(-PI / 2);
   }

  go = (go + 1) % l._res.length();
}


void loop(void) {
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );
  delay(0);
}




