#include "Plateau.hpp"
#include <memory>
Plateau::Plateau(int t):plateau(t , vector<shared_ptr<Case>>  (t)),taille(t){
  
  
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

Case& Plateau::operator()(int x,int y){
  return *plateau[x][y];
}


int Plateau::getTaille(){
  return taille;
}
