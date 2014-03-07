/**
* @file		task2_6.h
* @brief	header file for task2_6.cpp
defines data types and prototypes for functions used in task2_6.cpp
*/

#include "stdafx.h"


const int LEN = 30;	/*maximum length of student's surname and initials*/

/*defines data type for holding student's surname, age, sex, height and weight */
struct student
{
	char name[LEN];
	int age;
	char sex;
	double height;
	double weight;
};


/**
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface();



/**
* @brief						Checking if data match requirements set to that data types or functions return values

* @param	[in]				unsigned char retCode - return value of other functions for checking if functions ended properly
			[in]				int val - number for checking if it's negative or zero
* @return	unsigned char		Return ERROR if data doesn't match requirements
								Return SUCCESS if inputed data match requirements
*/
unsigned char Type_checking(unsigned char retCode, int val);



/**
* @brief					Function for input information about students medical examination
* @param	[in/out]		struct student* students - pointer to array of structures 
							that holds information about students medical examination

			[in]			unsigned int num - the number of students in created database
*
* @return	unsigned char	Return ERROR if pointer to array of structure is NULL
							Return SUCCESS if data was inputed
*/
unsigned char  Input(struct student* students, unsigned int num);



/**
* @brief					Function for checking if inputed string involves only digits
* @param	[in]			const char* pstr - pointer to, checking for numbers, string
*
* @return	unsigned char	Return ERROR if string contains not only numbers
							Return SUCCESS if string contains only numbers
*/
unsigned char Is_digit(const char* pstr);


/**
* @brief					Function sorts list of students by their surnames
* @param	[in/out]		struct student* students - pointer to array of structures that holds information about students
			[in]			unsigned int n - the number of students in created  database
* @return	unsigned char	Return ERROR if pointer to array of structures students is NULL
							Return SUCCESS if list was sorted
*/
unsigned char  Sort_by_surname(struct student* students, unsigned int n);



/**
* @brief					Function estimates student's average height and weight separate for males and females
* @param	[in]			const struct student* students - pointer to array of structures that holds information about students
			[in]			unsigned int num - the number of students in created  database
* @return	unsigned char	Return ERROR if pointer to array of structures students is NULL
							Return SUCCESS if average height and weight were estimated and displayed
*/
unsigned char Average(const struct student* students, unsigned int num);



/**
* @brief					Function for displaying information about students and their medical examination
* @param	[in]			const struct student* students - pointer to array of structures that holds information about students
			[in]			unsigned int num - the number of students stored in created database
*
* @return	unsigned char	Return ERROR if pointer to array of structures is NULL
							Return SUCCESS if data was displayed
*/
unsigned char Output(const struct student* students, unsigned int num);





