#include <iostream>
#include <string>
#include <cstring>
#include<cmath>
#include<unordered_map>
using namespace std;
/*
1st Problem:

Write and run a C program with that
Declare at least 2 strings
Prompts the user to enter the strings
Converts the two strings to upper case then print the result,
Copy the first string into a third string,
Concatenate the second string with the third string then print the result,
Calculate the length of the result of the pervious step and print the result
*/

void enterStrings(string& userInput) {
	cout << "Please enter a string: \n";
	getline(cin, userInput);
}
void convertToUpperCase(string& s) {
	for (int i = 0; i < s.size();i++) {
		s[i] = (char)toupper(s[i]);
	}
}
void callFirstSolution() {
	string S1, S2, S3, ConS;
	enterStrings(S1);
	enterStrings(S2);

	convertToUpperCase(S1);
	convertToUpperCase(S2);
	cout << "Upper Case : " << S1 << "\n";
	cout << "Upper Case : " << S2 << "\n";

	S3 = S1;
	ConS = S3.append(S2);
	cout << "After Concatenation : " << ConS << "\n";
	cout << "Length of concatenation result: " << ConS.size() << "\n";
}
/*Main Call : callFirstSolution();*/
/*********************************************************************/
/*
2nd Problem:
Write a program with the folowing functions:

A university uses 15 digits for student IDs :
		d1	d2	d3	d4	d5	d6	d7	d8	d9	d10		d11		d12		d13		d14		d15
		 9		7		8		0		1		3		2		1		3		0			8			0			0			0			6

The last digit d15 is a checksum, which is calculated from the other digits using the following formula:
10 - (d1 + 3d2 + d3 + 3d4 + d5 + 3d6 + d7 + 3d8 + d9 + 3d10 + d11 + 3d12+d13+3d14)%10 . If the checksum is 10, replace it with 0.

1.  Write a function named readString  that takes only an array of character as parameter named data,  reads a string of size 15 from the user, and store it in the array data.
	 The function should ask the user to enter a proper string until the user enters a string of size 15.
2.  Write a function named checkSum that takes only an array of character as parameter and calculates and returns the check sum from the first 14 digits
3.  Write the main function that
		•	 Define an array of character of proper size to store a string of 15 characters
		•	 Properly call the function readString  to read a  15-digit student ID
		•	 Displays valid student ID  if digit 15 equals the checksum calculated in part2 or invalid otherwise
*/
int handleMod(int op1, int op2) {
	return (op1 % op2 + op2) % op2;
}
int checkSum(char d[]) {
	int CS = 10 - ((d[0] - '0') + 3 * (d[1] - '0') + (d[2] - '0') + 3 * (d[3] - '0') + (d[4] - '0') + 3 * (d[5] - '0') + (d[6] - '0') + 3 * (d[7] - '0') + (d[8] - '0') + 3 * (d[9] - '0') + (d[10] - '0') +
		3 * (d[11] - '0') + (d[12] - '0') + 3 * (d[13] - '0'));

	CS = handleMod(CS, 10);
	CS = (CS == 10 ? 0 : CS);
	return CS;
}

