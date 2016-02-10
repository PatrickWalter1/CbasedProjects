/* Filename: mylist.h
 * ------------------
 * Author: M. van Bommel
 * Course: CSci 162
 * Date:   23 March 2011
 *
 * Purpose: Generic template class implementation of list.
 *
 * To create a list to store datatype d, declare it as a List<d> name;
 * for example, to create a list of integers, use
 *                  List<int> myIntList;
 *
 * To then use a method m on the list, use name.m();
 * for example, to insert the number 10 at the front of myIntList, use
 *                  myIntList.InsertAtFront(10);
 *
 * Notes:
 *
 * In order to use display, stream insertion (<<) must be defined for
 *       the type used in the list.
 *
 * In order to use InsertInOrder, less than (<) must be defined for
 *       the type used in the list.
 */

#ifndef _mylist_h
#define _mylist_h

#include <iostream>
#include <stdlib>

template <class T>
class ListNode
{
   public:
      T value;
      ListNode<T> *next;
      ListNode(const T &v, ListNode *n = NULL) : value(v), next(n) {}
};

template <class T>
class List
{
   private:
      ListNode<T> *head, *tail;
      int size;
   public:
      List() { head = tail = NULL; size = 0;}
     ~List();
      bool InsertAtFront(const T &);
      bool InsertAtEnd(const T &);
      bool InsertInOrder(const T &);
      const T & Front() const;
      bool DeleteFromFront();
      int  Size() const { return size; }
      bool Empty() const { return head == NULL; }
      void Display() const;
      void Reverse();
};

template <class T>
List<T>::~List()
{
   ListNode<T> *temp;

   while ((temp = head) != NULL)
   {
      head = head->next;
      delete temp;
   }
}

template <class T>
bool List<T>::InsertAtFront(const T &val)
{
   ListNode<T> *temp = new ListNode<T>(val, head);
   if (temp == NULL) return false;
   head = temp;
   if (tail == NULL) tail = head;
   size++;
   return true;
}

template <class T>
bool List<T>::InsertAtEnd(const T &val)
{
   ListNode<T> *temp = new ListNode<T>(val, NULL);
   if (temp == NULL) return false;
   if (head == NULL) head = temp;
   else tail->next = temp;
   tail = temp;
   size++;
   return true;
}

template <class T>
bool List<T>::InsertInOrder(const T &val)
{
   ListNode<T> *temp = new ListNode<T>(val, NULL);
   if (temp == NULL) return false;
   size++;

   if (head == NULL)
   {
      head = tail = temp;
   }  else if (val < head->value) {
      temp->next = head;
      head = temp;
   } else {
       ListNode<T> *curr = head->next, *prev = head;
      while (curr != NULL && curr->value < val)
      {
         prev = curr;
         curr = curr->next;
      }
      temp->next = curr;
      prev->next = temp;
      if (curr == NULL) tail = temp;
   }
   return true;
}

template <class T>
const T & List<T>::Front() const
{
   if (head == NULL)
   {
      cout << endl << "*** Cannot take front of empty list! ***" << endl;
      exit(0);
   }
   return head->value;
}

template <class T>
bool List<T>::DeleteFromFront()
{
   if (head == NULL) return false;
   ListNode<T> *temp = head;
   head = head->next;
   if (tail == temp) tail = NULL;
   delete temp;
   size--;
   return true;
}


template <class T>
void List<T>::Display() const
{
   ListNode<T> *n;
   cout << "Head -> ";
   for (n = head; n != NULL; n = n->next)
   {
      cout << n->value << " -> ";
   }
   cout << "NULL" << endl;
}

template <class T>
void List<T>::Reverse()
{
ListNode<T> *prev=NULL, *nxt;
tail = head;

while( head!=NULL)
{
nxt = head->next;
head->next=prev;
prev=head;
head=nxt;
}
head=prev;

return;
}

#endif
