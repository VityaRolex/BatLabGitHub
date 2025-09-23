#include "list.h"

void List::InsertFirst(const int& Ainfo){
 ListItem* ptrItemList = new ListItem;
 ptrItemList->Info = Ainfo;
 ptrItemList->Next = first;
 first = ptrItemList;
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
 ListItem* ptrItemList = first;
 first = first->Next;
 delete ptrItemList;
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
 ListItem* ptrItemList = L.first;
 ListItem* TempPtrItem = nullptr;
 ListItem* ptrLastAddedItem = nullptr;

 while (ptrItemList != nullptr) {
  TempPtrItem = new ListItem;
  TempPtrItem->Info = ptrItemList->Info;
  TempPtrItem->Next = nullptr;

  if (ptrLastAddedItem == nullptr) {
   first = TempPtrItem;
  }
  else {
   ptrLastAddedItem->Next = TempPtrItem;
  }
  ptrLastAddedItem = TempPtrItem;
  ptrItemList = ptrItemList->Next;
 }
}
void List::Erase() {
 ListItem* ptrItemList;
 ListItem* tempPtrItem;
 ptrItemList = first;
 while (ptrItemList != nullptr) {
  tempPtrItem = ptrItemList->Next;
  delete ptrItemList;
  ptrItemList = tempPtrItem;
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