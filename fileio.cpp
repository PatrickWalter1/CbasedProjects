#include <iostream>
#include <fstream>

int main()
{
   char ch;

   ifstream inFile;
   ofstream outFile;

   inFile.open("fileio.cpp");
   outFile.open("fileio.bak");

   if (inFile.fail() || outFile.fail())
   {
      cout << "File cannot be opened." << endl;
      return 0;
   }

   inFile.get(ch);

   while (!inFile.eof())
   {
      outFile << ch;
      inFile.get(ch);
   }

   inFile.close();
   outFile.close();

   cout << "Done!" << endl;

   return 0;
}