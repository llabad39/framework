#include "Caisse.hpp"

bool Caisse::isEmpty(){
  return false;
}

bool Caisse::moveTo(shared_ptr<Case> c){
  if(c->isEmpty())return true;
  return false;
}

void Caisse::affiche(){
  cout << "C";
}
