/*
	복사생성자와 호출 시점.
*/


#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public :
	SoSimple(int n) :num(n) {
		cout << "New Object: " << this << endl;
	}
	SoSimple(const SoSimple& copy) :num(copy.num) {
		cout << "New Copy obj: " << this << endl;
	}
	~SoSimple() {
		cout << "Destroy obj: " << this << endl;
	}
};
SoSimple SimpleFuncObj(SoSimple ob) {
	cout << "Param ADR: " << &ob << endl;
	return ob;
}

int main() {
	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);
	cout << "Return Obj " << &tempRef << endl;
	return 0;
}

/*
New Object: 002AFCCC
New Copy obj: 002AFBB4
Param ADR: 002AFBB4
New Copy obj: 002AFBE8
Destroy obj: 002AFBB4
Destroy obj: 002AFBE8

New Copy obj: 002AFBB4
Param ADR: 002AFBB4
New Copy obj: 002AFCC0
Destroy obj: 002AFBB4
Return Obj 002AFCC0
Destroy obj: 002AFCC0
Destroy obj: 002AFCCC
계속하려면 아무 키나 누르십시오 . . .
*/