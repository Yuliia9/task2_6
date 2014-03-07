/**
* @file		task2_6.cpp
* @brief	Program creates database for holding informations about students medical examination.
			Database stores students surnames, age, sex, height and weight.
			Program also sorts list by student's surname 
			and estimates average height and weight separate for male and female.

*
* Copyright 2014 by Yuliia Lyubchik
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*/


#include "stdafx.h"
#include "task2_6.h" /*defines data types and prototypes of used in this file functions*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned char ERROR = 0;
const unsigned char SUCCESS = 1;
const unsigned char MAIN_SUCCESS = 0;


int main()
{
	Interface();
	unsigned char retCode;
	unsigned int num; 

	do 
	{
		printf("Please enter how many students took medical examination: ");
		retCode = scanf("%u", &num);
		fflush(stdin); // Flush the input buffer

	} while (Type_checking(retCode, (int) num) == ERROR);
	printf("List will consist of %u students.\n", num);
	
	struct student* students = (student*)malloc (num * sizeof (student) );
	if (students == NULL)
	{
		printf("Error occurs while trying to allocate memory for list of points. \n");
		return (int)ERROR;
	}


	retCode = Input(students, num);
	if (retCode == ERROR)
	{
		free(students);
		return (int)ERROR;
	}


	retCode = Sort_by_surname(students, num);
	if (retCode == ERROR)
	{
		free(students);
		return (int)ERROR;
	}


	retCode = Output(students, num);
	if (retCode == ERROR)
	{
		free(students);
		return (int)ERROR;
	}


	retCode = Average(students, num);
	if (retCode == ERROR)
	{
		free(students);
		return (int)ERROR;
	}
	

	system("pause");
	free(students);
	return MAIN_SUCCESS;
}


void Interface()
{
	printf("---------------------------------------------------------------------------\n");
	printf("Hi! Please welcome to your personal students medical care handler.\n");
	printf("You can store list of students surnames and their personal information.\n");
	printf("Program will create for you sorted list of students \n and find average students height and weight.\n");
	printf("Program made by Yuliia Lyubchik;)\n");
	printf("---------------------------------------------------------------------------\n\n");
}


unsigned char Input(struct student* students, unsigned int num)
{
	if (students == NULL)
	{
		printf("Error occurs while trying to get access to memory to input data.\n");
		return ERROR;
	}

	printf("Please enter information about students. \nMaximum length of surname and initials is %i  \n", LEN);
	unsigned char retCode;
	unsigned int i;
	char temp[20];
	for (i = 0; i < num; ++i)
	{
		do 
		{
			printf("%i student surname and initials:  ", i + 1);
			gets(students[i].name);

		} while (strlen(students[i].name) == 0);
		
		do 
		{
			printf("age: ");
			scanf("%s", &temp);
			fflush(stdin); // Flush the input buffer
		} while (Is_digit(temp) == ERROR);

		students[i].age = atoi(temp);

		do 
		{
			printf("enter char that identify sex of student(f-female, m-male): ");
			students[i].sex = getchar();
			fflush(stdin); // Flush the input buffer
			if (students[i].sex != 'f' && students[i].sex != 'm')
			{
				printf("Data mismatch. Please next time check information.\n");
				retCode = ERROR;
			}
			else
			{
				retCode = SUCCESS;
			}
		} while (retCode == ERROR);
		

		do
		{
			printf("height (if float number, separate it by dot): ");
			scanf("%s", &temp);
			fflush(stdin); // Flush the input buffer
		} while (Is_digit(temp) == ERROR);

		students[i].height = atof(temp);
		
		do
		{
			printf("weight (if float number, separate it by dot): ");
			scanf("%s", &temp);
			fflush(stdin); // Flush the input buffer
		} while (Is_digit(temp) == ERROR);

		students[i].weight = atof(temp);
	}
	return SUCCESS;
}


