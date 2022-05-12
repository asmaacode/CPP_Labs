#include <iostream>
#include <map>
using namespace std;

/*
1st Problem:
	In geometry, the surface area for a cube of side length s can be calculated as Cube Area= 6s^2, whereas the volume of such a cube is calculated asCube Volume = s^3.
	For a sphere of radius r, surface area can be calculated as Sphere Area= 4πr^2 whereas the volume of such a sphere is calculated as
	Sphere Volume = 4/3 πr^3.
	Use 3.14 for π
	Write a C program that
		Prompts the user to select the type of calculation (A for Area and V for Volume)
		Prompts the user to select the shape type (C for cube and S for Sphere)
		If the users selects a Cube, prompts the user to enter the side length of the cube
		If the users selects a Sphere, prompts the user to enter the radius of the sphere
*/
const float pi = 3.14;
enum enShapeTypes { Sphere = 'S', Cube = 'C' };
enum enCalculationTypes { Area = 'A', Volume = 'V' };
double enterSideLength() {
	double SideLength = 0.0;
	cout << "Please enter the side length : \n";
	cin >> SideLength;
	return SideLength;
}
double enterRadiusLength() {
	double RadiusLength = 0.0;
	cout << "Please enter the radius length:\n";
	cin >> RadiusLength;
	return RadiusLength;
}
double calculateSphereArea(double RadiusLength) {
	return 4.0 * pi * pow(RadiusLength, 2);
}
double calculateSphereVolume(double RadiusLength) {
	return (4.0 / 3.0) * pi * pow(RadiusLength, 3);
}
double calculateCubeArea(double SideLength) {
	return 6.0 * pow(SideLength, 2);
}
double calculateCubeVolume(double SideLength) {
	return pow(SideLength, 3);
}
void callSphereCalculation(double CalculationType) {
	double RadiusLength = enterRadiusLength();
	if (CalculationType == enCalculationTypes::Area) cout << "The result is :" << calculateSphereArea(RadiusLength);
	if (CalculationType == enCalculationTypes::Volume) cout << "The result is :" << calculateSphereVolume(RadiusLength);
}
void callCubeCalculation(double CalculationType) {
	double SideLength = enterSideLength();
	if (CalculationType == enCalculationTypes::Area) cout << "The result is :" << calculateCubeArea(SideLength);
	if (CalculationType == enCalculationTypes::Volume) cout << "The result is :" << calculateCubeVolume(SideLength);
}
void drawCalculationTypeMenu() {
	cout << "****************************************\n";
	cout << "What do you want to calculate ?\n";
	cout << "V- Volume \n";
	cout << "A- Area \n";
}
void drawShapeTypeMenu() {
	cout << "************************************\n";
	cout << "Please enter the shape type:\n";
	cout << "C- Cube \n";
	cout << "S- Sphere \n";
}
char enterShapeType() {
	drawShapeTypeMenu();
	char ShapeType = enShapeTypes::Sphere;
	cin >> ShapeType;
	return ShapeType;
}
char enterCalculationType() {
	drawCalculationTypeMenu();
	char CalculationType = enCalculationTypes::Area;
	cin >> CalculationType;
	return CalculationType;
}
void callCalculation() {
	double CalculationType = enterCalculationType();
	char ShapeType = enterShapeType();
	if (ShapeType == enShapeTypes::Sphere) callSphereCalculation(CalculationType);
	if (ShapeType == enShapeTypes::Cube) callCubeCalculation(CalculationType);

}
//Main Call : 	callCalculation();
/*****************************************************************/
/*
 2nd Problem:
	The table below shows the normal boiling points of three metals in °C.
	Note: in mathematics; x is within 5% of y if  0.95*y  ≤ x ≤  1.05*y

	Metals	Normal boiling point (°C)
	Copper	1187
	Silver		2193
	Gold		2660

	Write a program that
	o	Prompts the user to enter the observed boiling point of a metal in °C
	o	Identifies the metal if the observed boiling point is within 5% of the expected boiling point.
	o	If the data input is more than 5% higher or lower than any of the boiling points in the table, the program should output the message Substance unknown.
*/
enum metalNormalBoiling { Copper = 1187, Silver = 2193, Gold = 2660 };
double errorPercentage = 0.05;
double lowerErrorMargin = 1.0 - errorPercentage;
double upperErrorMargin = 1.0 + errorPercentage;

