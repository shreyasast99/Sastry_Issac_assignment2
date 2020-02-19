#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include "ItemType.h"

struct ListNode{
  ItemType item;
  ListNode *next;
};
#endif
