#include <iostream>

using namespace std;


void main(void) {
	const int num=12;
	const int *ptr = &num;
	const int *(*deptr) = &ptr;
	const int *(&ref) = ptr;

	cout << "num :" << num << endl;
	cout << "*ptr :" << *ptr << endl;
	cout << "ptr : " << ptr << endl;
	cout << "*(*deptr) :" << *(*deptr) << endl;
	cout << "*deptr :" << *deptr << endl;
	cout << "deptr :" << deptr << endl;
	cout << "*(&ref) :" << *(&ref) << endl;
	cout << "&ref :" << &ref << endl;
	cout << "ref :" << ref << endl;


}