void copyStringToArray(char data[], string str) {
	for (int i = 0;i < str.size();i++) {
		data[i] = str[i];
	}
}
void readStringInArray(char data[], int dataSize) {
	string userInput = "";
	do {
		cout << "Please enter the student ID with 15 digits : \n";
		cin >> userInput;
	} while (userInput.size() != dataSize);

	copyStringToArray(data, userInput.c_str());
}
bool IsValidID(char data[], int dataSize) {
	int CS = checkSum(data);
	cout << "CS : " << CS << "  \nLast Element : " << data[dataSize - 1] << "\n";
	return CS == data[dataSize - 1] - '0';
}
void printValidityTest(char data[], int dataSize) {
	if (IsValidID(data, dataSize))
		cout << "Valid ID \n";
	else
		cout << "Invalid ID\n";
}
void callSecondSolution() {
	const int dataSize = 15;
	char data[dataSize];
	readStringInArray(data, dataSize);
	printValidityTest(data, dataSize);
}
/*Main Call :  callSecondSolution();*/
/*********************************************************************/
/*
3rd Problem:
Let us call a 2-dimensional array of integers a Magic matrix  if the following conditions are true:
		The first row has no duplicate values.
		All values in the first row of the array appears in each column of the array.

Write a program with the following functions
	-Define and implement a  a function named randArray that receives two parameters: a 6 column - 2-dimensional array of integers, and the number of rows in the array.
		The function should fill the array with random integer values in the range  -43 to 57 (inclusive)
	-Define and implement a function named printArray that receives two parameters: a 6 column- 2-dimensional array of integers, and the number of rows in the array.
		The function should print the content of the array in a tabular format row by row
	 -Define and implement a function named isMagic, that takes two parameters: a 6-column-2-dimensional array of integers, and the number of rows in the array.
		The function should return 1 if the array is a Magic matrix according to the above rules , and 0 otherwise.

	 -Implement the main function that performs the following:
	   Defines an  integer 2D arrays  a1 of size 10 X 6
	   Uses the function randArray defined above to randomly initialize the array a1.
	   Uses the function printArray to print the array a1 after initialization
	   Properly calls the function isMagic to determine if the array is a magic matrix or not and prints the returned value.
*/
int const rows = 4, cols = 4;

bool hasNoDuplicateInFirstRow(int arr[rows][cols]) {
	unordered_map<int, int> noDuplicateElements;
	for (int j = 0;j < cols;j++) {
		if (noDuplicateElements[arr[0][j]] == arr[j][0]) return false;
		noDuplicateElements[arr[0][j]] = arr[0][j];
	}
	return true;
}
bool allColsHasFirstRowElements(int arr[rows][cols]) {
	//first row elements one by one pass to cols but i <> current Col
	//arr[0][0] >> isFound in arr[1][i] && in arr[2][i]....
	bool result = true;
	unordered_map<int, int> firstRowElementsWithCols;

	//1 >> 3 , 2>> 3,3>>3,4>>3 found in all columns mean the 3 will be 0
	for (int j = 0; j < cols;j++) {
		firstRowElementsWithCols[arr[0][j]] = cols - 1;
	}
	for (int i = 1;i < rows;i++) {
		for (int j = 0; j < cols; j++) {
			if (firstRowElementsWithCols[arr[i][j]] == 0)
				continue;
			firstRowElementsWithCols[arr[i][j]]--;
		}
	}
	for (int j = 0; j < cols;j++) {
		if (firstRowElementsWithCols[arr[0][j]] > 0) {
			result = false;
			break;
		}
	}
	return result;
}
bool isMagic(int arr[rows][cols]) {
	if (hasNoDuplicateInFirstRow(arr)) {
		if (allColsHasFirstRowElements(arr))
			return true;
		else
			return false;
	}
	else
		return false;
}
void randArray(int arr[rows][cols], int fromRand, int toRand) {
	int steps = toRand - fromRand;
	for (int i = 0;i < rows;i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = (rand() % steps) + (fromRand);
		}
	}
}
void printArray(int arr[rows][cols]) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << "	";
		}
		cout << "\n";
	}
}
void callThirdSolution() {
	srand((unsigned)time(0));
	int arr[rows][cols];
	randArray(arr, -43, 57);
	/*arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[0][3] = 4;

	arr[1][0] = 2;
	arr[1][1] = 1;
	arr[1][2] = 4;
	arr[1][3] = 3;

	arr[2][0] = 3;
	arr[2][1] = 4;
	arr[2][2] = 2;
	arr[2][3] = 1;

	arr[3][0] = 4;
	arr[3][1] = 3;
	arr[3][2] = 1;
	arr[3][3] = 2;*/

	printArray(arr);
	if (isMagic(arr))
		cout << "Magic Array !! \n";
	else
		cout << "Not Magic Array !! \n";

}
/*Main Call :  callThirdSolution();*/
/*********************************************************************/
