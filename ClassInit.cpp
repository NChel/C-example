//클래스 복사생성자
//아래는 묵시적변환을 했을떄 복자생성자 생성

#include <iostream>
using namespace std;

class SoSimple {
private:
	int num1;
	int num2;
public :
	SoSimple(int n1, int n2):num1(n1),num2(n2){}
	explicit SoSimple(SoSimple &copy):num1(copy.num1),num2(copy.num2) {
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}
	void ShowSimpleData() {
		cout << num1 << endl;
		cout << num2 << endl;
	}
};
int main() {
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	sim1.ShowSimpleData();
	SoSimple * sim2 = &sim1;
	SoSimple * sim4(&sim1);
	cout << "생성 및 초기화 직후" << endl;
	sim4->ShowSimpleData();
	
	//SoSimple * sum3 = *sum2;
	//SoSimple sim4(*sum3);
	return 0;
}