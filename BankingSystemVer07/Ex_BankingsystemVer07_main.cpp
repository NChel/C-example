#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void) {
	int cho;				//�޴������ϴ� ����
	AccountHandler manager;
	while (1) {
		manager.menu();
		cout << "�޴��� �ش��ϴ� ���ڸ� �������ּ��� : ";
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
			cout << "��ȿ���� �ʴ� ����Դϴ�." << endl;
		}
	}
	cout << "���α׷� ����" << endl;
	return 0;
}