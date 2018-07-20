/*
	���ڵ尡 _crtisvalidheappointer(block) ������ �ߴ� ������
	���� �����̹Ƿ�, �ϳ��� ��ü�� 2���� �����Ѵ�.
	�׷��� �ϳ��� ��ü�� �����ǰ� �Ҹ�ɶ�
	�Ѵ� ���� ���ÿ� �Ǵ°��� �ƴϱ� �����̴�.
	
	�ϳ��� ��ü�� �Ҹ��ϰ� �����ϰ� �ִ� ����� �������� �������簴ü��
	�״�� ������ �����ϰ� �ȴ�.
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
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person() {
		delete []name;
		cout << "Called destructor." << endl;
	}
};
int main(void){
	Person man1("ȫ�浿", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}