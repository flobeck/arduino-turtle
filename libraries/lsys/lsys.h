#ifndef Lsys_h
#define Lsys_h
/*
  FILE: Lsys.h
*/

#include <string.h>

#if ARDUINO >= 100
        #include "Arduino.h"
#else
        #include "WProgram.h"
#endif


class Lsys
{
public:
        Lsys(String axiom, String left, String right[], int rules);

        String _axiom;
        String _left;
        String _right[];
        String _res;
        int _rules;


        String lsysparse(String axiom);
        void generate(int depht);

};


#endif
