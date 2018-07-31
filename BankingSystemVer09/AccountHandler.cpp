

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::menu() const {
	cout << "-----메뉴-----" << endl;
	cout << "1. 계좌계설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌번호 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << endl;
}
void AccountHandler::insertAcout(void) {
	int select;
	cout << "[계좌 종류 선택]" << endl;
	cout << "1. 보통예금계좌 | 2. 신용신뢰계좌" << endl;
	cout << "선택"; cin >> select; cout << endl;
	if (select == NORMAL)
		insertNomalAccount();
	else
		insertCreditAccount();
}
//보통예금계좌
void AccountHandler::insertNomalAccount(void) {
	int id;
	//char name[MAX];
	String name;
	int balance;
	int interRait;

	cout << "----보통예금계좌계설-------" << endl;
	cout << "계좌의 번호 : ";	cin >> id;
	cout << "이름 : ";	cin >> name;
	cout << "초기 입금액 : ";	cin >> balance;
	cout << "이자률 : ";	cin >> interRait;
	accArr[accCnt++] = new NormalAccount(id, balance, name, interRait);
	cout << "----------" << endl;
	cout << endl;
}
//신용신뢰계좌
void AccountHandler::insertCreditAccount(void) {
	int id;
	//char name[MAX];
	String name;
	int balance;
	int interRait;
	int creditLevel;

	cout << "----보통예금계좌계설-------" << endl;
	cout << "계좌의 번호 : ";	cin >> id;
	cout << "이름 : ";	cin >> name;
	cout << "초기 입금액 : ";	cin >> balance;
	cout << "이자률 : ";	cin >> interRait;
	cout << "신용등급(1.A등급, 2.B등급, 3.C등급): "; cin >> creditLevel;

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

	cout << "-----계좌 입금-----" << endl;
	if (accCnt == 0) {
		cout << "입금가능한 계좌가 존재하지 않습니다.";
	}
	else {
		cout << "입금할 계좌번호를 쓰시오 : ";
		cin >> id;
		cout << endl;
		cout << "입금할 금액을 쓰시오 : ";
		cin >> money;
		cout << endl;

		for (int i = 0; i < accCnt; i++) {
			if (accArr[i]->GetAccId() == id) {
				accArr[i]->Deposit(money);
				cout << "입금후 잔액은 " << accArr[i]->GetBalance() << "입니다." << endl;
				return;
			}
			else {
				cout << "계좌번호가 존재하지 않습니다." << endl;
			}
		}
	}
	cout << endl;
}
void AccountHandler::withdraw(void) {
	int Taccid;
	int Tbalance;
	cout << "-----계좌 출금-----" << endl;
	if (accCnt == 0) {
		cout << "출금가능한 계좌가 존재하지 않습니다.";
	}
	else {
		cout << "출금할 계좌번호를 쓰시오 : ";
		cin >> Taccid;
		cout << endl;
		cout << "출금할 금액을 쓰시오 : ";
		cin >> Tbalance;
		cout << endl;

		for (int i = 0; i < accCnt; i++) {
			if (accArr[i]->GetAccId() == Taccid) {
				if (accArr[i]->GetBalance() > Tbalance) {
					accArr[i]->Withdraw(Tbalance);
					cout << "출금후 잔액은 " << accArr[i]->GetBalance() << "입니다." << endl;
					return;
				}
				else {
					cout << "잔고의 잔액이 부족합니다.";
				}
			}
			else {
				cout << "계좌번호가 존재하지 않습니다." << endl;
			}
		}
	}
	cout << endl;
}

AccountHandler::AccountHandler() :accCnt(0) {}

void AccountHandler::showAllAcount(void) {
	cout << "-----모든계좌-----" << endl;
	if (accCnt == 0) {
		cout << "계좌목록이 없습니다..";
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