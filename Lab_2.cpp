#include<iostream>
#include<string>
using namespace std;
/*
1st Problem:
In mathematics, the absolute value a number x, denoted |x|, is the non-negative value of x without regard to its sign.
Namely, |x| = x if x is positive, and |x| = −x if x is negative (in which case −x is positive), and |0| = 0.
Write a C program that asks to enter an integer and prints its absolute value.
*/
int readUserNumber() {
	int userNumber = 0;
	cout << "Please enter the number : \n";
	cin >> userNumber;
	return userNumber;
}

int absoluteNumber(int number) {
	return (number >= 0 ? number : number * -1);
}
//main call : cout << absoluteNumber(readUserNumber())<<endl;
//----------------------------------------------------------------------------//
/*
2nd Problem:
Write a C program that prompts the user to enter a character, and prints “ODD” if the ASCII code of the character is odd or “EVEN” otherwise.
*/
string checkASCIIOddEven(char theLetter) {
	if (toascii(theLetter) % 2 == 0) {
		return "Even";
	}
	return "Odd";
}
//main call : cout << checkASCIIOddEven(readUserLetter()) << endl;
//----------------------------------------------------------------------------//
/*
3rd Problem:
	An Electricity provider charges personal and business customers as follows:
	Personal:  The monthly fee for the plan is 5.00 JD. The cost for each consumed unit (kW) is  0.03 JD
	Business:  The monthly fee for the plan is 10.00 JD. The cost for each consumed unit (kW) is  0.07 JD.
	Write a C program that prompts the user to enter one of the two  letters (B- Business or P-  Personal) and the number of consumed units, then calculates and prints the total of the bill
*/
double PersonalConsumedPerc = 0.03, PersonalMonthlyPlan = 5, BusinessConsumedPerc = 0.07, BusinessMonthlyPlan = 10;
void drawCustomersTypesMenu() {
	cout << "***************************************************\n";
	cout << "Customer Types : \n";
	cout << "-P Personal \n";
	cout << "-B Business\n";
	cout << "***************************************************\n";
	cout << "Please choose from the menu : \n";
}

char readCustomerType(char& customerType) {
	cin >> customerType;
	return customerType;
}
double  readCustomingAmount() {
	double consumingAmount = 0;
	cout << "Please enter the consuming amount : \n";
	cin >> consumingAmount;
	return consumingAmount;
}
double calculatePersonalConsuming(double consumingAmount) {
	return (consumingAmount * PersonalConsumedPerc) + PersonalMonthlyPlan;
}

double calculateBusinessConsuming(double consumingAmount) {
	return (consumingAmount * BusinessConsumedPerc) + BusinessMonthlyPlan;
}
void calculateConsuming(char customerType, double consumingAmount) {
	switch (customerType) {
	case('P'):
		cout << calculatePersonalConsuming(consumingAmount) << endl;
		break;
	case('B'):
		cout << calculateBusinessConsuming(consumingAmount) << endl;
		break;
	deafult:
		cout << "Cannot find the entered type !! \n";
	}
}
/*
Main Call:
	char customerType = 'P';
	drawCustomersTypesMenu();
	readCustomerType(customerType);
	calculateConsuming(customerType, readCustomingAmount());
*/
//----------------------------------------------------------------------------//
/*
4th Problem:
	In English, capital  vowel letters are (A,E,I, O, and U) and small vowel letters are (a,e,i, o, and u)
	Write a C program that prompts the user to enter a single character and prints vowel If the letter is a vowel or NOT vowel
*/

char vowels[] = { 'A', 'O', 'U', 'W', 'E', 'I','a','o','u','w','e','i' };
char readUserLetter() {
	char userLetter = '0';
	cout << "Please enter the letter you want to check \n";
	cin >> userLetter;
	return userLetter;
}
bool isVowelLetter(char letter) {
	for (int i = 0;i < sizeof(::vowels) - 1;i++) {
		if (::vowels[i] == letter)
			return true;
	}
	return false;
}
void testLetterType(char letter) {
	if (isVowelLetter(letter)) {
		cout << "Vowel" << endl;
	}
	else {
		cout << "Not A Vowel" << endl;
	}
}
//main call : 	testLetterType(readUserLetter());
//----------------------------------------------------------------------------//
