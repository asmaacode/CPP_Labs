#include <iostream>
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
	if (CalculationType == enCalculationTypes::Area) cout<<"The result is :" << calculateSphereArea(RadiusLength);
	if (CalculationType == enCalculationTypes::Volume) cout << "The result is :" << calculateSphereVolume(RadiusLength);
}
void callCubeCalculation(double CalculationType) {
	double SideLength = enterSideLength();
	if (CalculationType == enCalculationTypes::Area) cout <<"The result is :" << calculateCubeArea(SideLength);
	if (CalculationType == enCalculationTypes::Volume) cout << "The result is :" <<calculateCubeVolume(SideLength);
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



