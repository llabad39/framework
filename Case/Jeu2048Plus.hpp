#ifndef JEU2048PLUS
#define JEU2048PLUS
#include "Jeu2048.hpp"
#include "ChiffreBase3.hpp"
#include "ChiffreNegBase2.hpp"

class Jeu2048Plus :public Jeu2048{
public:
   void place();
  Jeu2048Plus(int taille);
};
#endif
