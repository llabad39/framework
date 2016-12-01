#include "Jeu2048.hpp"

Jeu2048::Jeu2048(int t):Jeu(t),prec(Plateau(t)){
  srand(time(0));
  int x1 = rand()%t;
  int y1 = rand()%t;
  int x2 = rand()%t;
  int y2 = rand()%t;
  for(int i=0;i<t;i++){
    for(int j=0;j<t;j++){
      if((i==x1 && j==y1) || (i==x2 && j==y2)){
	plat(i,j,make_shared<Chiffre>());
      }
      else 
	plat(i,j,make_shared<Vide>());
    }
  }
  plat.affiche();
}

bool Jeu2048::right(){
  bool move=false;
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
	  shared_ptr<Chiffre> c2 = static_pointer_cast<Chiffre>(plat.get(i,j));
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
  


