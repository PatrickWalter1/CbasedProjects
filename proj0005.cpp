/*File:lab11.cpp
*------------------------
*Name: patrick  walter
*Username: x2010ogh
*Couse: CSci 161
*Purpose: Lab #11
*Date: thursday, december 2, 2010
*
*This program makes a christmas tree
*/
#include <iostream>
#include <conio>
#include <stdio>

/*Function Prototype */
void Space(int numSpaces);
void stars(int numstars, int count);

/* Main program*/
int main()

{
int x;
for (x=0;x<100;x++)
{
int i=0, numSpaces=13, numstars=1, count=0;
printf("\007");
	for (i=0;i<13;i++)
	{
		Space(numSpaces);
		stars(numstars,count);
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
    cout<< "           MERRY";

 count++;
  getch();
  clrscr();
printf ("\a");

 int y=0;
	for (numSpaces=12; numSpaces >= 0; numSpaces--)
	{

	Space(numSpaces);

	cout << '/';
	stars(25 - 2*(numSpaces),count);
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
 printf ("\a");
  getch();
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
void stars(int numstars,int count )
{

	while(numstars>0 )
   {  if (count==0)
      {
  	 	cout << '*' ;
      }
      if (count==1)
      {
      	if(numstars%2==0)
      	{cout << '0';}
      	else{
      	cout<< '*';}
     	}
      numstars--;
   }
}
