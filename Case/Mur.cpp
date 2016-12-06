#include "Mur.hpp"

bool Mur::isEmpty(){
  return false;
}

bool Mur::moveTo(shared_ptr<Case> c){
  if(c->isEmpty())
    return true;
  else return false;
}
void Mur::affiche(){
  cout << "M";
}
