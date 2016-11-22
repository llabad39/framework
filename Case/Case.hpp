#ifndef CASE
#define CASE
class Case{
public :
  virtual bool isEmpty()=0;
  virtual bool moveTo(Case &c)=0;
};
#endif
