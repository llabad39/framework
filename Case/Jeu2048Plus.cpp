#include "Jeu2048Plus.hpp"

void Jeu2048Plus::place(){
  int x,y;
  int type;
  int t = getTaille();
  type = Fonction::aleat(0,10);//on choisie un chiffre entre 0 et 10
  do{
    x = Fonction::aleat(0,t-1);//on récupère la position x y d'une case vide aléatoirement
    y = Fonction::aleat(0,t-1);
  }while(!plat.get(x,y)->isEmpty());
  if(type < 5)//selon le chiffre obtenue on met soit un chiffre négatif sois base 2 sois paire
    plat(x,y,make_shared<ChiffreBase2>());
  else if(type <8)
    plat(x,y,make_shared<ChiffreBase3>());
  else
    plat(x,y,make_shared<ChiffreNegBase2>());
  
}

Jeu2048Plus::Jeu2048Plus(int taille):Jeu2048(taille){}
