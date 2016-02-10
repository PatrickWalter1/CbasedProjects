#include <iostream>
#include "btree.h"

int main()
{
   BTree<int> t;

   t.insert(40);
   t.insert(20);
   t.insert(10);
   t.insert(5);
   t.insert(15);
   t.insert(30);
   t.insert(60);
   t.insert(50);
   t.insert(70);
   
   cout << "Inorder: ";
   t.inorder();
   cout << endl << endl << "Height of tree is " << t.height() << endl << endl;
   
   if (t.search(10)) cout << "10 is found" << endl;
   else cout << "10 not found" << endl;

   if (t.search(1)) cout << "1 is found" << endl;
   else cout << "1 not found" << endl;

   return 0;
}
