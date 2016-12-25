#include "ChiffreBase3.hpp"

ChiffreBase3::ChiffreBase3(){
  int al = Fonction::aleat(0,5);
  if(al==4)
    val = 9;
  else
    val = 3;
  aFus = false;
  image = to_string(val);

}
