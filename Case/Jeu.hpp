#ifndef JEU
#define JEU
#include <iostream>
#include "Plateau.hpp"
#include <cstdlib>

using namespace std;
class Jeu{
public:
  virtual bool down()=0;
  virtual bool up()=0;
  virtual bool left()=0;
  virtual bool right()=0;
  virtual bool win()=0;
  virtual bool loose()=0;
  
protected:
  Plateau plat;
  int taille;
};

#endif
