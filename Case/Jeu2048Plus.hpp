#ifndef JEU2048PLUS
#define JEU2048PLUS
#include "Jeu2048.hpp"
#include "ChiffreBase3.hpp"
#include "ChiffreNegBase2.hpp"

class Jeu2048Plus :public Jeu2048{
public:
/*!
     *  \brief redefinition de la fonction place avec des chiffres base 2, 3 et -2
     */     
   void place();
  Jeu2048Plus(int taille);
};
#endif
