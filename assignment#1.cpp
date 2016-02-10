#include <iostream>
#include <fstream>
#define NameLength 20
#define maxnames 50

void readnames( ifstream &infile, char names[NameLength][maxnames])
void sortnames(char *ptrs[])

int main ()
{
char names[NameLength][maxnames];



 ifstream infile("phone.txt");
   if (infile.fail())
   {
   	cout << "names not found" << endl;
      return 0;
   }

void readnames(ifstream infile, names[]);

	for (i=0;i<maxnames;i++)
	{
   ptrs[i]=&names[


void sortnames(ptrs[])


}







void readnames(ifstream infile,string names[])
{
int i;
	for (i = 0; i<maxnames; i++)
		{
   	getline(ifstream infile,names[i]);
      }
}

bool compare(char name1[], char name2[])
{
        int i=0;
        char ch1, ch2;

        ch1=array1[i];
        ch2=array2[i];
        if(ispunct(ch1))
        {
                ch1=' ';
        }

        if(ispunct(ch2))
        {
                ch2=' ';
        }

        ch1 = toupper(ch1);
        ch2 = toupper(ch2);

    while((ch1!='\0')||(ch2!='\0'))
        {
                cout << "'" << ch1 << "'  '" << ch2 << "'" << endl;
                if (ch1>ch2)
                {
                        return true;
                }

                else if (ch1<ch2)
                {
                        return false;
                }
                else
                {
                        i++;

                        ch1=array1[i];
                        ch2=array2[i];

                        if(ispunct(ch1))
                        {
                                ch1=' ';
                        }

                        if(ispunct(ch2))
                        {
                                ch2=' ';
                        }

                        ch1 = toupper(ch1);
                        ch2 = toupper(ch2);
            }



        }
        return false;
}


int sortnames(char *ptrs[])
{
char *temp;

for (i=0;i<maxnames;i++)
{

if (compare (*ptrs[i], *ptrs[i+1])0)
	{
   temp = ptrs[i];
   ptrs[i] = ptrs[i+1];
   ptrs[i+1] = temp;
   }



}



