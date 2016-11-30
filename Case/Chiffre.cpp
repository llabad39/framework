#include "Chiffre.hpp"

bool Chiffre::isEmpty(){
  return false;
}
void Chiffre::print(){
  cout << val;
}
int Chiffre::getVal(){
  return this->val;
}
bool Chiffre::moveTo(Chiffre &c){
  return this->fusion(c);
}

bool Chiffre::fusion(Chiffre &c){
  if(c.getVal()==this->val){
    this->val = val*2;
    return true;
  }
  else
    return false;
  
}
bool Chiffre::moveTo(Case &c){
  return false;
}
