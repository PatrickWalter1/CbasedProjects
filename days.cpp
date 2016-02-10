#include <iostream>

enum weekdayT {
   Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

void PrintDay(weekdayT day);

int main()
{
   weekdayT day;

   int d;

   cout << "What day is it (Sunday=0, Monday=1, etc.)? ";
   cin >> d;

   while (d < Sunday || d > Saturday)
   {
      cout << "Invalid day. Please re-enter: ";
      cin >> d;
   }

   day = (weekdayT) d;

   cout << endl << "So it is ";
   PrintDay(day);

   cout << " and tomorrow is ";

   day = (weekdayT) ((day + 1) % 7);
   PrintDay(day);

   return 0;
}

void PrintDay(weekdayT day)
{
   char *name[] = {"Sunday","Monday","Tuesday","Wednesday",
                      "Thursday","Friday","Saturday"};

   cout << name[day];
}
