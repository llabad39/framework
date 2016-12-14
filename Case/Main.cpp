#include "Jeu2048.hpp"
#include "JeuTaquin.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
int main(){
  Jeu *j;
  int taille;
  int jeu;
  
  cout << "entrez votre type de jeu\n";
  cin >> jeu;
  cout << "entrez la taille du plateau\n";
  cin >> taille;
  switch(jeu){
  case 1:
    j= new Jeu2048(taille);
    break;
  case 2:
    j=new JeuTaquin(taille);
    break;
  default:
    return -1;
  }
  j->play();
  
}
