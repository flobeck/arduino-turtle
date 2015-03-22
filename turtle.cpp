#include "turtle.h"
#include <math.h>


Turtle::Turtle(uint8_t x, uint8_t y, float angle) {
  _x = x;
  _y = y;
  _angle = angle;
}

void Turtle::set(uint8_t x, uint8_t y, float angle){
  _x = x;
  _y = y;
  _angle = angle;
}

void Turtle::forward(uint8_t l) {
  _xold = _x; _yold = _y;

  _x = _x + l * cos(_angle);
  _y = _y + l * sin(_angle);

  // todo:
  //(*f)(xold,yold,_x,_y);
}


void Turtle::turn(float angle) {
  _angle += angle;
}


void Turtle::run(char instruction[]) {
  
}