double enterObservedBoilingPoint() {
	cout << "Please enter the observed Boling Point\n";
	double observerdPoint = 0.0;
	cin >> observerdPoint;
	return observerdPoint;
}
bool isCopper(double observedPoint) {
	return observedPoint >= metalNormalBoiling::Copper * lowerErrorMargin && observedPoint <= metalNormalBoiling::Copper * upperErrorMargin;
}
bool isSilver(double observedPoint) {
	return observedPoint >= metalNormalBoiling::Silver * lowerErrorMargin && observedPoint <= metalNormalBoiling::Silver * upperErrorMargin;
}
bool isGold(double observedPoint) {
	return observedPoint >= metalNormalBoiling::Gold * lowerErrorMargin && observedPoint <= metalNormalBoiling::Gold * upperErrorMargin;
}
void identifyTheMetal(double observedPoint) {
	if (isCopper(observedPoint)) {
		cout << "The Metal is Copper\n";
	}
	else if (isSilver(observedPoint))
	{
		cout << "The Metal is Silver\n";
	}
	else if (isGold(observedPoint))
	{
		cout << "The Metal is Gold\n";
	}
	else
	{
		cout << "Substance Unknown";
	}
}

//Main Call: 	identifyTheMetal(enterObservedBoilingPoint());
/***********************************************************************/
/*
3rd Problem
	Write a C code that prompts the user to input students mark (0-100) and displays the mark in words. You should use switch statement to solve this question.

	Example:
	if the mark is 52
	the program should displays: fifty-two
*/
bool isValidUnitsORTensNumber(string number) {
	if (number.size() > 2 || number.empty()) {
		return false;
	}
	if (!isdigit(number[0]) || !isdigit(number[number.size() - 1])) {
		return false;
	}
	return true;
}
string enterStudentMark() {
	string mark = "";
	cout << "Please enter the student mark between 1 to 99 :\n";
	cin >> mark;
	if (isValidUnitsORTensNumber(mark))
		return mark;
	else {
		return enterStudentMark();
	}
}
map<char, string> unitsNumbersInLetters =
{
	{'1',"One"},
	{'2',"Two"},
	{'3',"Three"},
	{'4',"Four"},
	{'5',"Five"},
	{'6',"Six"},
	{'7',"Seven"},
	{'8',"Eight"},
	{'9',"Nine"}
};
map<string, string> tensNumbersInLetters = {
	{"10","Ten"},
	{"11","Eleven"},
	{"12","Twelve"},
	{"13","Thirteen"},
	{"14","Fourteen"},
	{"15","Fifteen"},
	{"16","Sixteen"},
	{"17","Seventeen"},
	{"18","Eighteen"},
	{"19","Ninteen"},

	{"20","Twenty"},
	{"30","Thirty"},
	{"40","Fourty"},
	{"50","Fifty"},
	{"60","Sixty"},
	{"70","Seventy"},
	{"80","Eighty"},
	{"90","Ninty"}
};
map<char, string> unitTensNumbersInLetters = {
	{'2',"Twenty"},
	{'3',"Thirty"},
	{'4',"Fourty"},
	{'5',"Fifty"},
	{'6',"Sixty"},
	{'7',"Seventy"},
	{'8',"Eighty"},
	{'9',"Ninty"}
};
string convertUnitsORTensNumberToWords(string number) {
	string numberInWords = "";
	int numberSize = number.size();
	if (!isValidUnitsORTensNumber(number)) {
		return "Not Supported Yet";
	}
	if (numberSize == 1) {
		numberInWords = unitsNumbersInLetters.at(number[0]);
	}
	else
	{
		if (number[0] == '1' || number[1] == '0') {
			numberInWords = tensNumbersInLetters.at(number);
		}
		else {
			numberInWords = unitTensNumbersInLetters.at(number[0]);
			numberInWords += "-";
			numberInWords += unitsNumbersInLetters.at(number[1]);
		}
	}
	return numberInWords;
}

//Main Call :	cout << convertUnitsORTensNumberToWords(enterStudentMark()) << endl;
/***********************************************************************/

