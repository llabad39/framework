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
	  else if(k!=j){
	    k--;
	    plat.swap(i,j,i,k);
	  }
	}
	else if(k!=j){
	  plat.swap(i,j,i,k);
	}
      }
    }
    
  }
  return move;
}

bool Jeu2048::down(){
  plat.rotation();
  bool move =right();
  plat.rotation();
  plat.rotation();
  plat.rotation();
  return move;
}

bool Jeu2048::left(){
  plat.rotation();
  plat.rotation();
  bool move =right();
  plat.rotation();
  plat.rotation();
  return move;
}

bool Jeu2048::up(){
  plat.rotation();
  plat.rotation();
  plat.rotation();
  bool move =right();
  plat.rotation();
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
  int x,y;
  int t = getTaille();
  do{
    srand(time(0));
    x = rand()%t;
    y = rand()%t;
  }while(!plat.get(x,y)->isEmpty());
  plat(x,y,make_shared<Chiffre>());
  
}

bool Jeu2048::endTurn(){
  if(!win() && !loose()){
	int t = getTaille();
	for(int i=0;i<t;i++){
	  for(int j=0;j<t;j++){
	    plat.get(i,j)->endTurn();
	  }
	}
	cout << "sa marche\n";
	place();
	return true;
  }
  else
    cout << "pas du tout";
    return false;
}
void Jeu2048::affiche(){
  plat.affiche();
}
  


