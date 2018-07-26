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
		cout << "�̸�: " << name <<endl;
		cout << "����: " << age << endl;
	}

	//�� �޼ҵ带 ������� ������ �޸� ������ �Ͼ� ����.
	//���� ���縦 �����ϵ��������Ѵ�.
	//�޸� ������ �߻����� �ʵ���, ���� ���翡 �ռ� �޸� ������ ������ ��ħ.
	Person& operator=(const Person& ref) {
		delete[]name;		//�޸��� ������ �������� �޸� ���� ����
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