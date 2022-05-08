#include<iostream>
#include<string>
using namespace std;
int bottlesNumber = 0;
enum containersSizes {Large = 100, Small = 48};

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