/*
	가상함수 오버라이드
*/

#include <iostream>
using namespace std;

class First {
public:
	virtual void MyFunc() { cout << "FirstFunc" << endl; }
};
class Second:public First {
public:
	virtual void MyFunc() { cout << "SecondFunc" << endl; }
};
class Third : public Second {
public :
	virtual void MyFunc() { cout << "ThirdFunc" << endl; }
};

int main(void) {
	Third * tptr = new Third();			//가상함수를 선언하지 않게 되면 . . -> FirstFunc  가상함수면 .ThirdFunc
	Second * sptr = tptr;				//가상함수를 선언하지 않게 되면 . . -> SecondFunc  가상함수면 .ThirdFunc
	First * fptr = sptr;				//가상함수를 선언하지 않게 되면 . . -> FirstFunc  가상함수면 .ThirdFunc

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}