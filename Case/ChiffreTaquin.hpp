#ifndef CHIFFRETAQUIN
#define CHIFFRETAQUIN
#include "Case.hpp"
#include <iostream>
#include <ctime>

using namespace std;
/*!
 * \class ChiffreTaquin
 * \brief Cases chiffres du taquin ;
 */
//classe différente de la classe Chiffre car les fonctions endTurn et moveTo diffèrent.
class ChiffreTaquin : public Case{
public :
  ChiffreTaquin(int v):val(v){image = to_string(v);};
  virtual bool isEmpty();
  virtual bool moveTo(shared_ptr<Case> c);
  int getVal();
  void setVal(int a);
  virtual void affiche();
  virtual void endTurn();
private :
  int val;
};
#endif
