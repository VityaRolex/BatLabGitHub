#include "list.h"

void List::InsertFirst(const int& Ainfo){
 ListItem* p = new ListItem;
 p->Info = Ainfo;
 p->Next = first;
 first = p;
}
void List::ListPrint() const {
 ListItem* P = first;
 if (P == nullptr) {
  std::cout << "The list is empty" << std::endl;
 }
 std::cout << "list contents:" << std::endl;
 while (P != nullptr) {
  std::cout << P->Info << std::endl;
  P = P->Next;
 }
}
const List& List::operator=(const List& L) {
 if (&L == this) {
  return *this;
 }
 Erase();
 Clone(L);
 return *this;
}
bool List::IsEmpty() const {
 if (first == nullptr) {
  throw std::logic_error("The list is empty");
 }
}
bool List::DeleteFirst(){
 if (first == nullptr)
 {
  return false;
 }
 ListItem* p = first;
 first = first->Next;
 delete p;
 return true;
}
const int List::Top() const {
 if (first == nullptr)
 {
  throw std::logic_error("The list is empty\n");
 }
 int x = first->Info;
 return x;
}
void List::Clone(const List& L) {
 Erase(); 
 ListItem* p = L.first;
 ListItem* q = nullptr;
 ListItem* r = nullptr;

 while (p != nullptr) {
  q = new ListItem;
  q->Info = p->Info;
  q->Next = nullptr;

  if (r == nullptr) {
   first = q;
  }
  else {
   r->Next = q;
  }
  r = q;
  p = p->Next;
 }
}
void List::Erase() {
 ListItem* p;
 ListItem* q;
 p = first;
 while (p != nullptr) {
  q = p->Next;
  delete p;
  p = q;
 }
 first = nullptr;
}
List::~List() {
 Erase();
}
List::List(const List& L){
 Clone(L);
}
List::List() {
 first = nullptr;
}