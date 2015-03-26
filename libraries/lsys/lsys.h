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
        Lsys(String axiom, String vars, String rules, int r);

        String _axiom;
        String _vars;
        String _rules;
        String _res;
        int _r;


        String getRule(String r, String var);
        String lsysparse(String axiom);
        void parse(int depht);

};


#endif
