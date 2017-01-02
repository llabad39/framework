#ifndef VIDE
#define VIDE

#include "Case.hpp"
#include <iostream>

using namespace std;
/*!
 * \class Vide
 * \brief c'est la case vide, que l'on retrouve dans les 3 jeux.
 */
class Vide : public Case{
public :
  Vide(){image = "image/Vide.png";};
  /*! \return true */ 
  bool isEmpty();
  bool moveTo(shared_ptr<Case> c); 
  void affiche() ;
  void endTurn();

};
#endif
