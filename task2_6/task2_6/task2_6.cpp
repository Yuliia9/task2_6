#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*maximum length of surname and initials of student*/
const int LEN = 30; 

struct stud
{
	char name[LEN];
	int age;
	char sex;
	double height;
	double weight;
};
/*checking entered data and return 0 if type doesn't match requirements*/
int Type_checking(int retCode, double val);
int Type_checking(int retCode, int val);

/*input information about students into list of students and return 0 if some data doesn't match requirements*/
int Input(struct stud* stud_list, int num);

/*displayed table of information about students*/
void Output(struct stud* stud_list, int num);

/*sorted table of information about students by surname*/
void Sort_by_surname(struct stud* stud_table, int num);

/*evaluate and display the average height and weight separate for female and male*/
void Average(struct stud* stud_table, int num);



int main()
{
	printf("Please enter how many students took medical examination: ");
	int retCode, num_of_stud;
	retCode = scanf("%i", &num_of_stud);

	if (0 == Type_checking(retCode, num_of_stud))
	{
		return 0;
	}

	struct stud* stud_list = (stud*)malloc(num_of_stud*sizeof(stud));
	printf("Please enter information about students. \nMaximum length of surname and initials is %i  \n", LEN);
	if (0 == Input(stud_list, num_of_stud))
	{
		return 0;
	}
	Sort_by_surname(stud_list, num_of_stud);
	printf("\nInformation about students: \n");
	printf("surname  age \t sex \t height weight");
	Output(stud_list, num_of_stud);
	Average(stud_list, num_of_stud);
	return 0;
}





int Input(struct stud* stud_list, int num)
{
	int retCode;
	for (int i = 0; i < num; i++)
	{
		printf("%i student surname and initials:  ", i + 1);
		getchar();
		gets(stud_list[i].name);
		printf("age: ");
		retCode = scanf("%i", &stud_list[i].age);
		if (0 == Type_checking(retCode, stud_list[i].age))
		{
			return 0;
		}
		printf("enter char that identify sex of student(f-female, m-male): ");
		getchar();
		stud_list[i].sex = getchar();
		if (stud_list[i].sex != 'f' && stud_list[i].sex != 'm')
		{
			printf("Data mismatch. Please next time check information.\n");
			return 0;
		}
		printf("height (if float number, separate it by dot): ");
		retCode = scanf("%lf", &stud_list[i].height);
		if (0 == Type_checking(retCode, stud_list[i].height))
		{
			return 0;
		}
		printf("weight (if float number, separate it by dot): ");
		retCode = scanf("%lf", &stud_list[i].weight);
		if (0 == Type_checking(retCode, stud_list[i].weight))
		{
			return 0;
		}
		
	}
	return 1;
}

int Type_checking(int retCode, double val)
{
	if (0 == retCode)
	{
		printf("Type mismatch.\n");
		return 0;
	}
	if (val < 0)
	{
		printf("The value can not be negative or null.\n");
		return 0;
	}
	return 1;
}
int Type_checking(int retCode, int val)
{
	if (0 == retCode)
	{
		printf("Type mismatch.\n");
		return 0;
	}
	if (val < 0)
	{
		printf("The value can not be negative or null.\n");
		return 0;
	}
	return 1;
}

void Output(struct stud* stud_list, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("\n%s\t", stud_list[i].name);
		printf("%i\t", stud_list[i].age);
		if ('f' == stud_list[i].sex)
		{
			printf("female\t");
		}
		else if ('m' == stud_list[i].sex)
		{
			printf("male\t");
		}
		printf("%0.2lf\t", stud_list[i].height);
		printf("%0.2lf", stud_list[i].weight);
	}
	
}

void Sort_by_surname(struct stud* stud_list, int n)
{
	struct stud temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (1 == strcmp((stud_list + i)->name, (stud_list + j)->name))
			{
				temp = *(stud_list + i);
				*(stud_list + i) = *(stud_list + j);
				*(stud_list + j) = temp;
			}
		}
	}
}

void Average(struct stud* stud_table, int num)
{
	double aver_height1 = 0, aver_height2 = 0;
	double aver_weight1 = 0, aver_weight2 = 0;
	int n1 = 0, n2 = 0;
	for (int i = 0; i < num; i++)
	{
		if ('f' == stud_table[i].sex)
		{
			n1++;
			aver_height1 += stud_table[i].height;
			aver_weight1 += stud_table[i].weight;
		}
		else if ('m' == stud_table[i].sex)
		{
			n2++;
			aver_height2 += stud_table[i].height;
			aver_weight2 += stud_table[i].weight;
		}
	}
	if (n1 != 0)
	{
		aver_height1 /= n1;
		aver_weight1 /= n1;
		printf("\nAverage female height and weight respectively: %0.2lf, %0.2lf\n", aver_height1, aver_weight1);
	}
	else
	{
		printf("\nSorry, there is no womens for evaluating average height and weight.\n");
	}
	if (n2 != 0)
	{
		aver_height2 /= n2;
		aver_weight2 /= n2;
		printf("\nAverage male height and weight respectively: %0.2lf, %0.2lf\n", aver_height2, aver_weight2);
	}
	else
	{
		printf("\nSorry, there is no mans for evaluating average height and weight.\n");
	}
	
		
	
}
