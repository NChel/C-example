#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char * name;
	int age;
public:
	Person(const char * myname, int myage) :age(myage) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	void ShowPersonInfo() const{
		cout << "이름: " << name <<endl;
		cout << "나이: " << age << endl;
	}

	//이 메소드를 사용하지 않으면 메모리 누수가 일어 난다.
	//깊은 복사를 진행하도록정의한다.
	//메모리 누수가 발생하지 않도록, 깇은 복사에 앞서 메모리 해제의 과정을 거침.
	Person& operator=(const Person& ref) {
		delete[]name;		//메모리의 누수를 막기위한 메모리 해제 연산
		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}
	/////////////////////////////////////////////////////////////////////


	~Person() {
		delete[]name;
		cout << "called destructor!" << endl;
	}
};
int main() {
	Person man1("LEE", 20);
	Person man2("Hong", 15);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
}