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
      int num = Fonction::remove(&l, n); //on pioche le nième int de la liste 
      if(num!=t*t){
	plat(i,j,make_shared<ChiffreTaquin>(num)); //création des chiffres
      }else{
	plat(i,j,make_shared<Vide>()); //création de la case vide
	x=i;
	y=j;
      }
    }
  }
}

bool JeuTaquin::right(){
  int taille = getTaille();
  if(y==(taille-1)){ //si on est deja au bord
    return false;
  }else{
    plat.swap(x, y, x, y+1);
    y++;
  }
  return true;
}

bool JeuTaquin::left(){
  if(y==0){
    return false;
  }else{
    plat.swap(x, y, x, y-1);
    y--;
  }
  return true;
}

bool JeuTaquin::up(){
  if(x==0){
    return false;
  }else{
    plat.swap(x, y, x-1, y);
    x--;
  }
  return true;
}

bool JeuTaquin::down(){
  int taille = getTaille();
  if(x==(taille-1)){
    return false;
  }else{
    plat.swap(x+1, y, x, y);
    x++;
  }
  return true;
}

bool JeuTaquin::win(){  
  int taille = getTaille();
  for(int i=0; i<taille; i++){
    for(int j=0; j<taille; j++){
      if(!plat.get(i,j)->isEmpty()){ //si on est pas sur la case vide, on vérifie que le chiffre est bien au bon endoit
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
