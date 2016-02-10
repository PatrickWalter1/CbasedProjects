/* Filename: payday.cpp
 * --------------------
 * Author:	M. van Bommel
 * Course:	CSci 161
 * Date:		October 20, 2010
 *
 * Purpose:	Permits the user to determine the duration of an cash payout.
 *				It accepts a starting principle, annual interest rate,
 *				and a bi-weekly payment, and determines the amount of time
 *				the money will last.  It is assumed that the first payment
 *				is withdrawn before the money is deposited.
 */

#include <iostream>

int main()
{
	int weeks, years;
   double balance, rate, payment, interest;

   cout << "Please enter the amount of the cash prize: ";
   cin  >> balance;

   cout << "Please enter the annual interest rate (in percent): ";
   cin  >> rate;

   cout << "Please enter the bi-weekly withdrawl: ";
   cin  >> payment;

   weeks    = 0;

   rate     = rate / 2600.0; 			// bi-weekly rate

   balance  = balance - payment;		// initial withdrawl

   interest = balance * rate;			// first period's interest earned

   if (interest >= payment)
   {
   	cout << "You will be able to withdraw the money forever!";
   } else {
   	while (balance + interest >= payment)
      {
      	balance += interest - payment;
      	weeks   += 2;
         interest = balance * rate;
      }

   	years = weeks / 52;
   	weeks = weeks % 52;
		cout << "You can withdraw money for " << years
           << " years and " << weeks << " weeks" << endl;
   }
	return 0;
}
