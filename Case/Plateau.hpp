#ifndef PLATEAU
#define PLATEAU
#include "Chiffre.hpp"
#include "Vide.hpp"
#include <iostream>
#include <vector>
using namespace std;
class Plateau{
public :
  Plateau(int taille);
  int getTaille();
  void affiche();
  Case& operator()(int x,int y);
  void operator()(int x,int y,Chiffre *c);
  vector<vector<shared_ptr<Case>>> plateau;
  
private :
  int taille;
};

#endif
