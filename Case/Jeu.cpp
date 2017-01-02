#include "Jeu.hpp"

shared_ptr<Case> Jeu::get(int x,int y){return plat.get(x,y);}
int Jeu::getTaille(){return plat.getTaille();}
void Jeu::robostupide(){
  bool joue=false;
  while(joue){
    joue = oneMove();//si on peut jouer on fais un mouvement aléatoire
  }
}

bool Jeu::oneMove(){
  if(!(win() || loose())){//si l'on peut jouer
    bool play = false;
    while(!play){//tant qu'un mouvement n'à pas été fais
      int n = Fonction::aleat(0,3);//on prend un  chiffre entre 0 et 3 aléatoirement
      switch (n) {//on choisie un mouvement un aléatoirement
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
  while(!(win()||loose())){//tant qu'on peut jouer
    affiche(); 
    cout << "6 : right(), 4: left(), 8:up(),2:down(),5:quit()\n";
    cin >> ecrit;//récupère le mouvement que veut faire l'utilisateur
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
      break;
    default :
      cout << "mauvaise commande\n";//on effectue rien 
      ecrit = -2;
      break;
    
    }
   
    if(ecrit==-1)
      break;//on sort de la boucle
    if(ecrit !=-2 && move)
      endTurn();   
  }
}
