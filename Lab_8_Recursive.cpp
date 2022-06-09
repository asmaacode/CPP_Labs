#include <iostream>
#include <string>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	1st Problem :
		Write a  recursive function with name sumDigits takes an integer parameter and returns the sum of its digits.
		Write a  program asks the user to input the number, then call the function sumDigits and prints the result.
*/
int numofDigits(int number) {
	int digits = 0;
	while (number != 0) {
		number /= 10;
		digits++;
	}
	return digits;
}
double sumDigits(int number ,int digits){
	if (number != 0)
		return (int(number / pow(10, digits))) + sumDigits((number - ((int (number / pow(10, digits))) * pow(10, digits))), digits - 1);

	return 0;
}
double sumDigits_UsingLoop(int number){
	int digits = numofDigits(number),currentDigit;
	digits--;
	double sum = 0;
	while (number != 0) {
		currentDigit = number / pow(10, digits);
		number = (number - (currentDigit * pow(10, digits)));
		digits--;
		sum += currentDigit;
	}
	return sum;
}
int readNumber(string message) {
	cout << message << endl;
	int userNumber = 0;
	while (!(cin >> userNumber))
	{
		// Explain error
		cout << "ERROR: A Number must be entered:\n";
		cin.clear();
		cin.ignore(132, '\n');
	}
	return  userNumber;
}
void callFirstSolution() {
	int number = readNumber("Please enter the number to calculate the sum of digits : \n");
	cout << sumDigits(number, numofDigits(number) - 1);
}
/*Main Call : 	callFirstSolution()*/

/*********************************************************************/

/*
	2nd Problem :
		Write a  recursive function with name countVowels that takes a string as an array of characters and returns the number of vowels in the string.
		Write a  program asks the user to input a string then call the function countVowels and prints the result.
*/
bool isLowerCase(char theLetter) {
	return toascii(theLetter) >= 97 && toascii(theLetter) <= 122;
}
bool isVowel(char theLetter) {
	int counter = 0;
	if (isLowerCase(theLetter)) {
		char lowerCaseVowels[5] = { 'a','e','o','i','u' };
		while (counter < 5) {
			if (lowerCaseVowels[counter] == theLetter)
				return true;
			counter++;
		}
	}
	else
	{
		char upperCaseVowels[5] = { 'A','E','O','I','U' };
		while (counter < 5) {
			if (upperCaseVowels[counter] == theLetter)
				return true;
			counter++;
		}

	}
	return false;
}
int currentIndex = 0;
int countVowels(string userInput) {
	if(userInput.size() != 0){
		if (isVowel(userInput[currentIndex])) {
			return 1 + countVowels(userInput.substr(currentIndex + 1, userInput.size() - 1));
		}
		else {
			return countVowels(userInput.substr(currentIndex + 1, userInput.size() - 1));
		}
	}
	return 0;
}
int countVowels_UsingLoop(string userInput) {
	int sum = 0;
	for ( char letter : userInput) {
		if (isVowel(letter)){
			sum++;
		}
	}
	return sum;
}
string readString() {
	string userInput = "";
	cout << "Please enter a string to count the Vowels :\n";
	while (!(cin >> userInput))
	{
		// Explain error
		cout << "ERROR: A string must be entered:\n";
		cin.clear();
		cin.ignore(132, '\n');
	}
	return  userInput;
}
void callSecondSolution() {
	cout <<"You have (" << countVowels(readString()) << ") Vowels." << endl;
}
/*Main Call : 
	callSecondSolution();
*/
/*********************************************************************/

/*
	3rd Problem :
		A cell type might split into two or three every hour, or might die.  
		The likelihood for splitting into two is 30% and into three is 55% and dying is 15% for every lifespan.
		
		Assume that we start with a sample of one cell:

			Write a recursive function called int cell (int total_hours) the function receives the number of hours as a parameter,
			this function calculates and return the total number of cells after a number of hours, the function should stop when the total_hours left is 0 or less.

			Use (rand ()) to simulate the percentage which this random percentage should be in one of these ranges (0-15 or 16-30 or 31-55),
			this percentage will indicate how many times the cell will split in each hour.

			Write the main function that prompts the user to enter the number of hours and pass the number of hours to the recursive function cell(hours).
			Then print the result returned by the recursive function as shown in the sample output

*/

int calculateTotalCells(int total_hours){
	if (total_hours > 0) {
		if((rand() % 55) <= 15)
			return  calculateTotalCells(total_hours - 1);
		else
		if ((rand() % 55) <= 30)
			return  2 + calculateTotalCells(total_hours - 1);
		else
		if ((rand() % 55) <= 55)
			return  3 + calculateTotalCells(total_hours - 1);
	}
	else {
		return 0;
	}
}

void callThirdSolution() {
	cout<<"The number of cells : "<<calculateTotalCells(readNumber("Please enter the total of hours : \n")) << endl;
}

/*Main Call : 	
	srand(time(NULL));
	callThirdSolution();
*/
/*********************************************************************/
