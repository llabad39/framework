#include "Jeu2048.hpp"
#include "JeuTaquin.hpp"
#include "JeuSokoban.hpp"
//#include "Jeu2048Plus.hpp"
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
  case 3:
    if(taille>4)
      j=new JeuSokoban(taille);
    else{
      cout << "Pour Sokoban, il faut un tableau de taille au moins 5" << endl;
      return -1;
    }
    break;
  case 4:
    //  j=new Jeu2048Plus(taille);
    break;
  default:
    return -1;
  }
  j->play();
  
}
