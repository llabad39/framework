#ifndef CHIFFRE
#define CHIFFRE
#include "Case.hpp"
#include <iostream>
#include <ctime>

using namespace std;
class Chiffre : public Case{
public :
  Chiffre(int v):val(v){};
  Chiffre();
  virtual bool isEmpty();
  virtual bool moveTo(shared_ptr<Case> c);
  int getVal();
  void setVal(int a);
  virtual void affiche();
  virtual void endTurn();
private :
  int val;
};
#endif
