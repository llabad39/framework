#ifndef JEU2048
#define JEU2048
#include "Jeu.hpp"
#include "ChiffreBase2.hpp"

class Jeu2048 :  public Jeu{
public:
  Jeu2048(int t);
  virtual bool endTurn();
  bool down();
  bool up();
  bool left();
  bool right();
  bool loose(){return false;};
  bool win(){return false;};
  void affiche();
  virtual void place();

};
#endif
