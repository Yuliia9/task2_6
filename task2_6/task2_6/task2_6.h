#include "stdafx.h"

/*maximum length of surname and initials of student*/
const int LEN = 30;

struct student
{
	char name[LEN];
	int age;
	char sex;
	double height;
	double weight;
};

/*displays some general information about program*/
void Interface();

/*checking entered data and return 0 if type doesn't match requirements*/
unsigned char Type_checking(unsigned char retCode, int val);

/*input information about students into list of students and return 0 if some data doesn't match requirements*/
unsigned char  Input(struct student* students, unsigned int num);

/*checking if string pstr involves only digits*/
unsigned char Is_digit(const char* pstr);

/*displayed table of information about students*/
unsigned char Output(const struct student* students, unsigned int num);

/*sorted table of information about students by surname*/
unsigned char  Sort_by_surname(struct student* stud_table, unsigned int n);

/*evaluate and display the average height and weight separate for female and male*/
unsigned char Average(const struct student* students, unsigned int num);
