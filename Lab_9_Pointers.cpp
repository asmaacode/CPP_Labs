#include <iostream>
using namespace std;
/*
	1st Problem :
	Consider the folowing function: 
		
  void mystery(char str1[], char str2[]) {
    int i = 0, j = 0;
    for (i = 0; str1[i] != 0 ;i++);
      for (j = 0; str2[j] != 0 ;j++)
        str1[i++] = str2[j];
  }

	Write an equivelent function named  myFunction that  takes two input parameters of type char* and does the same as the function mystery above. 
	You are not allowed to use arrays inside your function, only character pointers.

*/
//After testing mystery work is merging two arraies
//myFunction :
void arrayMerge(char* str1, char* str2) {
	int i = 0, j = 0;
	for (i = 0; str1[i] != 0;i++);
	for (j = 0; str2[j] != 0;j++)
		str1[i++] = str2[j];
};
void callFirstSolution() {
	char str1[6] = { 0 };
	str1[0] = 'A';
	str1[1] = 'B';
	str1[2] = 'C';

	char str2[4] = { 0 };
	str2[0] = 'D';
	str2[1] = 'E';
	str2[2] = 'F';

	char* str1_Ptr, * str2_Ptr;
	str1_Ptr = str1;
	str2_Ptr = str2;
	arrayMerge(str1_Ptr, str2_Ptr);

	cout << "Merged String :	 ";
	for (char x : str1) {
		cout << x;
	}
	cout << "\n";
};
/*Main Call :	callFirstSolution(); */
/***************************************************/
/*
	2nd Problem:
	 reverse (int * start, int *end);
	The first parameter is a pointer to the first element of the array, the second parameter is a pointer to the last element of the array. 
	The function supposed to reverse the element in the array.
	Example :
		If before calling the function, the array contains 4 9 3 6
		Then after calling the function,the array should contain 6 3 9 4
	You are not allowed to use in your implementation the array subscript operator [].
*/

void reverse(int* start, int* end) {
	int temp = 0;
	while (end > start) {
		temp = *end;
		*end = *start;
		*start = temp;

		start++;
		end--;
	}
}

void printArray(int arr[], int size) {
	for (int i = 0;i < size;i++)
		cout << arr[i] << "  ";
	cout << "\n";
}

void callSecondSolution() {
	int arr[4] = { 2,3,4,5 };
	cout << "Your Array : ";
	printArray(arr, 4);
	int* start = arr;
	int* end = &arr[sizeof(arr) / sizeof(int) - 1];
	reverse(start,end);
	cout << "Reversed : ";
	printArray(arr, 4);
}

/*Main Call :	callSecondSolution(); */
/***************************************************/
