#ifndef VIDE
#define VIDE

#include "Case.hpp"

class Vide : public Case{
public :
  Vide(){}
  virtual bool isEmpty();
  virtual bool moveTo(Case &c);
};
#endif
