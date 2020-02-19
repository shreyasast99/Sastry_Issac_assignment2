#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <iostream>
const int MAX_ITEM=5 ;
enum Comparison{LESS,EQUAL,GREATER};
class ItemType{
public:
  ItemType();
  Comparison ComparedTo(ItemType item);
  int getValue() const; //returns the value instance variable
  void Initialize(int num) ;
private:
  int value;
};
#endif
