#ifndef JEUTAQUIN
#define JEUTAQUIN
#include "Jeu.hpp"

using namespace std; 

class JeuTaquin : public Jeu{
public:
  JeuTaquin(int t);
  bool down();
  bool up();
  bool left();
  bool right();
  bool loose(){return false;};
  bool win();
  bool endTurn();
private :
  int x;
  int y;
};
#endif
