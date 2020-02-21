#include <fstream>
#include <iostream>
#include <string>
#include "SortedLinkedList.h"
using namespace std;
int main(int argc, char *argv[]){
  //cout<<"hi"<<endl;
  SortedLinkedList list;
 
    ItemType item;
    item.initialize(1);
    list.insertItem(item);
    //cout<<"Item 1: "<<list.searchItem(item)<<endl;

    //item 3
      ItemType item3;
     item3.initialize(1);
     list.insertItem(item3);
     //cout<<"Item 2: "<<list.searchItem(item3)<<endl;
    
    //item 2
    ItemType item2;
    item2.initialize(2);
    list.insertItem(item2);
    //cout<<"Item 3: "<<list.searchItem(item2)<<endl;

    
     //item 4
     ItemType item4;
     item4.initialize(3);
     list.insertItem(item4);
     //cout<<"Item 4: "<<list.searchItem(item4)<<endl;

      //item 5
     ItemType item5;
     item5.initialize(4);
     list.insertItem(item5);

     cout<<"Search "<<list.searchItem(item5)<<endl;

    list.print();
    list.reverse();
    list.print();
    list.deleteItem(item5);
    list.print();
    list.deleteItem(item2);
    list.print();
    list.deleteItem(item4);
    list.print();

    //cout<<"Get Next Item: "<<list.GetNextItem().getValue();
    //list.GetNextItem();
    //list.GetNextItem();
    /*    
    string userInput="";
    //SortedLinkedList list;
    ItemType item;
    int input;
    std::fstream fs;
    fs.open(argv[1], std::fstream::in);
    if (fs.is_open()){
        fs >> input;
        while (!fs.eof()){
            item.initialize(input);
            list.insertItem(item);
            fs >> input;
        }
    }
    else{
        std::cout << "Failed to open the input file" << std::endl;
        return 0;
    }
    */
    /*
    cout<<"commands:\n(i) - Insert value\n(d) - Delete value\n(s) - Search value\n(n) - Print next iterator value\n(r) - Reset iterator\n(p) - Print list\n(l) - Print length\n(b) - Reverse\n(q) - Quit program"<<endl;
    while(userInput.compare("q")!=0){
        cout<<"Enter a command: ";
        cin>>userInput;
        if(userInput.compare("i")==0){
            int val;
            cout<<"Enter number: ";
            cin>>val;
            list.insertItem(val);
        }
        if(userInput.compare("d")==0){
        }
           
    }
    */
}

