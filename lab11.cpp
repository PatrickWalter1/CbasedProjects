/*File:lab.cpp
*------------------------
*Name: patrick
*Username: x2010ogh
*Couse: CSci 161
*Purpose: Lab #1
*Date: thursday, september 16, 2010
*
*This program accepts a name and displays it several times
*/
#include <iostream>
#include <conio>
#include <cstdlib>

/*Function Prototype */
void Space(int numSpaces);
void stars(int numstars);

/* Main program*/
int main()
{


int x;
for (x=0;x<10;x++)
{
int i=0, numSpaces=13, numstars=1, count=0;

	for (i=0;i<13;i++)
	{
		Space(numSpaces);
		stars(numstars);
		cout << endl;
		numSpaces--;
		numstars+=2 ;
	}

   for (i=14;i<16;i++)
   {
   	Space(numSpaces=11);
      cout<< '|';
      Space(numSpaces=4);
      cout<< '|'<<endl;
    }
    cout<< "            MERRY";
/* -------------------------------------------------------*/
getchar();

  clrscr();

	for (numSpaces=13; numSpaces >= 1; numSpaces--)
	{
	Space(numSpaces);
	cout << '/';
	Space(26 - 2*(numSpaces));
	cout << '\\' << endl;
   }
   for (i=14;i<16;i++)
   {
   	Space(numSpaces=11);
      cout<< '|';
      Space(numSpaces=4);
      cout<< '|'<<endl;
    }
    cout<< "          CHRISTMAS";
  clrscr();
}


}

/*
*Function: Space
*usage: space(numSpaces);
*-----------------------------------
*this function displays numSpaces blank on output.
*/
void Space(int numSpaces)
{

	while(numSpaces > 0)
   {

  	 	cout << ' ' ;
  	   numSpaces--;

   }
}
/*
*Function: stars
*usage: stars(numstars);
*-----------------------------------
*this function displays i "*" on output.
*/
void stars(int numstars )
{

	while(numstars>0 )
   {
   	if(numstars%2==0)
      {cout << '@';}
      if(numstars%2!=0)
  	 	{cout << '*' ;}
      numstars--;

   }
}