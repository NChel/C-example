/*
	이코드가 _crtisvalidheappointer(block) 에러가 뜨는 이유는
	얕은 복사이므로, 하나의 객체를 2개가 참조한다.
	그러나 하나의 객체가 생성되고 소멸될때
	둘다 같이 동시에 되는것이 아니기 때문이다.
	
	하나의 객체가 소멸하고 참조하고 있던 대상이 없어지는 얕은복사객체는
	그대로 에러를 유발하게 된다.
*/


#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char * name;
	int age;
public:
	Person(const char * myname, int myage) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person() {
		delete []name;
		cout << "Called destructor." << endl;
	}
};
int main(void){
	Person man1("홍길동", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}