#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include "Jeu2048.hpp"
using namespace std;
 
int main()
{
  Jeu2048 j(4);
  int n;
  do{
    cout << "1:up 2:down 3:left 4:right 5:quit\n";
    cin >> n;
    switch(n){
    case 1:
      j.up();
      break;
    case 2:
      j.down();
      break;
    case 3:
      j.left();
      break;
    case 4:
      j.right();
      break;
    case 5:
      return -1;
    }
    j.endTurn();
    j.affiche();
  }while(true);
 
}
