#ifndef JEU2048
#define JEU2048
#include "Jeu.hpp"


class Jeu2048 : public Jeu{
public:
  Jeu2048(int t);
  bool endTurn();
  bool down();
  bool up();
  bool left();
  bool right();
  bool loose(){return false;};
  bool win(){return false;};
  void affiche();
  void place();
private:
  Plateau prec;
};
#endif
