#include "Caisse.hpp"

bool Caisse::isEmpty(){
  return false;//une caisse n'est jamais vide
}

bool Caisse::moveTo(shared_ptr<Case> c){
  if(c->isEmpty()){
    return true;//une caisse ce déplace seulement sur une case vide
  }
  return false;
}

void Caisse::affiche(){
  cout << "C";
}
