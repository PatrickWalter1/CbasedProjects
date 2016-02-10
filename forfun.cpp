#include <iostream>
#include <fstream>
#include "mylist.h"
#define maxchar 1000
int main()
{
int i,k;
enum daysT { monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday};
char *name[] = {"moday", "tuesday", "wednesday", "thursday", "saturday" , "sunday"};
char note[maxchar] ;
for (i=0;i<6;i++)
	{
   cout << name[i] << endl;
   }

   ifstream infile;

   List <char> mylist;

   infile.open("mylist.h") ;

   if (infile.fail()) cout << "fail" << endl;

   for (k=0;k<maxchar;k++)
   {

   infile >> note[k];
      .Stack = note[k]
   	if(note[k]<90)
			cout << note[k];


   }
mylist.Stack = note[k]


return(0);
}
