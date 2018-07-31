#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void) {
	int cho;				//메뉴선택하는 변수
	AccountHandler manager;
	while (1) {
		manager.menu();
		cout << "메뉴에 해당하는 숫자를 선택해주세요 : ";
		cin >> cho;
		cout << endl;
		switch (cho)
		{
		case MAKE:
			manager.insertAcout();
			break;
		case DEPOSIT:
			manager.deposit();
			break;
		case WITHDRAW:
			manager.withdraw();
			break;
		case INQUIRE:
			manager.showAllAcount();
			break;
		case EXIT:
			return 0;
		default:
			cout << "유효하지 않는 명령입니다." << endl;
		}
	}
	cout << "프로그램 종료" << endl;
	return 0;
}