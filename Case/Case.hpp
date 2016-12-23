#ifndef CASE
#define CASE
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include "Fonction.hpp"
using namespace std;

class Case{
public :
  virtual bool isEmpty()=0;                 //renvoie true ssi la case est de type Vide
  virtual bool moveTo(shared_ptr<Case> c)=0; //fonction de déplacement
  virtual void endTurn()=0;                 //fonction des choses a faire a la fin du tour.
  virtual void affiche()=0;
  string getImage();
protected :
  string image;

};
#endif
