#include <iostream>

using namespace std;


void ex(int &num1,int &num2) {
	num1++;
	num2 *= -1;
}
void SwapByRef2(int &ref1, int &ref2) {
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}


void main() {
	int i, j;
	i = 1;
	j = 1;
	cout << i << endl;
	cout << j << endl;
	ex(i, j);
	cout << "Call by value." << endl;
	cout << i << endl;
	cout << j << endl;

	cout << "-------------------------" << endl;

	int num1 = 5;
	int *ptr = &num1;
	int num2 = 10;
	int *ptr2 = &num2;

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	cout << "Call by reference." << endl;
	SwapByRef2(*ptr, *ptr2);
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
}