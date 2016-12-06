#ifndef JEU2048
#define JEU2048
#include "Jeu.hpp"


class Jeu2048 : public Jeu{
public:
  Jeu2048(int t);
  void endTurn();
  bool down();
  bool up();
  bool left();
  bool right();
  bool loose(){return true;};
  bool win(){return true;};
  void affiche(){plat.affiche();};
  void rotation();
  void place();
private:
  Plateau prec;
};
#endif
