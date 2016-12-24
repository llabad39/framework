#include "Chiffre.hpp"

bool Chiffre::isEmpty(){
  return false;
}
Chiffre::Chiffre():aFus(false){  
}

Chiffre::Chiffre(Chiffre& c):val(c.getVal()),aFus(false){
  image = c.image;
}


int Chiffre::getVal(){
  return this->val;
}
bool Chiffre::moveTo(shared_ptr<Chiffre> c){
  return this->fusion(c);
}

bool Chiffre::fusion(shared_ptr<Chiffre> c){ 
  if(c->getVal()==this->val && !c->aFus){
    c->val = val*2;
    c->aFus = true;
    return true;
  }
  else if(-(c->getVal())==this->val && !c->aFus){
    c->val=0;
     c->aFus = true;
    return true;
  }
  else{
    return false;
  }
}
void Chiffre::affiche(){
  cout << val ;
}
bool Chiffre::moveTo(shared_ptr<Case> c){
  return true;
}

void Chiffre::endTurn(){
  image = "image/"+to_string(val)+".png";
  aFus=false;
  
}


