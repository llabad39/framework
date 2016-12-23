#include "Fonction.hpp"
#include <chrono>
int Fonction::aleat(int x,int y){
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine dre(seed);
  uniform_int_distribution<int> uid(x,y);
  return uid(dre);
} 


