#include "mylist.h"

int main()
{
   List<int> list;

   list.Display();
   list.InsertAtFront(10);
   list.Display();
   list.InsertAtFront(20);
   list.Display();
   list.InsertAtEnd(30);
   list.Display();
   list.Reverse();
   list.Display();

   cout << endl << endl;

   while (list.DeleteFromFront()) list.Display();

   return 0;
}

