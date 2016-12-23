#ifndef CHIFFREFUS
#define CHIFFREFUS
#include "Chiffre.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
class ChiffreFus : public Chiffre{
public :
  ChiffreFus(int v):val(v),aFus(false){};
  ChiffreFus();
  ChiffreFus(ChiffreFus& c);
  virtual bool isEmpty();
  virtual bool moveTo(shared_ptr<Case> c);
  virtual bool moveTo(shared_ptr<ChiffreFus> c);
  virtual bool fusion(shared_ptr<ChiffreFus> c);
  virtual void endTurn();
protected :
  int val;
  bool aFus;
};
#endif
