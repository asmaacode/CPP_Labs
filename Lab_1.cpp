/*
Problem Description :
The vaccine of Covid-19 can be shipped in large or small containers. 
Larger containers can hold up to 100 vaccine bottles whereas small containers can hold up to 48 vaccine bottles.
• Develop and run a C program that performs the following that reads the number of the vaccine bottles to be shipped then calculates 
and prints the minimum number of containers needed to ship them all
 Note : the large container can only be used if filled 100%
for example: if you have 250 vaccine bottles then you need 2 Large containers and 2 Small containers 
 Submit your program as a c-file (a file with .c extension )
*/

#include<iostream>
#include<string>
using namespace std;
int bottlesNumber = 0;
enum containersSizes { Large = 100, Small = 48 };

int readBottlesNumber() {
	cout << "Please enter the number of bottels \n";
	cin >> ::bottlesNumber;
	return ::bottlesNumber;
}

int calculateLargeContainers() {
	int largeContainers = ::bottlesNumber / containersSizes::Large;
	::bottlesNumber = ::bottlesNumber - (largeContainers * containersSizes::Large);
	return largeContainers;
}

int calculateSmallContainers() {
	return  ceil(float(::bottlesNumber) / float(containersSizes::Small));
}

int main() {
	readBottlesNumber();
	cout << calculateLargeContainers() << " Large ";
	cout << calculateSmallContainers() << " Small  " << endl;
	return 0;
}