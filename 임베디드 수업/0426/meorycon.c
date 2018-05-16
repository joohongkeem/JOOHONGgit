#include <stdio.h>
#include <time.h>
#define MAX 10000

struct name
{
	unsigned char name[6];
        unsigned char kor;
        unsigned char eng;
        unsigned char math;
        unsigned char germ;
        short total;
        float average;
 };
typedef struct name NAME;

void in_data(NAME* students){
	int i;
	srand(time(NULL));
	

	for(i=0;i<MAX;i++)
        {
                students[i].kor = (rand() % 99) + 1;

                students[i].eng = (rand() % 99) + 1;

                students[i].math = (rand() % 99) + 1;

                students[i].germ = (rand() % 99) + 1;
        }
	
	for(i=0;i<MAX;i++)
	{
		students[i].total = students[i].kor + students[i].eng + 
		students[i].math + students[i].germ; 
	}


	for(i=0;i<MAX;i++)
	{
		students[i].average = students[i].total/4.0;
	}	
}

void print_data(NAME *students)
{
	int i;

	for(i=0;i<MAX;i++)
	{
		printf("%d번째 학생 ", i+1);
		printf("%d ", students[i].kor);
		printf("%d ", students[i].eng);
		printf("%d ", students[i].math);
		printf("%d ", students[i].germ);
		printf("%d ", students[i].total);
		printf("%f", students[i].average);
		
		puts("");
	}
}

void main()
{
	NAME students[MAX];
	
	in_data(&students);
	print_data(students);

}
