#ifndef JEU2048
#define JEU2048
#include "Jeu.hpp"
#include "ChiffreBase2.hpp"

class Jeu2048 :  public Jeu{
public:
  Jeu2048(int t);
/*!
     *  \brief on ajoute un chiffre
     */      
  virtual bool endTurn();
  bool down();
  bool up();
  bool left();
  bool right();
/*!
     *  \brief on regarde si on peut encore bouger
     */      
  bool loose();
/*!
     *  \brief on regarde si le plus grand chiffre est 2048
     */     
  bool win();
 /*!
     *  \brief Permet de sovoir si on peut bouger verticalement (fonction utilisée uniquement dans loose)
     */      
  bool canVert();
/*!
     *  \brief Permet de sovoir si on peut bouger horizontalement (fonction utilisée uniquement dans loose)
     */      
  bool canHor();
  void affiche();
/*!
     *  \brief place une case (utilisé dans endturn et les constructeurs)
     */      
  virtual void place();
  
protected:
/*! le plus grand chiffre que l'on a obtenu (utilisé dans la fonction win)  
     */      
  int highestFus;

};
#endif
