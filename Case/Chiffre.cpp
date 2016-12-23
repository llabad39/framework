#include "Chiffre.hpp"
Chiffre::Chiffre(){}
bool Chiffre::isEmpty(){
  return false;
}

bool Chiffre::moveTo(shared_ptr<Case> c){
  return false;
}

int Chiffre::getVal(){
  return this->val;
}

void Chiffre::setVal(int a){
 this->val=a;
}

void Chiffre::affiche(){
  cout << val ;
}

void Chiffre::endTurn(){
}

