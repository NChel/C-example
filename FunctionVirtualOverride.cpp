/*
	�����Լ� �������̵�
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
	Third * tptr = new Third();			//�����Լ��� �������� �ʰ� �Ǹ� . . -> FirstFunc  �����Լ��� .ThirdFunc
	Second * sptr = tptr;				//�����Լ��� �������� �ʰ� �Ǹ� . . -> SecondFunc  �����Լ��� .ThirdFunc
	First * fptr = sptr;				//�����Լ��� �������� �ʰ� �Ǹ� . . -> FirstFunc  �����Լ��� .ThirdFunc

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}