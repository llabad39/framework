#ifndef VIDE
#define VIDE

#include "Case.hpp"
#include <iostream>

using namespace std;
class Vide : public Case{
public :
  Vide(){}
  bool isEmpty();
  bool moveTo(shared_ptr<Case> c); 
  void affiche() ;
  void endTurn();
};
#endif
