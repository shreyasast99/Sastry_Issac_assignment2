#include <iostream>
const int  MAX_ITEM = 5 ;
enum  RelationType { LESS, EQUAL, GREATER };
class  ItemType// declares class data type
{
public : //  3 public member functions
    RelationType  ComparedTo ( ItemType )  const;
    void    Print ( )  const;
    void    Initialize ( int  number ) ;
private :// 1 private data member
    int value ;           // could be any different
// type, including a class
} ;
