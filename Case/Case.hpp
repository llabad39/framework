#ifndef CASE
#define CASE
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Case{
public :
  virtual bool isEmpty()=0;
  virtual bool moveTo(shared_ptr<Case> c)=0;
  virtual void endTurn()=0;
  virtual void affiche()=0;
  //~Case(){ cout << "destroy Case \n";};

};
#endif
