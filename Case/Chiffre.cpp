#include "Chiffre.hpp"

bool Chiffre::isEmpty(){
  return false;
}

int Chiffre::getVal(){
  return this->val;
}
bool moveTo(Chiffre c){
  if(c.getVal()==this.val)
    return this.fusion(c);
  else
    return false;
}
bool Chiffre::moveTo(Case c){
  return false;
}
