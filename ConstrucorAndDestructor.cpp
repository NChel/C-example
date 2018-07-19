/*
*	생성자, 소멸자 사용 예제
*/
#include <iostream>
#include <cstring>
using namespace std;

//열거형을 사용한 예제.
namespace COMP_POS {
	enum{
		CLERK, SENIOR, ASSIST, MANAGER
	};
	void ShowPositionInfo(int pos) {
		switch (pos) {
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
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
	//여기 생성자부분 char 문자열 동적할당.
	NameCard(const char * myname, const char * mycom, const char * mytel, int pos):position(pos) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);

		com = new char[strlen(mycom) + 1];
		strcpy(com, mycom);

		tel = new char[strlen(mytel) + 1];
		strcpy(tel, mytel);

	}
	void showNameC() const {
		cout << "이름 :" << name << endl;
		cout << "회사이름 :" << com << endl;
		cout << "전화번호 :" << tel << endl;
		cout << "직급 :";
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
	NameCard m1("마스터이", "회사이름", "000-000-0000", COMP_POS::ASSIST);
	m1.showNameC();
	return 0;
}