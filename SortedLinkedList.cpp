#include "ListNode.h"
#include "ItemType.h"
#include "SortedLinkedList.h"
ListNode* predLoc=NULL;
ListNode* insert=NULL;
SortedLinkedList::SortedLinkedList(){
  size=0; //intializing the size into 0.
  head=NULL;
  currentPos=NULL;
}
SortedLinkedList::~SortedLinkedList(){
}
//returns the length of the linked list
int SortedLinkedList::length() const{
  return size;
}
void SortedLinkedList::insertItem(ItemType item){
  currentPos=head; //setting to beginning of list
  insert->item=item; //setting the value of the item into new node
  if(size!=0){
    while(currentPos!=NULL){
      predLoc=currentPos;
      currentPos=currentPos->next;
      //if the position has been found; need to sandwich through
      if((predLoc->item.ComparedTo(item)==LESS)&&(currentPos->item.ComparedTo(item)==GREATER)){
	predLoc->next=insert;
	insert->next=currentPos;
      }
      //if it needs to be added in beginning (first sorted is greater than item wanted to add)
      if((predLoc->item.ComparedTo(item)==GREATER)&&(currentPos->item.ComparedTo(item)==GREATER)){
	insert->next=predLoc;
      }
      //adding to end of the list
      if((predLoc->item.ComparedTo(item)==LESS)&&(currentPos==NULL)){
	currentPos->item=item;
      }
    }
  }//if length!=0
  if(size==0){ 
    head->item=item; //setting the first value into head
  }
  /*
    ListNode* location;
    location= new ListNode;
    location->item=item;
    location->next=head;
    head=location;
    size++;
  */
}
void SortedLinkedList::deleteItem(ItemType item){
  size--;
}
//returns the index as to where the item is found. If not foudn,returns -1
int SortedLinkedList::searchItem(ItemType item){
  currentPos=head;
  int count=-1;
  //iterates through the end
  while(currentPos->next!=NULL){
    if(currentPos->item.ComparedTo(item)==EQUAL){
      count++;
      break;
    }
    else{
      count++;
    }
  }
  //if count is -1, then you know it will print "not found"
  return count;
}
ItemType SortedLinkedList::GetNextItem(){
  currentPos=currentPos->next;
  return currentPos->item;
}
void SortedLinkedList::ResetList(){
  size=0;
  currentPos=0;
}
void SortedLinkedList::reverse(){
}