unsigned char Type_checking(unsigned char retCode, int val)
{
	if (retCode == ERROR)
	{
		printf("Type mismatch.Next time please check data.\n");
		return ERROR;
	}
	if (val <= 0)
	{
		printf("The value can not be negative or zero.\n");
		return ERROR;
	}
	return SUCCESS;
}



unsigned char Is_digit(const char* pstr)
{
	if (pstr == NULL)
	{
		return ERROR;
	}
	unsigned int i;
	unsigned char krapka = 0;
	for ( i = 0; i < strlen(pstr); ++i )
	{
		if ( pstr[i] >= 48 && pstr[i] <= 57 )
		{
			continue;
		}
		else if (pstr[i] == '.')
		{
			if (krapka == 0)
			{
				krapka = 1;
			}
			else
			{
				printf("Type mismatch. Please next time check if you entered appropriate numbers.\n");
				return ERROR;
			}
		}
		else
		{
			printf("Type mismatch. Please next time check if you entered appropriate numbers.\n");
			return ERROR;
		}	
	}
	return SUCCESS;
}



unsigned char  Output(const struct student* students, unsigned  int num)
{
	if (students == NULL)
	{
		printf("Error occurs while trying to get access to data to display it.\n");
		return ERROR;
	}

	printf("\nInformation about students: \n");
	printf("surname  age \t sex \t height weight");
	unsigned int i;
	for (i = 0; i < num; ++i)
	{
		printf("\n%s\t", students[i].name);
		printf("%i\t", students[i].age);
		if ('f' == students[i].sex)
		{
			printf("female\t");
		}
		else if ('m' == students[i].sex)
		{
			printf("male\t");
		}
		printf("%0.2lf\t", students[i].height);
		printf("%0.2lf", students[i].weight);
	}
	return SUCCESS;
}

unsigned char  Sort_by_surname(struct student* students, unsigned int n)
{
	if (students == NULL)
	{
		printf("Error occurs while trying to get access to data to sort it.\n");
		return ERROR;
	}
	struct student temp;
	unsigned int i, j;
	for ( i = 0; i < n; ++i )
	{
		for ( j = i + 1; j < n; ++j )
		{
			if (1 == strcmp((students + i)->name, (students + j)->name))
			{
				memcpy(&temp, students+ j, sizeof(student));
				memcpy(students + j, students + i, sizeof(student));
				memcpy(students + i, &temp, sizeof(student));
			}
		}
	}
	return SUCCESS;
}


unsigned char  Average(const struct student* students, unsigned int num)
{

	if (students == NULL)
	{
		printf("Error occurs while trying to get access to data to provide estimation.\n");
		return ERROR;
	}

	double aver_height1 = 0, aver_height2 = 0;
	double aver_weight1 = 0, aver_weight2 = 0;
	unsigned int quatity1 = 0, quantity2 = 0;
	unsigned int i;

	for ( i = 0; i < num; ++i )
	{
		if ('f' == students[i].sex)
		{
			++quatity1;
			aver_height1 += students[i].height;
			aver_weight1 += students[i].weight;
		}

		else if ('m' == students[i].sex)
		{
			++quantity2;
			aver_height2 += students[i].height;
			aver_weight2 += students[i].weight;
		}
	}

	if ( quatity1 != 0 )
	{
		aver_height1 /= quatity1;
		aver_weight1 /= quatity1;
		printf("\nAverage female height and weight respectively: %0.2lf, %0.2lf\n", aver_height1, aver_weight1);
	}

	else
	{
		printf("\nSorry, there is no womens for evaluating average height and weight.\n");
	}

	if (quantity2 != 0)
	{
		aver_height2 /= quantity2;
		aver_weight2 /= quantity2;
		printf("\nAverage male height and weight respectively: %0.2lf, %0.2lf\n", aver_height2, aver_weight2);
	}

	else
	{
		printf("\nSorry, there is no mans for evaluating average height and weight.\n");
	}
	
	return SUCCESS;
}
