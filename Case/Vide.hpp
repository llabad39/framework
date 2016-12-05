#ifndef VIDE
#define VIDE

#include "Case.hpp"
#include <iostream>

using namespace std;
class Vide : public Case{
public :
  Vide(){}
  virtual bool isEmpty();
  virtual bool moveTo(shared_ptr<Case> c);
  virtual void affiche(){ cout << " "; } ;
};
#endif
