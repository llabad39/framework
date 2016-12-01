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

Chiffre::Chiffre(Chiffre& c):val(c.getVal()),aFus(false){
  
}
int Chiffre::getVal(){
  return this->val;
}
bool Chiffre::moveTo(shared_ptr<Chiffre> c){
  cout << "in chiffre\n";
  return this->fusion(c);
}

bool Chiffre::fusion(shared_ptr<Chiffre> c){
 
  cout <<c->getVal() << " " << val << "\n";
  if(c->getVal()==this->val){
    this->val = val*2;
    return true;
  }
  else{
    cout << "false" ;
    return false;
  }
}
void Chiffre::affiche(){
  cout << val ;
}
bool Chiffre::moveTo(shared_ptr<Case> c){
  cout << "in case\n";
  return true;
}

void Chiffre::endTurn(){
  aFus=false;
}
