#ifndef CASE
#define CASE
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
using namespace std;

class Case{
public :
  virtual bool isEmpty()=0;
  virtual bool moveTo(shared_ptr<Case> c)=0;
  virtual void endTurn()=0;
  virtual void affiche()=0;
  virtual string getImage();
  //~Case(){ cout << "destroy Case \n";};
protected :
  string image;

};
#endif
