#include <iostream>

using namespace std;


void main(void) {
	const int num=12;
	const int *ptr = &num;
	const int *(*deptr) = &ptr;
	const int *(&ref) = ptr;

	cout << "num :" << num << endl;			//12
	cout << "*ptr :" << *ptr << endl;		//12
	cout << "ptr : " << ptr << endl;		//0021FD68
	cout << "*(*deptr) :" << *(*deptr) << endl;	//12
	cout << "*deptr :" << *deptr << endl;		//0021FD68
	cout << "deptr :" << deptr << endl;		//0021FD5C
	cout << "*(&ref) :" << *(&ref) << endl;		//0021FD68
	cout << "&ref :" << &ref << endl;		//0021FD5C
	cout << "ref :" << ref << endl;			//0021FD68


}
