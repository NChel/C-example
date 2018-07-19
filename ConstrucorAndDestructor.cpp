/*
*	������, �Ҹ��� ��� ����
*/
#include <iostream>
#include <cstring>
using namespace std;

//�������� ����� ����.
namespace COMP_POS {
	enum{
		CLERK, SENIOR, ASSIST, MANAGER
	};
	void ShowPositionInfo(int pos) {
		switch (pos) {
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
			break;
		}
	}
}

class NameCard {
private:
	char * name;
	char * com;
	char * tel;
	int position;
public:
	//���� �����ںκ� char ���ڿ� �����Ҵ�.
	NameCard(const char * myname, const char * mycom, const char * mytel, int pos):position(pos) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);

		com = new char[strlen(mycom) + 1];
		strcpy(com, mycom);

		tel = new char[strlen(mytel) + 1];
		strcpy(tel, mytel);

	}
	void showNameC() const {
		cout << "�̸� :" << name << endl;
		cout << "ȸ���̸� :" << com << endl;
		cout << "��ȭ��ȣ :" << tel << endl;
		cout << "���� :";
		COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}
	~NameCard() {
		delete[]name;
		delete[]com;
		delete[]tel;
	}

};

int main(void){
	NameCard m1("��������", "ȸ���̸�", "000-000-0000", COMP_POS::ASSIST);
	m1.showNameC();
	return 0;
}