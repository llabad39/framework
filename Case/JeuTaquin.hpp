#ifndef JEUTAQUIN
#define JEUTAQUIN
#include "Jeu.hpp"
/*!
 * \class JeuTaquin
 */
using namespace std; 

class JeuTaquin : public Jeu{
public:
  /*!
     *  \brief Initialise le plateau (place les Chiffre) et 
     *  \la position x, y de la case vide
     */        
  JeuTaquin(int t);
  bool down();
  bool up();
  bool left();
  bool right();
  bool loose(){return false;};
  /*!
     *  \return true ssi on a tout les chiffres dans le bon ordre
     */        
  bool win();
  void affiche();
  bool endTurn();
private :
  /*! Abscisse de la case vide*/ 
  int x;
  /*! Ordonnée de la case vide*/ 
  int y;
};
#endif
