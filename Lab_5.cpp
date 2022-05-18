#include <iostream>
using namespace std;

/*
1st Problem

Write a program that performs the following:
-	Defines an array named numbers of size 10 using an initializer list. 
	The array contains the following values: {45, 7, 78, 11, 60, 10, 23, 85, 40, 63}
-	Asks the user to input an integer in the range [2-5], and if it is not in the range ask the user to try again.
-	Searches the array for numbers divisible by the number inserted by the user and prints them along with the count of the numbers and sum.
*/
const int arraySize = 10;
int readIntegerNumberInRange(int From, int To) {
	int userInput = 0;
	do {
		cout << "Please enter the number between " << From << " and " << To << "\n";
		cin >> userInput;
	} while (userInput > To || userInput < From);
	
	return userInput;
}
void searchForDivisibleNumbers(int divisibleNumbers[],int targetNumber) {
	int mainArray[arraySize] = { 45, 7, 78, 11, 60, 10, 23, 85, 40, 63 };
	for (int i = 0; i < arraySize;i++) {
		if (mainArray[i] % targetNumber == 0) {
			divisibleNumbers[i] = mainArray[i];
		}
		else {
			divisibleNumbers[i] = -1;
		}
	}
}
void printDivisibleNumbersWithCountAndSum(int divisibleNumbers[], int targetNumber) {
	int count = 0, sum = 0;
	cout << "The numbers from the array divisible by " << targetNumber << "  are: ";
	for (int i = 0; i < arraySize;i++) {
		if (divisibleNumbers[i] != -1) {
			cout << divisibleNumbers[i] << "  ";
			count++;
			sum += divisibleNumbers[i];
		}
	}
	cout << "\nThere are " << count << " numbers divisible by " << targetNumber<<"\n";
	cout << "The sum of these numbers is:  " << sum <<"\n";
}
void callFirstSolution() {
	int divisibleNumbers[arraySize] = {0};
	int userInput = readIntegerNumberInRange(2, 5);
	searchForDivisibleNumbers(divisibleNumbers, userInput);
	printDivisibleNumbersWithCountAndSum(divisibleNumbers, userInput);
}
//Main Call : callFirstSolution();
/***********************************************************/
/*
2nd Problem:
	Write a program that performs the following:
	•	Define two 1D-arrays that represent the ID and GPA of 5 students. 
		The first 1D-array is an array of integer name “ID”, and the second 1D-array is an array of float named “GPA”, both of size 5.
	•	Prompt the user to input the ID and grade for each student.
	•	Print student ID and GPA in a tabular format as shown the sample output.
	•	Compute and print the average of GPA’s for all students.
	Sample Output :

		StudentID       GPA
		--------------------
		   202101       93.7
		   202102       89.4
		   202103       74.1
		   202104       98.3
		   202105       69.8
		--------------------
		The average of GPA's is: 85.1

*/
void readTheStudentsInfo(int ID[], float GPA[],int studentNumber) {
	for (int i = 0;i< studentNumber;i++) {
		cout << "What is your ID ?   ";
		cin >> ID[i];
		cout << "What is your GPA ?   ";
		cin >> GPA[i];
		cout << "\n" ;
	}
}
void printStudentsInfoAsTabular(int ID[], float GPA[], int studentNumber) {
	cout << "StudentID		" << "GPA\n";
	cout << "------------------------------------------\n";
	for (int i = 0;i < studentNumber;i++) {
		cout << ID[i] << "				" <<GPA[i] << "\n";
	}
	cout << "------------------------------------------\n";
}
void calculateAndPrintTheClassAverage(float GPA[], int studentNumber) {
	float sum = 0.0;
	for (int i = 0;i < studentNumber;i++) {
		sum += GPA[i];
	}
	cout << "The average of GPA's is: " <<sum / (studentNumber*1.0)<< endl;
}
void callSecondSolution() {
	int const studentsNumber = 5;
	int ID[studentsNumber] = { 0 };
	float GPA[studentsNumber] = { 0.0 };
	readTheStudentsInfo(ID, GPA, studentsNumber);
	printStudentsInfoAsTabular(ID, GPA, studentsNumber);
	calculateAndPrintTheClassAverage(GPA, studentsNumber);
}
//Main Call : callSecondSolution();
/***********************************************************/
/*
3rd Problem:
Write a program that performs the following:
	Asks the user to enter a letter (lowercase or uppercase).
	Prints the letters between the entered letter and z or Z with even ASCII codes.
	Prints beside each letter “A vowel” if the letter is a vowel, and nothing beside the other letters.
	Prints the alphabets, that their ASCII is divisible by 2, beginning from ‘a’ until ‘z’.(Using continue)
*/
void printEvenASCII_LowerLettersRange() {
	cout << "The even ASCII lower case letters :\n";
	for (int i = toascii('a'); i <= toascii('z');i++) {
		if (i % 2 != 0)continue;
		cout << char(i) << "		";
	}
}
char enterTheLetter() {
	char userInput;
	int ascii;
	do {
		cout << "Give me any letter : \n";
		cin >> userInput;
		ascii = toascii(userInput);
	} while (ascii > 122 || ascii< 65 || (ascii< 97 && ascii > 90));
	return userInput;
}

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

void printTheLetterInRange(char theLetter) {
	int toLetter = toascii('Z');
	if (isLowerCase(theLetter)) {
		toLetter=toascii('z');
	}
	int currentLetter = toascii(theLetter);
	while (currentLetter <= toLetter) {
		if(isVowel(char(currentLetter)))
		cout << char(currentLetter) << "-------Is Vowel\n";
		else
			cout << char(currentLetter)<<"\n";

		currentLetter++;
	}
}
void callThirdSolution() {
	printTheLetterInRange(enterTheLetter());
	cout << "-----------------------------------\n";
	printEvenASCII_LowerLettersRange();
}
//Main Call : callThirdSolution();
/***********************************************************/
