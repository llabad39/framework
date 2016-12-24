#ifndef FONCTION
#define FONCTION
#include <random>
#include <list>
#include <utility>
using namespace std;

class Fonction{
public:
 static int aleat(int x,int y);
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
