#include "Jeu2048.hpp"

Jeu2048::Jeu2048(int t):Jeu(t),prec(Plateau(t)){
  srand(time(0));
  int x1 = rand()*t;
  int y1 = rand()*t;
  int x2 = rand()*t;
  int y2 = rand()*t;
  for(int i=0;i<t;i++){
    for(int j=0;j<t;j++){
      if((i==x1 && j==y1) || (i==x2 && j==y2))
	plat.plateau[i][j]= make_shared<Chiffre>();
      else 
	plat.plateau[i][j]= make_shared<Vide>();
    }
  }
}
