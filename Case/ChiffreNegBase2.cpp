#include "ChiffreNegBase2.hpp"

ChiffreNegBase2::ChiffreNegBase2(){
  srand(time(0));
  int al = rand()%5;
  if(al==4)
    val = -4;
  else
    val = -2;
  aFus = false;
}
