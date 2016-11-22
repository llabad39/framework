#ifndef CHIFFRE
#define CHIFFRE
#include "Case.hpp"

class Chiffre : public Case{
public :
  Chiffre(int v):val(v),aFus(false){};
  virtual bool isEmpty();
  virtual bool moveTo(Case &c);
  bool moveTo(Chiffre &c);
  bool fusion(Chiffre &c);
  int getVal();
  void setVal(int a);
private :
  int val;
  bool aFus;
};
#endif
