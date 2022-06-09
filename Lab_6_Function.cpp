#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;


/*
1st Problem :
	Write a program that simulates drawing a number card from a 52 cards:
	-	Write a prototype for a function called showCard that takes one unsigned integer argument and doesn’t return anything
	-	Write a function definition showCard  after the main function that takes one unsigned integer argument and returns nothing and prints the corresponding card to that number
		Assume that the cards are sorted A, 2 , 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K for the spades suite first, then Hearts, then Clubs, then Diamonds.
		Hint: use the mod of 13 to find the card and divide by 13 to find the suite
		For example
		if the user enters the integer 0, the function should print: A of Spades
		If the user enters 12 it should print: K of Spades
		If the user enters 15 it should print: 3 of Hearts
		If the user enters 31 it should print: 6 of Clubs
	-	Write the main function that prompts the user to enter a positive number
	-	Calls the showCard function passing the number the user entered
	-	Adjust your code, remove the user prompt to enter a number in the main function
	-	In the main function write the code that will randomly provide 5 numbers
	-	Each time you randomly generate a number, call the showCard function to print the corresponding card to that random number,
		this would simulate randomly drawing five cards from a deck of 52 cards.
*/
int readNumber() {
	int userNumber = 0;
	while (!(cin >> userNumber))
	{
		// Explain error
		cout << "ERROR: a number must be entered:";
		cin.clear();
		cin.ignore(132, '\n');
	}
	return  userNumber;
}
bool isValidNumber(int theNumber) {
	return theNumber > 0;
}
int readPositiveNumber() {
	int positiveNumber = 0;
	do {
		cout << "Please enter a number greater than zero :\n";
		positiveNumber = readNumber();
	} while (!isValidNumber(positiveNumber));

	return positiveNumber;
}
void showCard(unsigned int card);
void showCard(unsigned int card) {
	char cards[52] = { 'A', '2' , '3', '4', '5', '6', '7', '8', '9', '10','J', 'Q', 'K' };
	unsigned int realCard = card;
	int whichSuite;
	do {
		whichSuite = card % 13;
	} while (whichSuite >= 4);

	realCard = realCard % 13;
	string suite = "";

	switch (whichSuite)
	{
	case 0:
		suite = "Spades";
		break;
	case 1:
		suite = "Hearts";
		break;
	case 2:
		suite = "Clubs";
		break;
	case 3:
		suite = "Diamonds";
		break;
	default:
		break;
	}
	cout << cards[realCard] << " " << suite;
}
/*
Main Call :
	srand((unsigned)time(0));
	unsigned int num = rand();
	cout << "The Number " << num << endl;
	showCard(num);
*/

/****************************************************************/
/*
A calculator
*/
double add(double op1, double op2) {
	return op1 + op2;
}
double sub(double op1, double op2) {
	return op2 - op1;
}
double divide(double op1, double op2) {
	return op2 / op1;
}
double multiply(double op1, double op2) {
	return op1 * op2;
}
double sqroot(double op1) {
	return sqrt(op1);
}
double power(double op1, double op2) {
	return pow(op2, op1);
}
double sine(double op1) {
	return sin(op1);
}
double cosin(double op1) {
	return cos(op1);
}
void drawTheCalculatorMenu() {
	cout << "Choose from the menu :\n";
	cout << "1 : to add\n";
	cout << "2 : to subtract\n";
	cout << "3 : to divide\n";
	cout << "4 : to multiply\n";
	cout << "5 : to square root\n";
	cout << "6 : to power\n";
	cout << "7 : to sin\n";
	cout << "8 : to cosin\n";
	cout << "-1 : to exit\n";

}
int enterNumber() {
	int theOperation = 0;
	cin >> theOperation;
	while (!cin.good()){
		cin.ignore();
			cin.clear();
		cin >> theOperation;
	}
	return theOperation;
}
double enterFloatNumber() {
	double theOperation;
	cout << "Enter the operand/s \n";
	cin >> theOperation;

	while (!cin.good()) {
		cin.ignore();
		cin.clear();
		cout << "Enter the operand/s \n";
		cin >> theOperation;
	}
	return theOperation;
}
void calculator() {
	drawTheCalculatorMenu();
	switch (enterNumber())
	{
	case 1:
		cout<<add(enterFloatNumber(), enterFloatNumber());
		break;
	case  2:
		cout<<sub(enterFloatNumber(), enterFloatNumber());
		break;
	case 3:
		cout<<divide(enterFloatNumber(), enterFloatNumber());
		break;
	case 4:
		cout<<multiply(enterFloatNumber(), enterFloatNumber());
		break;
	case 5:
		cout<<sqroot(enterFloatNumber());
		break;
	case 6:
		cout<<power(enterFloatNumber(), enterFloatNumber());
		break;
	case 7:
		cout<<sine(enterFloatNumber());
		break;
	case 8:
		cout<<cosin(enterFloatNumber());
		break;
	default:
		break;
	}
}
/*
Main Call : calculator();
*/
/****************************************************************/
