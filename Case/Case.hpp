#ifndef CASE
#define CASE
#include <iostream>
using namespace std;

class Case{
public :
  virtual bool isEmpty()=0;
  virtual bool moveTo(Case &c)=0;
  virtual void print()=0;
};
#endif
