#ifndef CASE
#define CASE
class Case{
public :
  virtual bool isEmpty()=0;
  virtual bool moveTo(Case &c)=0;
  virtual void endTurn(){};
  virtual void affiche()=0;
  
};
#endif
