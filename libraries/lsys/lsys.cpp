#include "lsys.h"

Lsys::Lsys(String axiom, String left, String right[], int rules) {
  _axiom = axiom;
  _left  = left;
  _rules = rules;
  memcpy(_right, right, rules * sizeof(String));
}


String Lsys::lsysparse(String axiom) {
  String result = String("");
  for (int i = 0; i < axiom.length(); i++) {
    for (int r = 0; r < _rules; r++) {
      if (axiom.charAt(i) == _left.charAt(r)) {
        result += _right[r];
      }
      else {
        result += axiom.charAt(i);
      }
    }
  }
  return result;
}


void Lsys::generate(int depth) {
  for (int d = 0; d < depth; d++) {
    _axiom = lsysparse(_axiom);
  }
  _res = _axiom;


}
