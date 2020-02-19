#include "ItemType.h"
#include  <iostream>

//constructor
ItemType::ItemType(){
}
//Comparison Method
Comparison ItemType::compareTo(ItemType item){
  if(value<item.value)
    return LESS;
  else if(value>item.value)
    return  GREATER;
  else
    return EQUAL;
}
//returns the value of type ItemType
int ItemType::getValue() const{
  return value;
}
//intiializes the value into number
void ItemType::initialize(int num){
    value=num;
} 
