#ifndef JEU
#define JEU
#include <iostream>
#include "Plateau.hpp"
#include <cstdlib>

using namespace std;
/*!
 * \class Jeu
 * \brief classe abstraite qui représente un jeu
 */
class Jeu{
public:
  Jeu(int t) : plat(t){};
 /*!
     *  \brief fonction de déplacement en bas
     *  \return true si on a pu bouger, false sinon
     */     
  virtual bool down()=0;
 /*!
     *  \brief fonction de déplacement en haut
     *  \return true si on a pu bouger, false sinon
     */     
  virtual bool up()=0;
 /*!
     *  \brief fonction de déplacement a gauche
     *  \return true si on a pu bouger, false sinon
     */     
  virtual bool left()=0;
 /*!
     *  \brief fonction de déplacement a droite
     *  \return true si on a pu bouger, false sinon
     */     
  virtual bool right()=0;
 /*!
     *  \return true si on a gagné, false sinon
     */     
  virtual bool win()=0;
 /*!
     *  \return true si on a perdu, false sinon 
     *  \(fonction qui ne sera pas toujours implémentée,comme dans le taquin
     *  \ ou le sokoban, mais il nous a semblé logique de la mettre tout de 
     *  \même dans la framework ettant donné que l'on peut perdre dans
     *  \ la majorité des jeux)
     */     
  virtual bool loose()=0;
 /*!
     *  \brief fonction des actions a faire a la fin de chaque tour
     */     
  virtual bool endTurn()=0;
  virtual void affiche()=0;
 /*!
     *  \brief lance le jeu
     */     
  void play();
  void robostupide();
  shared_ptr<Case> get(int x,int y);
  int getTaille();
  
protected:
  /*! Le Plateau du jeu*/ 
  Plateau plat;
};

#endif
