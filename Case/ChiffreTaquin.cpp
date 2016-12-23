#include "ChiffreTaquin.hpp"
bool ChiffreTaquin::isEmpty(){
  return false;
}

bool ChiffreTaquin::moveTo(shared_ptr<Case> c){
  return false;
}

int ChiffreTaquin::getVal(){
  return this->val;
}

void ChiffreTaquin::setVal(int a){
 this->val=a;
}

void ChiffreTaquin::affiche(){
  cout << val ;
}

void ChiffreTaquin::endTurn(){
}

