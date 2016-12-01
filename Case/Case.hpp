#ifndef CASE
#define CASE
#include <iostream>
#include <vector>
using namespace std;

class Case{
public :
  virtual bool isEmpty()=0;
  virtual bool moveTo(shared_ptr<Case> c)=0;
  virtual void endTurn(){};
  virtual void affiche()=0;
  ~Case(){ cout << "destroy Case \n";};

};
#endif
