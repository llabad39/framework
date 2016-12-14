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
  int n = (rand()%((t*t)/20))+1; //nombre de caisses/d'objectifs.
  for(int i=0; i<(2*n+1); i++){ 
    int num=rand()%(l.size());
    list<pair<int,int>>::iterator it=l.begin();
    for (int k=0; k != num; k++){
      ++it;
    }
    pair<int,int> p=*it;
    l.erase(it);
    if(i==(2*n)){         //choix de l'emplacement du personnage
      x=std::get<0>(p);
      y=std::get<1>(p);
      plat(x,y,make_shared<Vide>());
    }else{
      if(i%2==0){        //choix de l'emplacement des Caisses
	plat(std::get<0>(p),std::get<1>(p),make_shared<Caisse>());
      }else{             //choix de l'emplacement des objectifs
	objectifs.push_back(p);
	plat(std::get<0>(p),std::get<1>(p),make_shared<Vide>());
      }
    }
  }
  while(!l.empty()){
    pair<int,int> p=l.front();
    int m = rand()%10;
    if(!m==0){
      plat(std::get<0>(p),std::get<1>(p),make_shared<Vide>());
    }else{
      plat(std::get<0>(p),std::get<1>(p),make_shared<Mur>());
    }
    l.pop_front();
  }
  affiche();
}

bool JeuSokoban::right(){
  int taille = getTaille();
  if(y==(taille-2)){
    return false;
  }else{
    if(plat.get(x,y+1)->isEmpty())
      y++;
    
    else if(plat.get(x,y+1)->moveTo(plat.get(x,y+2))){
      plat.swap(x,y+1,x,y+2);
      y++;
    }
    else{
      return false;
    }
  }
  return true;
}

bool JeuSokoban::down(){
  int t= getTaille();
  plat.rotation();
  int a= x;
  x=t-y-1;
  y=a;
  bool move =right();
  plat.rotation();
  plat.rotation();
  plat.rotation();
  a=y;
  y=t-x-1;
  x=a;
  return move;
}

bool JeuSokoban::left(){
  int t=getTaille();
  plat.rotation();
  plat.rotation();
  x=t-x-1;
  y=t-y-1;
  bool move =right();
  plat.rotation();
  plat.rotation();
  x=t-x-1;
  y=t-y-1;
  return move;
}

bool JeuSokoban::up(){
  int t=getTaille();
  plat.rotation();
  plat.rotation();
  plat.rotation();
  int a=y;
  y=t-x-1;
  x=a;
  bool move =right();
  a= x;
  x=t-y-1;
  y=a;
  plat.rotation();
  return move;
}

bool JeuSokoban::win(){
  for (std::list<pair<int,int>>::iterator i = objectifs.begin(); i != objectifs.end(); ++i) {  
  if(plat.get(std::get<0>(*i),std::get<1>(*i))->isEmpty()){
    return false;
  }
 }
 return true;
}

void JeuSokoban::affiche(){
  int taille = getTaille();
  for(int i=0;i<taille;i++){
    cout << "|" ;
    for(int j =0;j<taille;j++){
      if(!plat.get(i,j)->isEmpty()){
	plat.get(i,j)->affiche();
      }else{
	if(i==x && j==y){
	  cout << "P";
	}else{
	  pair<int,int> p (i,j);
	  if(find(objectifs.begin(), objectifs.end(), p) != objectifs.end()){
	    cout << "O";
	  }else{
	    plat.get(i,j)->affiche();
	  }
	}
      }
      cout << "|";
    }
    cout << "\n" ;
  }
}

bool JeuSokoban::endTurn(){
  if(!(win() || loose()))
    return true;
  else
    return false;
}
