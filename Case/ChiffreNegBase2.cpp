#include "ChiffreNegBase2.hpp"

ChiffreNegBase2::ChiffreNegBase2(){
  int al = Fonction::aleat(0,5);
  if(al==4)
    val = -4;
  else
    val = -2;
  aFus = false;
}
