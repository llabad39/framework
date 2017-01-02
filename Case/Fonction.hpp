#ifndef FONCTION
#define FONCTION
#include <random>
#include <list>
#include <utility>
using namespace std;
/*!
 * \class Fonction
 * \brief classe contenant des fonctions utiles indépendantes de la Framework
 */
class Fonction{
public:
 /*!
     *  \brief fonction d'aléatoire
     *  \return un int aléatoire entre x et y.
     */         
 static int aleat(int x,int y);
 /*!
     *  \brief fonction de suppression d'un élément d'une liste
     *  \param l : la liste
     *  \param n : l'indice de l'élément a supprimer
     *  \return l'élément supprimé de la liste.
     */         
  template <class T>
  static T remove(list<T>* l, int n){
    typename list<T>::iterator it=l->begin();
    for (int k=0; k != n; k++){
      ++it;
    }
    T p=*it;
    l->erase(it);
    return p;}
};
#endif
