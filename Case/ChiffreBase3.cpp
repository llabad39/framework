#include "ChiffreBase3.hpp"

ChiffreBase3::ChiffreBase3(){
  int al = Fonction::aleat(0,5);//donne une valeur 3 où 9 avec une probalité de 1/6 pour les 4
  if(al==4)
    val = 9;
  else
    val = 3;
  aFus = false;
  image = to_string(val);

}
