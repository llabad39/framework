#include "Jeu2048Plus.hpp"

void Jeu2048Plus::place(){
  int x,y;
  int type;
  int t = getTaille();
  srand(time(0));
  type = rand()%10;
  do{
    srand(time(0));
    x = rand()%t;
    y = rand()%t;
  }while(!plat.get(x,y)->isEmpty());
  if(type < 5)
    plat(x,y,make_shared<ChiffreBase2>());
  else if(type <8)
    plat(x,y,make_shared<ChiffreBase3>());
  else
    plat(x,y,make_shared<ChiffreNegBase2>());
  
}

Jeu2048Plus::Jeu2048Plus(int taille):Jeu2048(taille){place();}
