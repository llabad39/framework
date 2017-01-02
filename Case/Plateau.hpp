#ifndef PLATEAU
#define PLATEAU
#include "Chiffre.hpp"
#include "ChiffreTaquin.hpp"
#include "Vide.hpp"
#include "Caisse.hpp"
#include "Mur.hpp"
#include <iostream>
#include <vector>
using namespace std;

/*!
 * \class Plateau
 * \brief Classe qui contient le tableau de cases
 */
class Plateau{
public :
  Plateau(int taille);
  Plateau(Plateau& p);
  int getTaille();
  void affiche();
 /*!
     *  \brief retourne la case en position x y
     */          
  shared_ptr<Case> operator()(int x,int y);
 /*!
     *  \brief affecte c en position x y
     */          
  void operator()(int x,int y,shared_ptr<Case> c);
  shared_ptr<Case> get(int x,int y);
 /*!
     *  \brief echange la case en position x1, y1 avec celle en position x2, y2
     */          
  void swap(int x1, int y1, int x2, int y2);
 /*!
     *  \brief tourne le plateau d'un quart de tour vers la gauche
     */          
  void rotation();

private :
  /*! Taille du plateau */ 
  int taille;
  vector<vector<shared_ptr<Case>>> plateau;
};

#endif
