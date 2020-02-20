#include <fstream>
#include <iostream>
#include <string>
#include "SortedLinkedList.h"
using namespace std;
int main(int argc, char *argv[]){
  //cout<<"hi"<<endl;
  SortedLinkedList list;
 
    ItemType item;
    item.initialize(4);
    list.insertItem(item);

    //item 3
      ItemType item3;
     item3.initialize(2);
     list.insertItem(item3);
    
    //item 2
    ItemType item2;
    item2.initialize(1);
    list.insertItem(item2);

    
     //item 4
     ItemType item4;
     item4.initialize(5);
     list.insertItem(item4);

      //item 5
     ItemType item5;
     item5.initialize(1);
     list.insertItem(item5);
     
    list.print();    
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

