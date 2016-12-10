#ifndef JEUSOKOBAN
#define JEUSOKOBAN
#include "Jeu.hpp"
#include <list>

using namespace std; 

class JeuSokoban : public Jeu{
public:
  JeuSokoban(int t);
  bool down();
  bool up();
  bool left();
  bool right();
  bool loose(){return false;};
  bool win();
private :
  int x;
  int y;
  list<pair<int,int>> objectifs;
};
#endif
