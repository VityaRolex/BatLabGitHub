#include "list.h"

int main()
{
 try {
  List L;

  L.InsertFirst(10);
  L.InsertFirst(20);
  L.InsertFirst(30);
  L.ListPrint();
  std::cout << "View the first item in the list: " << L.Top() << '\n';

  if (L.DeleteFirst()) {
   std::cout << "First element deleted\n";
  }
  L.ListPrint();

  List Clone(L);
  std::cout << "Cloned list:\n";
  Clone.ListPrint();
  
  List Assigned;
  Assigned = L;
  std::cout << "Assigned list:\n";
  Assigned.ListPrint();

  L.Erase();
  std::cout << "Original list erased\n";

  L.IsEmpty();

  std::cout << "Trying Top on empty list:\n";
  std::cout << L.Top() << std::endl;
 }
 catch (const std::logic_error& e) {
  std::cerr << e.what() << std::endl;
 }
 return 0;
}