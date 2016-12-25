#ifndef JEUSOKOBAN
#define JEUSOKOBAN
#include "Jeu.hpp"
#include <list>

class JeuSokoban : public Jeu{
public:
  JeuSokoban(int t);
  bool down();
  bool up();
  bool left();
  bool right();
  bool loose(){return false;};
  bool win();
  bool endTurn();
  void affiche();
  bool isObj(int x,int y);
  bool isPers(int x,int y);
private :
  int x;
  int y;
  list<pair<int,int>> objectifs;
};
#endif
