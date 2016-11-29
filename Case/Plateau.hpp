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
  Case& operator()(int x,int y);
  
private :
  vector<vector<shared_ptr<Case>>> plateau;
  int taille;
};

#endif
