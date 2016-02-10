/* File: Assign4.cpp
*Name:			Patrick Walter
*Username:   x2010ogh
*Purpose: assignment 4
*date: december 1st
*
*this programs gives instuction on how to get a desired amount of water using two
*coprime volumed buckets.
*/

# include <iostream>
bool coprime(int x, int y);
 /*main program*/
int main ()

{
int volume, pail1, pail2, x, y, answer;
while (true){
cout << "Enter desired measurment: " ;
cin >> volume ;
cout << "Enter first pail volume: ";
cin >> pail1;
cout << "Enter second pail volume: ";
cin >> pail2;

	if ( pail1 < pail2)
   	{ x=pail1; y=pail2;}
   else
   	{x=pail2; y=pail1;}

   if ( volume > y)
   {  cout << "this volume can not be obtianed" << endl;}
   if ( coprime(x,y) == false)
   { cout << "NUMBERS ARE NOT COPRIME" << endl;break;}

pail1=0;
pail2=0;
answer=0;

	while ( answer!=volume)
 	{

   	while (pail2 < y)
      {
      pail2=pail2 + x;
      cout << "Fill " << x << " liter pail, pour into " << y << " liter pail"<< endl;
      if (pail2== volume)break;
      }

      if (pail2==volume)break;

      pail1= pail2-y;
      cout << "Empty " << y << " liter pail "<< endl;
      if (pail1==volume) break;
      cout << "Pour " << x << " liter pail into " << y << " liter pail"<< endl ;


      if (pail2==volume)break;

      answer = pail2+pail1;
      pail2= pail1;

    }
    }
}
/*
*Function: coprime
*usage: coprime(x,y)
*--------------------
*this function checks to see if two numbers are coprime
*/
bool coprime(int x,int y)
{
int i;

for ( i=2; i<y; i++)
{ if (y%i ==0)
	 {
	 return (false);
    }
} if ( x%i==0)
		{return (false);}
return (true);
}
