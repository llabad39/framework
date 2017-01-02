#include "ChiffreNegBase2.hpp"

ChiffreNegBase2::ChiffreNegBase2(){
  int al = Fonction::aleat(0,5);//donne une valeur -2 où -4 avec une probalité de 1/5 pour les 4
  if(al==4)
    val = -4;
  else
    val = -2;
  aFus = false;
  image = to_string(val);

}
