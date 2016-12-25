#ifndef CAISSE
#define CAISSE
#include "Case.hpp"

class Caisse : public Case{
public :
  Caisse(){image="image/caisse.png";};
  virtual bool isEmpty();
  virtual bool moveTo(shared_ptr<Case> c);
  virtual void affiche();
  virtual void endTurn(){};
};
#endif
