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
  head=currentPos;
  //  currentPos=new ListNode;
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
  currentPos=head;
  ListNode *insert=new ListNode;
  insert->item=item;

  
  //checking if there is duplicates
  //cout<<"Search Item: "<<searchItem(item)<<endl;
  /*
  if(searchItem(item)!=-1){
      cout<<"Sorry You cannot have duplicate"<<endl;
   }
 
  else{
  */
      //if the list is not empty
      while(currentPos!=NULL){
          //predLoc=currentPos;
          //if inserting to the beginning if it's less than head
          if(head->item.compareTo(insert->item)==GREATER){
              insert->next=head;
              head=insert;
              //cout<<"current head: "<<head->item.getValue();
              predLoc=currentPos->next;
          }
          else{//used for middle/end insertion(if head<insert)
              currentPos=head;
              while(currentPos->next!=NULL&&currentPos->next->item.compareTo(insert->item)==LESS){
                  currentPos=currentPos->next;
              }
              //end
              if(currentPos->next==NULL){
                  currentPos->next=insert;
                  break;
              }
              
              //middle
              if(currentPos->next->item.compareTo(insert->item)==GREATER){
              predLoc=currentPos;
              postLoc=currentPos->next;
              predLoc->next=insert;
              insert->next=postLoc;
              break;
              }
              
              //insert->next=currentPos->next;
              //currentPos->next=insert;
          }
          currentPos=predLoc;
      }
      
      //if the list is empty
      if(length()==0){
          //cout<<"List was empty before"<<endl;
          head=insert;
          //current=head;
      }
      //head->next=location;
      
      size=size+1;
      //}
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
  while(currentPos!=NULL){
      count=count+1;
      if(currentPos->item.compareTo(item)==EQUAL){
          return count;
      }
      else{
          currentPos=currentPos->next;
      }
  }
  return -1;
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
  cout<<"This is the print Function"<<endl;
  currentPos=head;
  /*
  cout<<"This is head item: "<<head->item.getValue()<<endl;;
  cout<<"Head next: "<<head->next->item.getValue()<<endl;
  */

  cout<<"Hasn't gone through the for loop"<<endl;
  cout<<"Length 5= "<<length()<<endl;
  cout<<head->item.getValue()<<endl;
  for(int i=0;i<length();i++){
    cout<<currentPos->item.getValue()<<" ";
    currentPos=currentPos->next;
  }
  
  /*currentPos=head;
    cout<<"List: "<<endl;
    cout<<"Length: "<<length();
  */
    /*    
    for(int i=0; i<=length();i++){
      if(i!=length()){
	cout<<currentPos->item.getValue();
	cout<<" ";
      }
      else{
	cout<<currentPos->item.getValue();
	cout<<" ";
	currentPos=currentPos->next;
      }
    }
    */
}
