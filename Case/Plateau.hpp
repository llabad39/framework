#ifndef PLATEAU
#define PLATEAU
#include "Case.hpp"
#include <iostream>
#include <vector>
using namespace std;
class Plateau{
public :
  Plateau(int taille);
  int getTaille();
  void affiche();
  void setCase(x,y);
private :
  vector<vector<Case*>> plateau;
  int taille;
};

#endif
