#include "Chiffre.hpp"

bool Chiffre::isEmpty(){
  return false;//une case chiffre n'est jamais vide
}
Chiffre::Chiffre():aFus(false){  
}

Chiffre::Chiffre(Chiffre& c):val(c.getVal()),aFus(false){
  image = c.image;
}


int Chiffre::getVal(){
  return this->val;//renvoie la valeur du chiffre
}
bool Chiffre::moveTo(shared_ptr<Chiffre> c){
  return this->fusion(c);//regarde si les deux chiffres peuvent fusionner et si oui les fusionnent
}

bool Chiffre::fusion(shared_ptr<Chiffre> c){ 
  if(c->getVal()==this->val && !c->aFus){//si la valeur est la même et que le chiffre n'a pas déjà fusionné
    c->val = val*2;
    c->aFus = true;//on marque que celui ci a déjà fusionné et donc ne pourra pas refusionné
    return true;
  }
  else if(-(c->getVal())==this->val && !c->aFus){//si ce sont des valeurs opposés et que le chiffre n'à pas fusionner
    c->val=0;
     c->aFus = true;
    return true;
  }
  else{
    return false;
  }
}
void Chiffre::affiche(){
  cout << val ;//affiche la valeur du chiffre
}
bool Chiffre::moveTo(shared_ptr<Case> c){
  return true;
}

void Chiffre::endTurn(){
  image = to_string(val);//recupere la nouvelle valeur de l'image
  aFus=false;//reset le marqueur de fusion
  
}


