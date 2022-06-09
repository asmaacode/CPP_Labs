#include <iostream>
using namespace std;

/*
1st Problem:

Write a program that prints the integers from 55 to 130 (inclusive).
Exclude the odd numbers in range 100 to 120.
The value of the numbers should be printed one value per line.
*/
void printIntegersInRange(int fromNumber, int toNumber) {
	for (int i = fromNumber;i <= toNumber;i++) {
		cout << i << "\n";
	}
}
void printEvenIntegersInRange(int fromNumber, int toNumber) {
	for (int i = fromNumber;i <= toNumber;i++) {
		if (i % 2 == 0)
			cout << i << "\n";
	}
}
void callTheSolution() {
	printIntegersInRange(55, 100);
	printEvenIntegersInRange(101, 120);
	printIntegersInRange(121, 130);
}
//Main Call : callTheSolution();
/**************************************************/
/*
2nd Problem:
	Develop and run a program that performs the following:
	Declare an array of integers of size 10 named largeNum
	Declare an array of character of size 15 named str
	Ask the user to enter a string of 10 digits
	Using  a single statement, read in a single string of 10 digits (such as 9432786461)
	Store the corresponding digits in the array largeNum
	Prints the :
	The sum of the  individual digits
	The average of individual digits (as floating point)
	The result of multiplying individual digits
	The result of subtracting the least significant digit from the most significant digit

Sample:
		Enter a string of 10 digits
		9753128604
		The sum of the  individual digits: 45
		The average of individual digits (as floating point): 4.500000
		The result of multiplying individual digits: 0
		The result of subtracting the least significant digit from the least significant digit is 5
*/

string enterStringofNumbers() {
	string numbers = "";
	cout << "Please enter a number with 10 digits :\n";
	cin >> numbers;
	return numbers;
}
void convertStringofNumbersToArray(string input, int numbers[], int arr_size) {
	for (int i = 0; i < arr_size;i++) {
		numbers[i] = (int)input[i] - (int)'0';
	}
}
int sumofNumbersArray(int numbers[], int arr_size) {
	int summation = 0;
	for (int i = 0; i < arr_size; i++) {
		summation += numbers[i];
	}
	return summation;
}
int multiplyofNumbersArray(int numbers[], int arr_size) {
	int multi = 1;
	for (int i = 0; i < arr_size; i++) {
		multi *= numbers[i];
		if (multi == 0) return 0;
	}
	return multi;
}
int subLeastFromMostElement(int numbers[], int arr_size) {
	return numbers[arr_size - 1] - numbers[0];
}
double findAverageofNumbersArray(int sum, int arr_size) {
	return sum * 1.0 / arr_size * 1.0;
}
void maniplulateWithArray() {
	const int array_size = 10;
	int largeNum[array_size];
	string numbers = enterStringofNumbers();
	convertStringofNumbersToArray(numbers, largeNum, array_size);

	int sum = sumofNumbersArray(largeNum, array_size);
	cout << "The summation of the digits : " << sum << "\n";
	cout << "The average of the digits : " << findAverageofNumbersArray(sum, array_size) << "\n";
	cout << "The multiplying of the digits : " << multiplyofNumbersArray(largeNum, array_size) << "\n";
	cout << "The subtracting of least significant from the most one is : " << subLeastFromMostElement(largeNum, array_size) << endl;

}
//Main Call : maniplulateWithArray();
/**************************************************/
/*
3rd Problem:
- Use for loop to solve this exercise
Write a program that reads an integer N that represents the number of students in a class
followed by N floating point numbers (one float on a line) representing students grades.
The program then computes and prints the following:
	The maximum grade in the class.
	The average (arithmetic mean) grade  for all student in the class
	The number of students whose grade is larger than the average
	If more than 20% of the students have grades less than 50, the program prints: “Too many low  grades”.

Note: N is less than 100

*/
float sumofGrades(float numbers[], int arr_size) {
	float summation = 0.0;
	for (int i = 0; i < arr_size; i++) {
		summation += numbers[i];
	}
	return summation;
}
double findGradesAverage(double sum, int arr_size) {
	return sum * 1.0 / arr_size * 1.0;
}
int enterStudentsNumber() {
	int studentsNumber = 0;
	do {
		cout << "Please enter the number of the students (less than 100): \n";
		cin >> studentsNumber;
	} while (studentsNumber > 100);
	return studentsNumber;
}
void enterStudentsGrades(float studentsGradesArr[], int studentsNumber) {
	for (int i = 0; i < studentsNumber;i++) {
		cout << "Grade (" << i+1 << ") : ";
		cin >> studentsGradesArr[i];
		cout << "\n";
	}
}
float findTheMaximumGrade(float studentsGradesArr[], int studentsNumber) {
	float max = studentsGradesArr[0];
	for (int i = 1;i < studentsNumber;i++) {
		if (studentsGradesArr[i] > max) max = studentsGradesArr[i];
	}
	return max;
}
int countMoreThanAverage(float studentsGradesArr[], int studentsNumber, float average) {
	int count = 0;
	for (int i = 0;i < studentsNumber;i++) {
		if (studentsGradesArr[i] > average) count++;
	}
	return count;
}
int countofFaildStudents(float studentsGradesArr[], int studentsNumber, float failMark) {
	int count = 0;
	for (int i = 0;i < studentsNumber;i++) {
		if (studentsGradesArr[i] < failMark) count++;
	}
	return count;
}
bool isTooManyLowGrades(int countLessThanAverage, int studentsNumber, float lowestGradePercentage) {
	return (countLessThanAverage * 1.0 / studentsNumber * 1.0) > lowestGradePercentage ? true : false;
}
void runTheGradesProgram() {
	float studentsGradesArr[100];
	int studentsNumber = enterStudentsNumber();
	enterStudentsGrades(studentsGradesArr, studentsNumber);
	float maximumGrade = findTheMaximumGrade(studentsGradesArr, studentsNumber);
	cout << "The maximum grade in this class : " << maximumGrade << "\n";
	float gradesSum = sumofGrades(studentsGradesArr, studentsNumber);
	float gradesAverage = findGradesAverage(gradesSum, studentsNumber);
	cout << "The average of grades in this class :" << gradesAverage << "\n";
	int moreThanAverage = countMoreThanAverage(studentsGradesArr, studentsNumber, gradesAverage);
	cout << "The count of students more than average :" << moreThanAverage << "\n";
	int faildStudents = countofFaildStudents(studentsGradesArr, studentsNumber, 50.0);
	cout << "Faild Students : " << faildStudents << "\n";
	float lowestGradePercentage = 0.2;
	if (isTooManyLowGrades(faildStudents, studentsNumber, lowestGradePercentage))
		cout << "Too many low  grades";
	cout << endl;
}
/*Main Call : runTheGradesProgram();*/
