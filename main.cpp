#include <fstream>
#include <iostream>
#include <string>
#include "SortedLinkedList.h"
using namespace std;
int main(int argc, char *argv[]){
    /*
  //cout<<"hi"<<endl;
  SortedLinkedList list;
 
    ItemType item;
    item.initialize(1);
    list.insertItem(item);
    //cout<<"Item 1: "<<list.searchItem(item)<<endl;

    //item 3
      ItemType item3;
     item3.initialize(2);
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

     cout<<"Search "<<list.searchItem(item4)<<endl;
     cout<<"Printing get next item: "<<list.GetNextItem().getValue();
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
    */    
    SortedLinkedList list;
    string userInput="";
    //SortedLinkedList list;
    ItemType item;
    int input;
    int number=0;
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
    
    while(userInput.compare("q")!=0){
        cout<<"commands:\n(i) - Insert value\n(d) - Delete value\n(s) - Search value\n(n) - Print next iterator value\n(r) - Reset iterator\n(p) - Print list\n(l) - Print length\n(b) - Reverse\n(q) - Quit program"<<endl;

        cout<<"Enter a command: ";
        cin>>userInput;
        cout<<endl;
        list.print(); //prints the list
        cout<<endl;
        ItemType temp;
        //insert value
        if(userInput.compare("i")==0){
            cout<<"Enter number: ";
            cin>>number;
            temp.initialize(number);
            cout<<endl;
            list.insertItem(temp);
            list.print();
        }
        else if(userInput.compare("d")==0){
            cout<<"Enter a value to delete: ";
            cin>>number;
            temp.initialize(number);
            cout<<endl;
            list.deleteItem(temp);
            list.print();
        }
        else if(userInput.compare("s")==0){
            cout<<"Enter a value to search: ";
            cin>>number;
            temp.initialize(number);
            cout<<endl;
            if(list.searchItem(temp)!=-1){
                cout<<"Index "<<list.searchItem(temp);
            }
            //item not found
            else{
                cout<<"Item not found.";
            }
        }
        else if(userInput.compare("n")==0){
            ItemType test= list.GetNextItem();
            cout<<endl;
            cout<<test.getValue()<<endl;
        }
        else if(userInput.compare("r")==0){
            list.ResetList();
            cout<<"Iterator reset.";
        }
        else if(userInput.compare("p")==0){
            list.print();
        }
        else if(userInput.compare("l")==0){
            cout<<"List Length is "<<list.length();
        }
        else if(userInput.compare("b")==0){
            cout<<"Before"<<endl;
            list.print();
            cout<<endl;
            list.reverse();
            cout<<"After";
            list.print();
        }
        else if(userInput.compare("q")==0){
            cout<<"Quitting prorgam";
        }
        //invalid command
        else{
            cout<<"Invalid command, try again!";
        }
        cout<<endl;
    }
    //~SortedLinkedList();
   
}

