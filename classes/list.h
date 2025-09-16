#ifndef LIST_H
#define LIST_H

#include <iostream>

struct ListItem {
 int Info;
 ListItem* Next;
};

class List {
private:
 ListItem* first;
public:
 List();
 List(const List&);
 const List& operator=(const List&);
 ~List();

 void InsertFirst(const int&);
 bool DeleteFirst();
 const int Top() const;
 void Clone(const List&);
 void Erase();
 void ListPrint() const;
 bool IsEmpty() const;
};

#endif