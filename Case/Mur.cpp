#include "Mur.hpp"

bool Mur::isEmpty(){
  return false;//un mur n'est jamais vide
}

bool Mur::moveTo(shared_ptr<Case> c){
  return false;//on ne peut bouger un mur

}
void Mur::affiche(){
  cout << "M";
}
