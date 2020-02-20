#include "ListNode.h"
#include "ItemType.h"
#include "SortedLinkedList.h"
#include <string>
#include <iostream>
ListNode* predLoc=new ListNode;
//ListNode* insert=new ListNode;
ListNode* postLoc=new ListNode;

using namespace std;
//constructor 
SortedLinkedList::SortedLinkedList(){
  size=0; //intializing the size into 0.
  head=new ListNode;
  currentPos=new ListNode;
}

//deallocates the memory: delete pointer in the main method
SortedLinkedList::~SortedLinkedList(){
}

//returns the length of the linked list
int SortedLinkedList::length() const{
  return size;
}

//inserts item: beginning, middle, or end; and it the list is empty
void SortedLinkedList::insertItem(ItemType item){
    //if the item has been found
    if(searchItem(item)!=-1){
        cout<<"Sorry. You cannot insert the duplicate item"<<endl;
    }

    
    //if the item has not been found (new item    
    else{
      ListNode* insert=new ListNode; 
      currentPos=head; //setting to beginning of list
      insert->item=item; //setting the value of the item into new node
      
      if(size!=0){
	while(currentPos!=NULL){

	  /*
	    predLoc=currentPos;
	    currentPos=currentPos->next;
	  
	  //if the position has been found; need to sandwich through
	  if((predLoc->item.compareTo(item)==LESS)&&(currentPos->item.compareTo(item)==GREATER)){
	    predLoc->next=insert;
	    insert->next=currentPos;
	  }
	  //if it needs to be added in beginning (first sorted is greater than item wanted to add)
	  if((predLoc->item.compareTo(item)==GREATER)&&(currentPos->item.compareTo(item)==GREATER)){
	    insert->next=predLoc;
	    head=insert; 
	  }
	  */
	}//while loop
      
	//once we reach the end of the list
	if((predLoc->item.compareTo(item)==LESS)&&(currentPos==NULL)){
	  currentPos->item=item;
	}
	
	
      }//if length!=0
          
      if(size==0){ 
	head->item=item; //setting the first value into head
      }
      size++; //need to increment value
      
    } //if it is not a duplicate
}

void SortedLinkedList::deleteItem(ItemType item){
    //if it is an empty list
    if(length()==0){
        cout<<"You cannot delete from an empty list"<<endl;
    }
    else if(searchItem(item)==-1){
    cout<<"Item not found"<<endl;
  }
  //for everything else... regular deleting
  else{
    //if deleting from the middle
    if((searchItem(item)!=0)&&(searchItem(item)!=length()-1)){
      currentPos=head;
      predLoc=currentPos;
      int count=searchItem(item); //saves the index in where the item is found
      //takes the item for the predLoc
      for(int i=0;i<count-1;i++){
	predLoc=predLoc->next;
      }
      //taking value we want to remove (current)
      currentPos=predLoc->next;
      //taking the post value so we can connect
      postLoc=currentPos->next;
      predLoc->next=postLoc; //bascially skipping the current pos because we are deleting that
    }
    //if it deleting from beginning
    if(searchItem(item)==0){
      head=head->next; //setting the actual value into the next value
    }
    //if it is deleting the end
    if(searchItem(item)==length()-1){
      currentPos=head;
      for(int i=0;i<searchItem(item);i++){
	currentPos=currentPos->next;
      }
      currentPos=NULL; //setting the last value to NULL because item is deleted 
    }
    size--; //size decreases if we delete an item
  }
}

//returns the index as to where the item is found. If not foudn,returns -1
int SortedLinkedList::searchItem(ItemType item){
  currentPos=head;
  int count=-1;
  //iterates through the end
  if(size!=0){ //in case it is empty
    while(currentPos->next!=NULL){
      if(currentPos->item.compareTo(item)==EQUAL){
	count++;
	break;
      }
      else{
	count++;
      }
    }
  }
  //if count is -1, then you know it will print "not found"
  return count;
}

//returns the next item
ItemType SortedLinkedList::GetNextItem(){
  currentPos=currentPos->next;
  return currentPos->item;
}


void SortedLinkedList::ResetList(){
  size=0;
  head=NULL;
}

//reverses the linked list function 
void SortedLinkedList::reverse(){
  currentPos=head;
  predLoc=NULL;
  postLoc=NULL;
  while(currentPos!=NULL){
    postLoc=currentPos->next;
    currentPos->next=predLoc;
    predLoc=currentPos;
    currentPos=postLoc;
  }
  head=predLoc; //preLoc is the new header
}
void SortedLinkedList::print(){
    currentPos=head;
    for(int i=0; i<length();i++){
      cout<<currentPos->item.getValue();
      cout<<" ";
      currentPos=currentPos->next;
    }
}
