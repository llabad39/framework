#ifndef JEUSOKOBAN
#define JEUSOKOBAN
#include "Jeu.hpp"
#include <list>
/*!
 * \class JeuSokoban
 */
class JeuSokoban : public Jeu{
public:
  /*!
     *  \brief Initialise le plateau (construit des murs tout autour, place des caisses, des objectifs, des murs et le personnage.)
     */   
  JeuSokoban(int t);
  bool down();
  bool up();
  bool left();
  /*!
     *  \brief fonction de déplacement a droite, c'est la seule fonction de 
     *  \déplacement qui est entiérement implémentée, des autres utilisent cette
     *  \fonction et la rotation du plateau affin de rendre le code plus propre.
     */   
  bool right();
  bool loose(){return false;};
  /*!
     *  \return true ssi tout les objectifs ont une caisse (i.e. ils ne sont pas vide).
     */   
  bool win();
  bool endTurn();
 /*!
     *  \brief le affiche de plateau ne convient pas car il faut
     *  \afficher le personnage et les objectifs qui 
     *  \sont contenus dans la classe JeuSokoban
     */     
  void affiche();
  bool isObj(int x,int y);
  bool isPers(int x,int y);
private :
  /*! absisse de la position du personnage */ 
  int x;
  /*! ordonnée de la position du personnage */ 
  int y;
  /*! liste contenant les abscisse/ordonnée des objectifs. */ 
  list<pair<int,int>> objectifs;
};
#endif
