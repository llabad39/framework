#ifndef PLATEAU
#define PLATEAU
#include "Chiffre.hpp"
#include "ChiffreTaquin.hpp"
#include "Vide.hpp"
#include <iostream>
#include <vector>
using namespace std;
class Plateau{
public :
  Plateau(int taille);
  Plateau(Plateau& p);
  int getTaille();
  void affiche();
  shared_ptr<Case> operator()(int x,int y);
  void operator()(int x,int y,shared_ptr<Case> c);
  shared_ptr<Case> get(int x,int y);
private :
  int taille;
  vector<vector<shared_ptr<Case>>> plateau;
};

#endif
