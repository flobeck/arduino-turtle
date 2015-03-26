#include "lsys.h"

Lsys::Lsys(String axiom, String vars, String rules, int r) {
  _axiom = axiom;
  _vars  = vars;
  _r = r;
  _rules = rules;
}


String Lsys::getRule(String r, String var){
  int from = r.indexOf(var+":") + 2;
  int to;
  if(r.indexOf(';', from) == -1)
    to = r.length();
  else
    to = r.indexOf(';', from);
  return r.substring(from,to);
}


String Lsys::lsysparse(String axiom) {
  String result = String("");
  int substituted;
  for (int i = 0; i < axiom.length(); i++) {
    for (int r = 0; r < _r; r++) {
      substituted = 0;
      if (axiom.charAt(i) == _vars.charAt(r)) {
        result += getRule(_rules, String(_vars.charAt(r)));
        substituted = 1;
        break;
      }
    }
      if(!substituted)
        result += axiom.charAt(i);
  }
  return result;
}


void Lsys::parse(int depth) {
  for (int d = 0; d < depth; d++) {
    _axiom = lsysparse(_axiom);
  }
  _res = _axiom;

}
