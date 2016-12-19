#include "Jeu.hpp"

shared_ptr<Case> Jeu::get(int x,int y){return plat.get(x,y);}
int Jeu::getTaille(){return plat.getTaille();}
void Jeu::robostupide(){
  bool joue=false;
  while(joue){
    int n = Fonction::aleat(0,3);
     switch (n) {
     case 0:{
       right();
       break;
     }
     case 1:{
       left();
       break;
     }
     case 2:{
       up();
       break;
     }
     case 3:{
       down();
       break;
     }
     }
     joue=!(win() || loose());
  }
}

void Jeu::play(){
  int ecrit;
  bool move;
  while(!(win()||loose())){
    cout << "1 : right(), 2: left(), 3:up(),4:down(),5:quit()\n";
    cin >> ecrit;
    switch (ecrit){
    case 1:
      move = right();
      break;
      
    case 2:
      move =left();
      break;
      
    case 3:
      move =up();
      break;
    
    case 4:
      move = down();
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
