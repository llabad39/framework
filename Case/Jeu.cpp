#include "Jeu.hpp"

shared_ptr<Case> Jeu::get(int x,int y){return plat.get(x,y);}
int Jeu::getTaille(){return plat.getTaille();}
void Jeu::robostupide(){
  bool joue=false;
  while(joue){
    joue = oneMove();
  }
}

bool Jeu::oneMove(){
  if(!(win() || loose())){
    bool play = false;
    while(!play){
      int n = Fonction::aleat(0,3);
      switch (n) {
      case 0:
	play =right();
	break;
      case 1:
	play=left();
	break;
      case 2:
	play=up();
	break;
      case 3:
	play=down();
	break;
      }
    }
    return true;
  }
  else
    return false;
}
void Jeu::play(){
  int ecrit;
  bool move;
  while(!(win()||loose())){
    cout << "6 : right(), 4: left(), 8:up(),2:down(),5:quit()\n";
    cin >> ecrit;
    switch (ecrit){
    case 6:
      move=right();
      break;    
    case 4:
      move=left();
      break;    
    case 8:
     move= up();
      break;    
    case 2:
      move=down();
      break;
    case 5:
      ecrit =-1;
      move = false;
      break;
    default :
      cout << "mauvaise commande\n";
      ecrit = -2;
      break;
    
    }
    cout << move << "\n";
    cout << loose() << "this the looser\n";
    if(ecrit==-1)
      break;
    if(ecrit !=-2 && move)
      endTurn();
    affiche();    
  }
}
