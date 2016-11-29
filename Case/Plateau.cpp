#include "Plateau.hpp"
#include "Vide.hpp"
#include <memory>
Plateau::Plateau(int t):plateau(t , vector<Case*>  (t)),taille(t){
  for(int i=0;i<t;i++){
    for(int j=0;j<t;j++){
      plateau[i][j] = new Vide();
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
int Plateau::getTaille(){
  return taille;
}
