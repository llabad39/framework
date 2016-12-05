#include "Plateau.hpp"
#include <memory>
Plateau::Plateau(int t):taille(t),plateau(t, vector<shared_ptr<Case>>  (t)){}
Plateau::Plateau(Plateau& p):taille(p.taille),plateau(p.taille, vector<shared_ptr<Case>>  (p.taille)){
  for(int i=0;i<p.taille;i++){
    for(int j=0;j<p.taille;j++){
      plateau[i][j]=  p.plateau[i][j];
    }
  }
}

void Plateau::affiche(){
  for(int i=0;i<taille;i++){
    cout << "|" ;
    for(int j =0;j<taille;j++){
      plateau[i][j]->affiche();
      cout << "|";
    }
    cout << "\n" ;
  }
}


void Plateau::operator()(int x,int y,shared_ptr<Case> c){
  plateau[x][y] = c;
}

shared_ptr<Case> Plateau::get(int x,int y){
  return plateau[x][y];
}

shared_ptr<Case> Plateau::operator()(int x,int y){
  return plateau[x][y];
}


int Plateau::getTaille(){
  return taille;
}

void Plateau::swap(int x1, int y1, int x2, int y2){
    shared_ptr<Case> c = plateau[x1][y1];
    plateau[x1][y1]= plateau[x2][y2];
    plateau[x2][y2]= c;
}

