#ifndef CHIFFRETAQUIN
#define CHIFFRETAQUIN
#include "Case.hpp"
//#include <cstdlib>
#include <iostream>
//#include <ctime>

using namespace std;
class ChiffreTaquin : public Case{
public :
  ChiffreTaquin(int v):val(v){};
  virtual bool isEmpty();
  virtual bool moveTo(Case &c);
  int getVal();
  virtual void setVal(int a);
  virtual void affiche();
private :
  int val;
};
#endif
