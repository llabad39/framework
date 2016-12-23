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
  Chiffre(Chiffre& c);
  Chiffre();
  virtual bool isEmpty();
  virtual bool moveTo(shared_ptr<Case> c);
  bool moveTo(shared_ptr<Chiffre> c);
  bool fusion(shared_ptr<Chiffre> c);
  int getVal();
  void setVal(int a);
  virtual void affiche();
  virtual void endTurn();
protected :
  int val;
  bool aFus;
};
#endif
