/*
Problem Description:
	In English, capital  vowel letters are (A,E,I, O, and U) and small vowel letters are (a,e,i, o, and u)
	Write a C program that prompts the user to enter a single character and prints vowel If the number is a vowel and NOT vowel otherwise
*/

#include<iostream>
#include<string>

using namespace std;

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

int main()
{
	testLetterType(readUserLetter());
	return 0;
}