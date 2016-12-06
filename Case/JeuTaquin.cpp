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
      list<int>::iterator it=l.begin();
      for (int k=0; k != n; k++){
	++it;
      }
      int num=*it;
      l.erase(it);
      if(num!=t*t){
	plat(i,j,make_shared<ChiffreTaquin>(num));
      }else{
	plat(i,j,make_shared<Vide>());
	x=i;
	y=j;
      }
    }
  }
  plat.affiche();
}

bool JeuTaquin::right(){
  int taille = getTaille();
  if(y==(taille-1)){
    return false;
  }else{
    //shared_ptr<ChiffreTaquin> c = static_pointer_cast<ChiffreTaquin>(plat.get(x,y+1));
    //plat(x,y+1,make_shared<Vide>());
    //plat(x,y ,c);
    plat.swap(x, y, x, y+1);
    y++;

  }
  plat.affiche();
  return true;
}

bool JeuTaquin::left(){
  if(y==0){
    return false;
  }else{
    plat.swap(x, y, x, y-1);
    y--;
  }
  plat.affiche();
  return true;
}

bool JeuTaquin::up(){
  if(x==0){
    return false;
  }else{
    plat.swap(x, y, x-1, y);
    x--;
  }
  plat.affiche();
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
  plat.affiche();
  return true;
}

bool JeuTaquin::win(){
  int taille = getTaille();
  for(int i=0; i<taille; i++){
    for(int j=0; j<taille; j++){
      if(!plat.get(i,j)==i*taille+j+1 && !(i==taille && j==taille)){
	return false;
      }
    }
  }
  return true;
}
