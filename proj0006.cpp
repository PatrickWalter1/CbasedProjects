#include <iostream>
#include <fstream>

#define NameLength   20
#define StringLength 10
#define MaxStudents 200

struct student_t {
	long id;
   char fname[NameLength];
   char lname[NameLength];
   int  year;
   char program[StringLength];
   char major[StringLength];
};

bool ReadAStudent(ifstream &infile, student_t *s);
int  ReadStudents(ifstream &infile, student_t student[], int max);
void WriteStudents(student_t *stu[], int n);
void Sort(student_t *ptrs[], int n);


int main()
{
	int count = 0, i;
	student_t *student = new student_t[MaxStudents];
   student_t *ptrs[MaxStudents];

   ifstream infile("students.txt");
   if (infile.fail())
   {
   	cout << "Student file not found" << endl;
      return 0;
   }

	count = ReadStudents(infile, student, MaxStudents);

   for (i=0; i<count; i++) ptrs[i] = &student[i];

   Sort(ptrs, count);

   WriteStudents(ptrs, count);

   infile.close();
	return 0;
}

void Sort(student_t *ptrs[], int n)
{
	int i, j;
   student_t *temp;

   for (j=1; j<n; j++)
   {
   	for (i=0; i<n-j; i++)
      {
      	if (ptrs[i]->id > ptrs[i+1]->id)
         {
         	temp = ptrs[i];
            ptrs[i] = ptrs[i+1];
            ptrs[i+1] = temp;
         }
      }
   }
}

bool ReadAStudent(ifstream &infile, student_t *s)
{
   infile >> s->id;
   if (infile.eof()) return false;
 	infile >> s->fname >> s->lname >> s->year >> s->program >> s->major;
   return true;
}

int ReadStudents(ifstream &infile, student_t student[], int max)
{
	int count = 0;

   while (ReadAStudent(infile, &student[count]))
   {
      count++;
      if (count == max)
      {
      	cout << "Too many students in ReadStudents\n";
         return count;
      }
   }
   return count;
}

void WriteStudents(student_t *stu[], int n)
{
	int i;
   for (i=0; i<n; i++)
   {
   	cout << stu[i]->id << "  " << stu[i]->lname << ", " << stu[i]->fname << endl;
   }
}



