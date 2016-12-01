#ifndef JEU2048
#define JEU2048
#include "Jeu.hpp"


class Jeu2048 : public Jeu{
public:
  Jeu2048(int t);
  void endTurn(){};
  bool down(){return false;};
  bool up(){return false;};
  bool left(){return false;};
  bool right();
  bool loose(){return false;};
  bool win(){return false;};
  void affiche(){plat.affiche();};
  void rotation();
private:
  Plateau prec;
};
#endif
