#include "ChiffreBase2.hpp"

ChiffreBase2::ChiffreBase2(){
  int al = Fonction::aleat(0,4);
  if(al==4)
    val = 4;
  else
    val = 2;
  aFus = false;
}
