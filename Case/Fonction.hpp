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
  static T remove(list<T> l, int n);
};
#endif
