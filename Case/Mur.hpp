#ifndef MUR
#define MUR
#include "Case.hpp"

class Mur : public Case{
public :
  Mur(){image = "image/mur.png";};
  virtual bool isEmpty();
  virtual bool moveTo(shared_ptr<Case> c);
  virtual void affiche();
  virtual void endTurn(){};

};
#endif
