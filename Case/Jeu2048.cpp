#include "Jeu2048.hpp"

Jeu2048::Jeu2048(int t):Jeu(t),prec(t){
  for(int i=0;i<t;i++){
    for(int j=0;j<t;j++){
	plat(i,j,make_shared<Vide>());
    }
  }
  place();
  place();
  plat.affiche();
}

bool Jeu2048::right(){
  bool move=false;
  int taille = getTaille();
  for(int i=0;i<taille;i++){
    for(int j=taille-2;j>=0;j--){
      if(!plat.get(i,j)->isEmpty()){
	int k=j+1;
	while(plat.get(i,k)->isEmpty()){
	  k++;
	  move =true;
	  if(k==taille){
	    break;
	  }
	}
	k--;
	if(k!=taille-1){
	  k++;
	  shared_ptr<Chiffre> c = static_pointer_cast<Chiffre>(plat.get(i,j));
	  shared_ptr<Chiffre> c2 = static_pointer_cast<Chiffre>(plat.get(i,k));
	  if(c->moveTo(c2)){
	    plat(i,j,make_shared<Vide>());
	    plat(i,k ,c2);
	  }
	}
	else if(k!=j){
	  shared_ptr<Case> c= plat.get(i,j);
	  plat(i,j,plat.get(i,k));
	  plat(i,k,c);
	}
      }
    }
    
  }
  return move;
}

bool Jeu2048::down(){
  rotation();
  bool move =right();
  rotation();
  rotation();
  rotation();
  return move;
}

bool Jeu2048::left(){
  rotation();
  rotation();
  bool move =right();
  rotation();
  rotation();
  return move;
}

bool Jeu2048::up(){
  rotation();
  rotation();
  rotation();
  bool move =right();
  rotation();
  return move;
}
void Jeu2048::rotation(){
  Plateau p(plat);
  int t = getTaille();
  for(int i=0;i<t;i++){
    for(int j=0;j<t;j++){
      plat(i,j,p.get(j,t-i-1));
    }
  }
}

void Jeu2048::place(){
  srand(time(0));
  int x,y;
  int t = getTaille();
  do{
    x = rand()%t;
    y = rand()%t;
  }while(plat.get(x,y)->isEmpty());
  plat(x,y,shared_ptr<Chiffre>());
  
}

void Jeu2048::endTurn(){
  int t = getTaille();
  for(int i=0;i<t;i++){
    for(int j=0;j<t;j++){
      plat.get(i,j)->endTurn();
    }
  }
  place();
}
  


