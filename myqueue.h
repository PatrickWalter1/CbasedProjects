/* Filename: myqueue.h
 * -------------------
 * Author: M. van Bommel
 * Course: CSci 162
 * Date:   23 March 2011
 *
 * Purpose: Generic template class implementation of queue (uses mylist.h).
 *
 * To create a stack to store datatype d, declare it as a Queue<d> name;
 * for example, to create a queue of integers, use
 *                  Queue<int> myIntQueue;
 *
 * To then use a method m on the queue, use name.m();
 * for example, to enqueue the number 10 into myIntQueue, use
 *                  myIntQueue.Enqueue(10);
 *
 */

#ifndef _myqueue_h
#define _myqueue_h

#include "mylist.h"

template <class T>
class Queue : private List<T>
{
   public:
      bool Enqueue(const T &val) { return InsertAtEnd(val); }
      bool Dequeue() { return DeleteFromFront(); }
      const T &Front() const { return List<T>::Front(); }
      bool Empty() const { return List<T>::Empty(); }
};

#endif
