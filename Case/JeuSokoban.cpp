#include "JeuSokoban.hpp"

JeuSokoban::JeuSokoban(int t) : Jeu(t){
   for(int i=0; i<t-1; i++){
     plat(0,i,make_shared<Mur>());
     plat(i,t-1,make_shared<Mur>());
     plat(t-1,t-1-i,make_shared<Mur>());
     plat(t-1-i,0,make_shared<Mur>());
  }
  list<pair<int,int>> l;
  for(int i=1; i<(t-1); i++){
    for(int j=1; j<(t-1); j++){
      pair<int,int> p (i,j);
      l.push_back(p);
    }
  }
  srand(time(0));
  int n = rand()%t; //nombre de caisses/d'objectifs.
  for(int i=0; i<n; i++){
    int n=rand()%(l.size());
    list<pair<int,int>>::iterator it=l.begin();
    for (int k=0; k != n; k++){
      ++it;
    }
    pair<int,int> p=*it;
    l.erase(it);
    plat(get<0>(p),get<1>(p),make_shared<Caisse>());
  }

  while(!l.empty()){
    pair<int,int> p=l.front();
    plat(get<0>(p),get<1>(p),make_shared<Vide>());
    l.pop_front();
  }

  /* for(int j=0; j<n; j++){
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
    }*/
  plat.affiche();
}

bool JeuSokoban::right(){
  int taille = getTaille();
  if(y==(taille-1)){
    return false;
  }else{

    y++;
  }
  plat.affiche();
  return true;
}

bool JeuSokoban::left(){
  if(y==0){
    return false;
  }else{
    y--;
  }
  plat.affiche();
  return true;
}

bool JeuSokoban::up(){
  if(x==0){
    return false;
  }else{
    x--;
  }
  plat.affiche();
  return true;
}

bool JeuSokoban::down(){
  int taille = getTaille();
  if(x==(taille-1)){
    return false;
  }else{
    x++;
  }
  plat.affiche();
  return true;
}

bool JeuSokoban::win(){
  int taille = getTaille();
  return true;
}
