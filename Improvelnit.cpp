#include <iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	AAA(int n=0):num(n){
		cout << "AAA(int n=0)" << endl;
	}
	AAA(const AAA& ref) :num(ref.num) {
		cout << "AAA(const AAA& ref)" << endl;
	}
	AAA& operator=(const AAA& ref) {
		num = ref.num;
		cout << "AAA& operator=(const AAA& ref)" << endl;
		return *this;
	}
};
class BBB {
private:
	AAA mem;
public:
	//복사생서자만 실행됨
	BBB(const AAA& ref):mem(ref){}
};
class CCC {
private:
	AAA mem;
public:
	//복사생성자와 mem=ref의 대입연산자가 한번씩 실행됨
	CCC(const AAA& ref) { mem = ref; }
};

int main() {
	AAA obj1(12);
	cout << "-----------------------" << endl;
	BBB obj2(obj1);
	cout << "-----------------------" << endl;
	CCC obj3(obj1);
	return 0;
}

/* 실행결과 화면
AAA(int n = 0)
---------------------- -
AAA(const AAA& ref)
---------------------- -
AAA(int n = 0)
AAA& operator=(const AAA& ref)
계속하려면 아무 키나 누르십시오 . . .
*/