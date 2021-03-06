#ifndef CASE
#define CASE
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include "Fonction.hpp"
/*! \mainpage Framework
 *   Voici un framework adapté aux jeux de plateaux.

 * Pour une utilisation sans interface graphique : "./main"

 * Pour une utilisation avec : "./Nomdujeu" 

 * utilisation :
                - le pavé directionnel pour se déplacer
 *              - la barre d'espace pour recommencer
                - "r" pour le robot stupide   
 */
using namespace std;
/*!
 * \class Case
 * \brief classe abstraite qui représente une case du plateau
 */
class Case{
public :
  /*!
     *  \return  true ssi la case est de type Vide
     */
  virtual bool isEmpty()=0;    
  /*!
     *  \brief fonction de déplacement
     *  \param c : case sur laquelle on va aller
     *  \return true si on a pu bouger, false sinon
     */             
  virtual bool moveTo(shared_ptr<Case> c)=0; 
  /*!
     *  \brief fonction des choses a faire a la fin du tour.
     */
  virtual void endTurn()=0;
  virtual void affiche()=0;
  string getImage();
protected :
  /*! adresse de l'image de la case */ 
  string image;

};
#endif
