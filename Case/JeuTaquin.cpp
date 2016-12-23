#include "JeuTaquin.hpp"
#include <list>

JeuTaquin::JeuTaquin(int t) : Jeu(t){
  list<int> l;
  for(int i=1; i<=t*t; i++){
    l.push_back(i);
  }
  for(int i=0; i<t; i++){       
    for(int j=0; j<t; j++){    
      srand(time(0));          
      int n = rand()%(l.size());      
      int num=3;//Fonction::remove(l, n); //on pioche le nième int de la liste 
      if(num!=t*t){
	plat(i,j,make_shared<ChiffreTaquin>(num));
      }else{
	plat(i,j,make_shared<Vide>());
	x=i;
	y=j;
      }
    }
  }
  affiche();
}

bool JeuTaquin::left(){
  int taille = getTaille();
  if(y==(taille-1)){
    return false;
  }else{
    plat.swap(x, y, x, y+1);
    y++;
  }
  return true;
}

bool JeuTaquin::right(){
  if(y==0){
    return false;
  }else{
    plat.swap(x, y, x, y-1);
    y--;
  }
  return true;
}

bool JeuTaquin::down(){
  if(x==0){
    return false;
  }else{
    plat.swap(x, y, x-1, y);
    x--;
  }
  return true;
}

bool JeuTaquin::up(){
  int taille = getTaille();
  if(x==(taille-1)){
    return false;
  }else{
    plat.swap(x+1, y, x, y);
    x++;
  }
  return true;
}

bool JeuTaquin::win(){  // on vérivie que toutes les cases sont bien au bon endroit
  int taille = getTaille();
  for(int i=0; i<taille; i++){
    for(int j=0; j<taille; j++){
      if(!plat.get(i,j)->isEmpty()){
	shared_ptr<ChiffreTaquin> c = static_pointer_cast<ChiffreTaquin>(plat.get(i,j));
	if(!(c->getVal()==i*taille+j+1)){
	  return false;
	}
      }
    }
  }
  return true;
}

void JeuTaquin::affiche(){
  plat.affiche();
}
bool JeuTaquin::endTurn(){
  if(!(win() || loose()))
    return true;
  else
    return false;
}
