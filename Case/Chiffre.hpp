#ifndef CHIFFRE
#define CHIFFRE
#include "Case.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
class Chiffre : public Case{
public :
  Chiffre(int v):val(v),aFus(false){};
  Chiffre();
  virtual bool isEmpty();
  virtual bool moveTo(Case &c);
  bool moveTo(Chiffre &c);
  bool fusion(Chiffre &c);
  int getVal();
  void setVal(int a);
  virtual void affiche();
  virtual void endTurn();
private :
  int val;
  bool aFus;
};
#endif
