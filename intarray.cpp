/* Filename: intarray.cpp
 * ----------------------
 * Course: CSCI 162
 * Author: M. van Bommel
 * Date:   January 20, 2010
 *
 * Purpose: This program asks the user to enter values up to a sentinel value,
 * reverses the values, and prints them out in reverse order.  It then sorts
 * the values using a selection sort, and prints them in ascending order.
 * This program develops several functions for an array of integers.
 * Included are functions to fill up an array from input,
 * print the array, and reverse and sort the elements in the array.
 */

#include <iostream>

#define NElements 10
#define SENTINEL  -1

int  GetIntegerArray(int array[], int size, int sentinel);
void PrintIntegerArray(int array[], int n);
void ReverseIntegerArray(int array[], int n);
void SwapIntegerElements(int array[], int pos1, int pos2);
int  FindSmallestInteger(int array[], int low, int high);
int  SequentialSearch(int key, int array[], int n);
int  BinarySearch(int key, int array[], int n);
void SortIntegerArray(int array[], int n);

int main()
{
   int list[NElements];
   int n;

   cout << "Enter values (" << SENTINEL << " to stop)" << endl;
   n = GetIntegerArray(list, NElements, SENTINEL);
   cout << endl << endl << "In reverse order:" << endl;
   ReverseIntegerArray(list, n);
   PrintIntegerArray(list, n);
   cout << endl << endl << "In sorted order:" << endl;
   SortIntegerArray(list, n);
   PrintIntegerArray(list, n);
   cout << endl;

   return 0;
}

int  GetIntegerArray(int array[], int size, int sentinel)
{
   int count = 0;

   cout << "? ";
   cin  >> array[count];
   while (array[count] != sentinel)
   {
      count++;
      if (count == size) return count;
      cout << "? ";
      cin  >> array[count];
   }
   return count;
}


void ReverseIntegerArray(int array[], int n)
{
   int i;

   for (i=0; i < n/2; i++)
   {
      SwapIntegerElements( array, i, n - i - 1);
   }
}

void SwapIntegerElements(int array[], int pos1, int pos2)
{
   int temp;
   temp = array[pos1];
   array[pos1] = array[pos2];
   array[pos2] = temp;
}

void PrintIntegerArray(int array[], int n)
{
   int i;

   for (i=0; i<n; i++)
   {
      cout << array[i] << " ";
   }
}

int SequentialSearch(int key, int array[], int n)
{
   int i;
   for (i=0; i<n; i++)
   {
      if (array[i] == key) return i;
   }
   return -1;
}

int BinarySearch(int key, int array[], int n)
{
   int low = 0, high = n-1, mid;

   while (low <= high)
   {
      mid = (low + high) / 2;

      if (array[mid] == key) return mid;

      if (array[mid] > key) high = mid - 1;
      else low = mid + 1;
   }
   return -1;
}

int FindSmallestInteger(int array[], int low, int high)
{
   int i, pos = low;
   for (i=low+1; i<=high; i++)
   {
      if (array[i] < array[pos]) pos = i;
   }
   return (pos);
}

void SortIntegerArray(int array[], int n)
{
   int i, small;

   for (i = 0; i < n; i++)
   {
      small = FindSmallestInteger(array,i,n-1);
      SwapIntegerElements(array, i, small);
   }
}
