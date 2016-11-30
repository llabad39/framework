#include "Chiffre.hpp"

bool Chiffre::isEmpty(){
  return false;
}
Chiffre::Chiffre():aFus(false){
  srand(time(0));
  int al = rand()%5;
  if(al==4)
    val = 4;
  else
    val = 2;
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
void Chiffre::affiche(){
  cout << val ;
}
bool Chiffre::moveTo(Case &c){
  return false;
}

void Chiffre::endTurn(){
  aFus=false;
}
