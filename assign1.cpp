/*File:assign1.cpp
*------------------------
*Name: patrick walter
*Username: x2010ogh
*Couse: CSci 161
*Purpose: Lab #1
*
*This program work as a basic calculator
*/

#include <iostream>
#include <ctype>
#include <stdio>
#include <math>
#include <stdlib>


int main ()
{

double display=0, num, num2;
char opp, opp2;
cout << "Welcome to my calculator:"<< endl;
while (true)
{
cout << display << endl;
cin >> opp;
	if (opp== 'r') display=sqrt(display);
   if (opp== 'c') display=0;
	if (opp== 'q')
   { cout << "Goodbye"; exit(0);}

   else if(opp != 'r')
   {
	cin >> num;

		if (opp== '+') display+=num;
		if (opp== '-') display-=num;
		if (opp== '*') display= display * num;
		if (opp== '/') display= display/num;
		if (opp== 'r') display=sqrt(display);
		if (opp== '^') display= pow(display,num);
      if (opp=='(')
   	{
   		cin >> opp2;
			if (opp2== 'r') display=sqrt(display);
   		if (opp2== 'c') display=0;
			if (opp2== 'q')
   		{ cout << "Goodbye";break; exit(0);}

   		else if(opp2 != 'r')
   		{
			cin >> num2;

			if (opp2== '+') display+=num2;
			if (opp2== '-') display-=num2;
			if (opp2== '*') display= display * num2;
			if (opp2== '/') display= display/num2;
			if (opp2== 'r') display=sqrt(display);
			if (opp2== '^') display= pow(display,num2);
   		if (opp2==')')break;
   		}

		}
	}
}









return 0;
}
