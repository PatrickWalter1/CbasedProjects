/* File: Assign4.cpp
*Name:			Patrick Walter
*Username:   x2010ogh
*Purpose: assignment 4
*date: december 1st
*
*this programs simulates the line at the inn to give average wait times.
*/


#include <iostream>
#include <iomanip>
#include "random.h"
#include "myqueue.h"

#define InitialPatrons 100               // Patrons in Inn at 8:00

#define Capacity       250               // Overall capacity of Inn

int num_arrive[] = {2, 3, 3, 2, 1};      // Average number arriving each hour

int num_depart[] = {0, 1, 2, 3, 4};      // Average number leaving each hour

int RandomNum(int avg);                  // Generate value in normal distribution

int main()
{
   Queue<int> line;                                  // Line-up waiting to get in

   int patrons = InitialPatrons;                     // Number people in the Inn

   int time, i, arrivals, departures, entry_time, intline=0, beginline,
   maxline=0, Ltime, waittime, wait[5]={0,0,0,0,0}, line1[5]={0,0,0,0,0}, counter=0;
   double totalarrivals=0.0,totalwait=0.0, waitmax=0;


   Randomize();                                      // Seed the random numbers

   for (time=0; time<300; time++)                    // Each minute from 8 - 1.
   {
      if (patrons == Capacity &&  counter!=1)
        { beginline=time;
         counter++ ;
         }
      arrivals = RandomNum(num_arrive[time/60]);   // arriving this minute

      totalarrivals= totalarrivals +arrivals;

      for (i=0; i<arrivals; i++)
      { line.Enqueue(time);
      	intline++;}
         											 // End of the line

      departures = RandomNum(num_depart[time/60]);   // leaving this minute

      patrons -= departures;									// bye-bye


      while (patrons < Capacity && !line.Empty())
      {
         entry_time = line.Front();
         waittime= (time - entry_time);                  // move from line into Inn
         line.Dequeue();
         intline--;
         patrons++;
         totalwait= totalwait + waittime;
         if (waittime > waitmax) waitmax = waittime;

         wait[time/60]= wait[time/60] + (time - entry_time);
       	line1[time/60]++;

      }
     // cout << setw(4) << time << ":  " << arrivals << "  " << departures
       //    << setw(5) << patrons << endl;
          if (intline > maxline)
          {
          	maxline=intline;
            Ltime=time;
          }
   }

  //	cout << setw(4) << time << ":  " << arrivals << "  " << departures
   //   << setw(5) << patrons << endl;

   cout << " The maximum number of students in line is ";
   cout << maxline << " at " << setfill('0') << setw (2)<< ( 8 +(Ltime/60)) << ":" << Ltime%60 << endl;
   cout << " The average wait time is about " << (int (totalwait/totalarrivals +.999)) << " minutes " << endl;
   cout << " The average wait time from 8:00 to 9:00 is " << wait[0]/line1[0] << " minutes " << endl;
   cout << " The average wait time from 9:00 to 10:00 is " << wait[1]/line1[1] << " minutes " << endl;
   cout << " The average wait time from 10:00 to 11:00 is " << wait[2]/line1[2] << " minutes " << endl;
   cout << " The average wait time from 11:00 to 12:00 is " << wait[3]/line1[3] << " minutes " << endl;
   cout << " The average wait time from 12:00 to 1:00 is " << wait[4]/line1[4] << " minutes " << endl;
   cout << " The maximum wait time is " << waitmax << " minutes" << endl;
   cout << " The line starts at " << (8 + beginline/60) << ":" << setfill('0') << setw (2) << beginline%60 << endl;

   return (0);
}

int RandomNum(int avg)
{
   return RandomInteger(0,avg) + RandomInteger(0,avg);
}
