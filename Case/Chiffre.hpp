#ifndef CHIFFRE
#define CHIFFRE
#include "Case.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
/*!
 * \class Chiffre
 * \brief Chiffre capable de fusionner
 */
class Chiffre : public Case{
public :
  Chiffre(int v):val(v),aFus(false){};
  Chiffre(Chiffre& c);
  Chiffre();
  virtual bool isEmpty();
  virtual bool moveTo(shared_ptr<Case> c);
 /*!
     *  \brief surcharge de la methode moveTo
     */         
  bool moveTo(shared_ptr<Chiffre> c);
 /*!
     *  \brief prend un chiffre en argument et fusionne 
     * ssi la valeur est la meme
     *  \return true si on a pu fusionner
     */         
  bool fusion(shared_ptr<Chiffre> c);
  int getVal();
  void setVal(int a);
  virtual void affiche();
 /*!
     *  \brief fonction de déplacement
     *  \param c : case sur laquelle on va aller
     *  \return true si on a pu bouger, false sinon
     */         
  virtual void endTurn();
protected :
  int val;
/*! booléen utilisé pour savoir si le chiffre a déja fusionné 
 * dans le tour.
 */
  bool aFus;
};
#endif
