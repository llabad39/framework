#include "Jeu.hpp"

shared_ptr<Case> Jeu::get(int x,int y){return plat.get(x,y);}
int Jeu::getTaille(){return plat.getTaille();}
void Jeu::robostupide(){
  bool joue=true;
  while(joue){
     srand(time(0));
     int n = rand()%4; 
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
  while(true){
    cin >> ecrit;
    switch (ecrit){
    case 1:
      right();
      break;
      
    case 2:
      left();
      break;
      
    case 3:
      up();
      break;
    
    case 4:
      down();
      break;
    
    }
    affiche();
  }
}
