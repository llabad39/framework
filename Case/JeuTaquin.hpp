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
  void affiche();
  bool endTurn();
private :
  int x;
  int y;
  // vector<vector<int>> win; //enregistre les positions pour vérifier si on a gagné
};
#endif
