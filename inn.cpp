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

   int time, i, arrivals, departures, entry_time;

   Randomize();                                      // Seed the random numbers

   for (time=0; time<300; time++)                    // Each minute from 8 - 1.
   {
      arrivals = RandomNum(num_arrive[time/60]);     // arriving this minute

      for (i=0; i<arrivals; i++) line.Enqueue(time); // End of the line

      departures = RandomNum(num_depart[time/60]);   // leaving this minute

      patrons -= departures;                         // bye-bye

      while (patrons < Capacity && !line.Empty())
      {
         entry_time = line.Front();                  // move from line into Inn
         line.Dequeue();
         patrons++;
      }
      cout << setw(4) << time << ":  " << arrivals << "  " << departures
           << setw(5) << patrons << endl;
   }

   cout << setw(4) << time << ":  " << arrivals << "  " << departures
        << setw(5) << patrons << endl;

   return (0);
}

int RandomNum(int avg)
{
   return RandomInteger(0,avg) + RandomInteger(0,avg);
}

