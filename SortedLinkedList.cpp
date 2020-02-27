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
    /*
      delete predLoc;
      delete postLoc;
      delete currentPos;
      delete head;
    */
    
    ListNode *temp=head;
    ListNode *nextN;
    //currentPos=head;    
    while(temp!=NULL){
        /*
          predLoc=currentPos;
          currentPos=currentPos->next;
          delete predLoc;
        */
        nextN=temp->next;
        delete temp;
        temp=nextN;
        delete nextN;
            }
/*    delete nextN;
    // delete next;
    delete predLoc;
    delete postLoc;
    delete currentPos;
    delete head;
//    delete insert;
*/  
    //cout<<"Deconstructor is called"<<endl;
    
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
  if(searchItem(item)!=-1){
      cout<<"Sorry. You cannot insert the duplicate item"<<endl;
  }  
  else{
      //if the list is not empty
      while(currentPos!=NULL){
          //if inserting to the beginning if it's less than head
          if(head->item.compareTo(insert->item)==GREATER){
              insert->next=head;
              head=insert;
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
  }
  currentPos=head;
//  delete insert;
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
        delete currentPos;//I ADDED THIS NOW
    }
    //if it deleting from beginning
    if(searchItem(item)==0){
        ListNode* temp=head;
        head=head->next; //setting the actual value into the next value
        delete temp;
    }
    //if it is deleting the end
    if(searchItem(item)==length()-1){
        currentPos=head;
        for(int i=0;i<searchItem(item);i++){
            currentPos=currentPos->next;
        }
        //delete currentPos;//NEW
        currentPos=NULL; //setting the last value to NULL because item is deleted 
    }
    size--; //size decreases if we delete an item
    }
    currentPos=head;
}

//returns the index as to where the item is found. If not foudn,returns -1
int SortedLinkedList::searchItem(ItemType item){
  currentPos=head;
  int count=-1;
  while(currentPos!=NULL){
      count=count+1;
      //cout<<"Current Position: "<<currentPos->item.getValue()<<" Count: "<<count<<endl;
      if(currentPos->item.compareTo(item)==EQUAL){
          currentPos=head;
          return count;
      }
      else{
          currentPos=currentPos->next;
      }
  }
  currentPos=head;
  return -1;
  
}

//returns the next item
ItemType SortedLinkedList::GetNextItem(){
    /*  if(currentPos->next==NULL){
        cout<<"The end of the list has reached"<<endl;
        currentPos->next=head;
        
    }
    else if(length()==0){
        ItemType temp;
        temp.initialize(-1);
        return temp;
        //cout<<"List is empty"<<endl;
    }
    else{
        currentPos=currentPos->next;        
    }
    return currentPos->item;
    */
    //ItemType nextPos;
    //nxtNode=currentPos;
    ItemType temp1;
    //ListNode* temp=currentPos;
    if(length()==0){
        cout<<"List Is Empty"<<endl;
        //currentPos=head;
        //cout<<"current" << currentPos->item.getValue();
        return temp1;       
    }
    else{

        if(currentPos==NULL){
            cout<<"The end of the list has reached"<<endl;
            currentPos=head; //reiterates to the beginning
        }
        ListNode* temp=currentPos;
        currentPos=currentPos->next;
         return temp->item;
    }
//     return temp->item;
//OLD CODE
/*
    if(length()==0){
        cout<<"List Is Empty"<<endl;
    }
    else{
        currentPos=currentPos->next;
        if(currentPos==NULL){
            cout<<"The end of the list has reached"<<endl;
            currentPos=head; //reiterates to the beginning
        }
        return currentPos->item;
    }
*/
    
    /*
    cout<<"PRINTING ALL ELEMENTS"<<endl;
    if(currentPos->item.compareTo(head->item)==EQUAL){
        cout<<"current pos is the same as head"<<endl;
    }
    cout<<length()<<endl;
    for(int i=0;i<length();i++){
        cout<<currentPos->item.getValue();
        currentPos=currentPos->next;
    }
    
    if(currentPos==NULL)
    {
        //cout<<"hewrfjekk";
        currentPos=head;
    }
    else
    {
        currentPos=currentPos->next;
        cout<<"Next item: "<<currentPos->item.getValue();
    }
    //currentPos=currentPos;
    //nextPos=currentPos->item;
    
    //return currentPos->item;
    */
}


void SortedLinkedList::ResetList(){
    //size=0;
/*    
    while(currentPos!=NULL){
        predLoc=currentPos;
        currentPos=currentPos->next;
        delete predLoc;
    }
*/
    //currentPos->next=head;
       
    currentPos=NULL;
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
  currentPos=head;
}
void SortedLinkedList::print(){
    //cout<<"This is the print Function"<<endl;
  currentPos=head;
  /*
  cout<<"This is head item: "<<head->item.getValue()<<endl;;
  cout<<"Head next: "<<head->next->item.getValue()<<endl;
  */

  //cout<<"Hasn't gone through the for loop"<<endl;
  //cout<<"Length 5= "<<length()<<endl;
  //cout<<head->item.getValue()<<endl;
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
  currentPos=head;
}
