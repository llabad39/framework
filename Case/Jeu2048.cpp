#include "Jeu2048.hpp"

Jeu2048::Jeu2048(int t):Jeu(t), highestFus(0){
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
	if(k!=taille){
	  shared_ptr<Chiffre> c = static_pointer_cast<Chiffre>(plat.get(i,j));
	  shared_ptr<Chiffre> c2 = static_pointer_cast<Chiffre>(plat.get(i,k));
	  if(c->moveTo(c2)){
	    plat(i,j,make_shared<Vide>());
	    int v= c2->getVal();
	    if(v != 0){
	      plat(i,k ,c2);
	      if(v>highestFus)
		highestFus = v;
	    }
	    else
	      plat(i,k,make_shared<Vide>());
	    move=true;
	  }
	  else if(k!=j){
	    k--;
	    plat.swap(i,j,i,k);
	  }
	}
	else if(k!=j){
	  k--;
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


void Jeu2048::place(){
  int x,y;
  int t = getTaille();
  do{
    x = Fonction::aleat(0,t-1);
    y = Fonction::aleat(0,t-1);
  }while(!plat.get(x,y)->isEmpty());
  plat(x,y,make_shared<ChiffreBase2>());
  
}

bool Jeu2048::endTurn(){
  if(!win() && !loose()){
    int t = getTaille();
    for(int i=0;i<t;i++){
      for(int j=0;j<t;j++){
	plat.get(i,j)->endTurn();
      }
    }
    place();
    return true;
  }
  else
    return false;
}
void Jeu2048::affiche(){
  plat.affiche();
}

bool Jeu2048::win(){
  if(highestFus==2048)
    return true;
  else
    return false;
}

bool Jeu2048::canHor(){
  int t=getTaille();
  for(int i=0;i<t;i++){
    for(int j=0;j<t-1;j++){
      if(!(plat.get(i,j)->isEmpty() || plat.get(i,j+1)->isEmpty())){
	shared_ptr<Chiffre> c = static_pointer_cast<Chiffre>(plat.get(i,j));
	shared_ptr<Chiffre> c2 = static_pointer_cast<Chiffre>(plat.get(i,j+1));
	if(c->getVal()== c2->getVal() || c->getVal()== -(c2->getVal()))
	  return true;
      }
      else
	return true;
    }
  }
  return false;
}



bool Jeu2048::canVert(){
  plat.rotation();
  bool m = canHor();
  plat.rotation();
  plat.rotation();
  plat.rotation();
  return m;
}
bool Jeu2048::loose(){
  if(canHor())
    return false;
  else if(canVert())
    return false;
  return true;
}
  


