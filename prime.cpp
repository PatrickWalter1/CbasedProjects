#include <iostream>
/* Filename: prime.cpp
 * -------------------
 * Author:	M. van Bommel
 * Course:  CSCI 161
 * Date:    10 November 2010
 *
 * Purpose: To implement and test a function to test for primality.
 */

#include <math>

/* Function Prototype */

bool Prime(int);

/* Main Program */

int main(void)
{
   int i;

   for (i=-3; i<=50; i++)
   {
   	if (prime(i)) cout << i << endl;
   }

   cout << "5849 is" << (prime(5849)? " " : " not ") << "prime" << endl;
   cout << "5850 is" << (prime(5850)? " " : " not ") << "prime" << endl;

	return 0;
}

/* Function: Prime
 * Usage: if (Prime(n))
 * --------------------
 * Returns the result of testing if n is prime by trying to find
 * a factor between 2 and sqrt(n).
 */

bool Prime(int n)
{
	int i, limit;

   if (n == 2) return true;					  // 2 is prime

   if (n < 2 || n % 2 == 0) return false;  // negatives and evens not prime

   limit = sqrt(n) + 1;   					    // no need to test past this

   for (i=3; i<limit; i+=2)
   {
   	if (n % i == 0) return false;		    // found a factor so not prime
   }

   return true;		                      // no factor found so prime
}
