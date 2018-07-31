

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::menu() const {
	cout << "-----�޴�-----" << endl;
	cout << "1. ���°輳" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. ���¹�ȣ ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << endl;
}
void AccountHandler::insertAcout(void) {
	int select;
	cout << "[���� ���� ����]" << endl;
	cout << "1. ���뿹�ݰ��� | 2. �ſ�ŷڰ���" << endl;
	cout << "����"; cin >> select; cout << endl;
	if (select == NORMAL)
		insertNomalAccount();
	else
		insertCreditAccount();
}
//���뿹�ݰ���
void AccountHandler::insertNomalAccount(void) {
	int id;
	//char name[MAX];
	String name;
	int balance;
	int interRait;

	cout << "----���뿹�ݰ��°輳-------" << endl;
	cout << "������ ��ȣ : ";	cin >> id;
	cout << "�̸� : ";	cin >> name;
	cout << "�ʱ� �Աݾ� : ";	cin >> balance;
	cout << "���ڷ� : ";	cin >> interRait;
	accArr[accCnt++] = new NormalAccount(id, balance, name, interRait);
	cout << "----------" << endl;
	cout << endl;
}
//�ſ�ŷڰ���
void AccountHandler::insertCreditAccount(void) {
	int id;
	//char name[MAX];
	String name;
	int balance;
	int interRait;
	int creditLevel;

	cout << "----���뿹�ݰ��°輳-------" << endl;
	cout << "������ ��ȣ : ";	cin >> id;
	cout << "�̸� : ";	cin >> name;
	cout << "�ʱ� �Աݾ� : ";	cin >> balance;
	cout << "���ڷ� : ";	cin >> interRait;
	cout << "�ſ���(1.A���, 2.B���, 3.C���): "; cin >> creditLevel;

	switch (creditLevel) {
	case 1:
		accArr[accCnt++] = new HighCreditAccount(id, balance, name, interRait, LEVEL_A);
		break;
	case 2:
		accArr[accCnt++] = new HighCreditAccount(id, balance, name, interRait, LEVEL_B);
		break;
	case 3:
		accArr[accCnt++] = new HighCreditAccount(id, balance, name, interRait, LEVEL_C);
	}
	cout << "----------" << endl;
	cout << endl;
}

void AccountHandler::deposit(void) {
	int money;
	int id;

	cout << "-----���� �Ա�-----" << endl;
	if (accCnt == 0) {
		cout << "�Աݰ����� ���°� �������� �ʽ��ϴ�.";
	}
	else {
		cout << "�Ա��� ���¹�ȣ�� ���ÿ� : ";
		cin >> id;
		cout << endl;
		cout << "�Ա��� �ݾ��� ���ÿ� : ";
		cin >> money;
		cout << endl;

		for (int i = 0; i < accCnt; i++) {
			if (accArr[i]->GetAccId() == id) {
				accArr[i]->Deposit(money);
				cout << "�Ա��� �ܾ��� " << accArr[i]->GetBalance() << "�Դϴ�." << endl;
				return;
			}
			else {
				cout << "���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
			}
		}
	}
	cout << endl;
}
void AccountHandler::withdraw(void) {
	int Taccid;
	int Tbalance;
	cout << "-----���� ���-----" << endl;
	if (accCnt == 0) {
		cout << "��ݰ����� ���°� �������� �ʽ��ϴ�.";
	}
	else {
		cout << "����� ���¹�ȣ�� ���ÿ� : ";
		cin >> Taccid;
		cout << endl;
		cout << "����� �ݾ��� ���ÿ� : ";
		cin >> Tbalance;
		cout << endl;

		for (int i = 0; i < accCnt; i++) {
			if (accArr[i]->GetAccId() == Taccid) {
				if (accArr[i]->GetBalance() > Tbalance) {
					accArr[i]->Withdraw(Tbalance);
					cout << "����� �ܾ��� " << accArr[i]->GetBalance() << "�Դϴ�." << endl;
					return;
				}
				else {
					cout << "�ܰ��� �ܾ��� �����մϴ�.";
				}
			}
			else {
				cout << "���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
			}
		}
	}
	cout << endl;
}

AccountHandler::AccountHandler() :accCnt(0) {}

void AccountHandler::showAllAcount(void) {
	cout << "-----������-----" << endl;
	if (accCnt == 0) {
		cout << "���¸���� �����ϴ�..";
	}
	else {
		for (int i = 0; i < accCnt; i++) {
			cout << "------" << i + 1 << "-----" << endl;
			accArr[i]->showAccInfo();
		}
	}
	cout << endl;
}


AccountHandler::~AccountHandler()
{
	for (int i = 0; i<accCnt; i++)
		delete accArr[i];
}
//accouHandler END------------------------------------////////////////////////////////////////////////