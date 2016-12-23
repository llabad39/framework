#include "ChiffreFus.hpp"

bool ChiffreFus::isEmpty(){
  return false;
}
ChiffreFus::ChiffreFus():aFus(false){
  srand(time(0));
  int al = rand()%5;
  if(al==4)
    Chiffre(4);
  else
    Chiffre(2);
  image = "image/"+to_string(val)+".png";
}

ChiffreFus::ChiffreFus(ChiffreFus& c):Chiffre(c.getVal()),aFus(false){
  image = c.image;
}

bool ChiffreFus::moveTo(shared_ptr<ChiffreFus> c){
  return this->fusion(c);
}

bool ChiffreFus::fusion(shared_ptr<ChiffreFus> c){ 
  if(c->getVal()==this->val && !c->aFus){
    c->val = val*2;
    c->image= "image/"+to_string(val)+".png";
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

bool ChiffreFus::moveTo(shared_ptr<Case> c){
  return true;
}

void ChiffreFus::endTurn(){
  cout << image << "\n";
  aFus=false;
}


