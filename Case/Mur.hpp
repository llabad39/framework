#ifndef MUR
#define MUR
#include "Case.hpp"

class Mur : public Case{
public :
  Mur(){image = "image/mur.png";};
 /*!
     *  \return  false
     */
  virtual bool isEmpty();
 /*!
     *  \return  true ssi la case est de type Vide
     */
  virtual bool moveTo(shared_ptr<Case> c);
  virtual void affiche();
  virtual void endTurn(){};

};
#endif
