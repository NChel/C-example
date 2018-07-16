#include <iostream>
#define MAX 20	//이름과 잔고 최대 갯수를뜻함

using namespace std;

void menu();				//메뉴
void deposit(void);			//입금
void withdraw(void);		//출금
void insertAcout(void);		//계좌계설
void showAllAcount(void);	//전체 회원조회

typedef struct {			//acout 계좌 모델
	int accId;
	int balance;
	char name[MAX];
}accout;

int accCnt = 0;				//계좌 갯수 초기화= 0
accout accArr[MAX];

int main(void) {
	int cho;				//메뉴선택하는 변수
	while (1) {
		menu();
		cout << "메뉴에 해당하는 숫자를 선택해주세요 : ";
		cin >> cho;
		cout << endl;
		switch (cho)
		{
		case 1:
			insertAcout();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withdraw();
			break;
		case 4:
			showAllAcount();
			break;
		case 5:
			break;
		default:
			cout << "유효하지 않는 명령입니다." << endl;
			break;
		}
		if (cho == 5)
			break;
	}
	cout << "프로그램 종료" << endl;
	return 0;
}

void menu() {
	cout << "-----메뉴-----" << endl;
	cout << "1. 계좌계설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌번호 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << endl;
}
void insertAcout(void) {
	cout << "----계좌계설-------" << endl;
	cout << "계좌를 계설합니다." << endl;
	cout << "계좌의 번호 : ";
	cin >> accArr[accCnt].accId;
	cout << "이름 : ";
	cin >> accArr[accCnt].name;
	accArr[accCnt].balance = 0;
	accCnt++;
	cout << "----------" << endl;
	cout << endl;
}
void deposit(void) {
	cout << "-----계좌 입금-----" << endl;
	if (accCnt == 0) {
		cout << "입금가능한 계좌가 존재하지 않습니다.";
	}
	else {
		int Taccid;
		int Tbalance;
		cout << "입금할 계좌번호를 쓰시오 : ";
		cin >> Taccid;
		cout << endl;
		cout << "입금할 금액을 쓰시오 : ";
		cin >> Tbalance;
		cout << endl;

		for (int i = 0; i < accCnt; i++) {
			if (accArr[i].accId == Taccid) {
				accArr[i].balance += Tbalance;
				cout << "입금후 잔액은 " << accArr[i].balance << "입니다." << endl;
				return;
			}
			else
			{
				cout << "계좌번호가 존재하지 않습니다." << endl;
			}
		}
	}
	cout <<  endl;
}
void withdraw(void) {
	cout << "-----계좌 출금-----" << endl;
	if (accCnt == 0) {
		cout << "출금가능한 계좌가 존재하지 않습니다.";
	}
	else {
		int Taccid;
		int Tbalance;
		cout << "출금할 계좌번호를 쓰시오 : ";
		cin >> Taccid;
		cout << endl;
		cout << "출금할 금액을 쓰시오 : ";
		cin >> Tbalance;
		cout << endl;

		for (int i = 0; i < accCnt; i++) {
			if (accArr[i].accId == Taccid) {
				if (accArr[i].balance > Tbalance) {
					accArr[i].balance -= Tbalance;
					cout << "출금후 잔액은 " << accArr[i].balance << "입니다." << endl;
					return;
				}else{
					cout << "잔고의 잔액이 부족합니다.";
				}
			}
			else
			{
				cout << "계좌번호가 존재하지 않습니다." << endl;
			}
		}
	}
	cout << endl;
}
void showAllAcount(void) {
	cout << "-----모든계좌-----" << endl;
	if (accCnt == 0) {
		cout << "계좌목록이 없습니다..";
	}else{
		for (int i = 0; i < accCnt; i++) {
			cout << "------" << i+1 << "-----" << endl;
			cout << "계좌 : " << accArr[i].accId << endl;
			cout << "잔액 : " << accArr[i].balance << endl;
			cout << "이름 : " << accArr[i].name << endl;
		}
	}
	cout << endl;
}