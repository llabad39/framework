#include "ChiffreBase3.hpp"

ChiffreBase3::ChiffreBase3(){
  srand(time(0));
  int al = rand()%5;
  if(al==4)
    val = 9;
  else
    val = 3;
  aFus = false;
}
