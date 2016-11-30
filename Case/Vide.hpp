#ifndef VIDE
#define VIDE

#include "Case.hpp"
#include <iostream>

using namespace std;
class Vide : public Case{
public :
  Vide(){}
  virtual bool isEmpty(){return true;};
  virtual bool moveTo(Case &c){return true;};
  virtual void affiche(){ cout << "V"; } ;
};
#endif
