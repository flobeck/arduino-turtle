#ifndef Turtle_h
#define Turtle_h
/*


*/

#include <inttypes.h>
#include <math.h>

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


class Turtle
{
public:
  	Turtle(uint8_t x, uint8_t y, float angle);

  	uint8_t _xold;
  	uint8_t _yold;
  	uint8_t _x;
  	uint8_t _y;
  	float _angle;


	void forward(uint8_t l);
	void turn(float angle);
	void set(uint8_t x, uint8_t y, float angle);
	void run(char instruction[]);


};


#endif