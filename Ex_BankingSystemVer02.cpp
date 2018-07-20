#include <iostream>
#include <cstring>
#define MAX 100	//이름과 잔고 최대 갯수를뜻함

/*
	참고로 클래스 이름은 Accout 가 아닌 accout 임을 참고바람.
*/

using namespace std;

void menu();				//메뉴
void deposit(void);			//입금
void withdraw(void);		//출금
void insertAcout(void);		//계좌계설
void showAllAcount(void);	//전체 회원조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class accout {
private:
	int accId;
	int balance;
	char * name;
public:
	accout(int id, int money, const char * myname):accId(id),balance(money) {	//생성자
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	//동적할당인 문자열 name은 'name(copy.name)' 이런식으로 되지 않습니다.
	accout(const accout&copy) :accId(copy.accId), balance(copy.balance) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	int GetAccId() { return accId; }
	int GetBalance() { return balance; }
	void Deposit(int money) {													//아래는 다른 메소드에 실행되는게 아닌 클래스 안에서 실행되는 캡슐화 & 정보은닉
		balance += money;
	}
	int Withdraw(int money) {
		if (balance < money)
			return 0;
		balance -= money;
		return balance;
	}
	void showAccInfo() {
		cout << "계좌ID : " << accId << endl;
		cout << "이름 : " << name << endl;
		cout << "잔액 : " << balance << endl;
	}
	~accout() {																	//소멸자
		delete[]name;
	}
};

accout * accArr[MAX];		//저장을 위한 배열
int accCnt = 0;				//계좌 갯수 초기화= 0


int main(void) {
	int cho;				//메뉴선택하는 변수
	while (1) {
		menu();
		cout << "메뉴에 해당하는 숫자를 선택해주세요 : ";
		cin >> cho;
		cout << endl;
		switch (cho)
		{
		case MAKE:
			insertAcout();
			break;
		case DEPOSIT:
			deposit();
			break;
		case WITHDRAW:
			withdraw();
			break;
		case INQUIRE:
			showAllAcount();
			break;
		case EXIT:
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
void insertAcout(void) {															//처음 구조체 버전일때는 메드에서 연산을 했으나, 클래스를 선언함으로
	int id;																			//클래스 접근없이는 연산을 할 수없음
	char name[MAX];
	int balance;

	cout << "----계좌계설-------" << endl;
	cout << "계좌를 계설합니다." << endl;
	cout << "계좌의 번호 : ";
	cin >> id;
	cout << "이름 : ";
	cin >> name;
	cout << "초기 입금액 : ";
	cin >> balance;
	accArr[accCnt++] = new accout(id, balance, name);
	cout << "----------" << endl;
	cout << endl;
}
void deposit(void) {
	

	cout << "-----계좌 입금-----" << endl;
	if (accCnt == 0) {
		cout << "입금가능한 계좌가 존재하지 않습니다.";
	}
	else {
		int money;
		int id;
		cout << "입금할 계좌번호를 쓰시오 : ";
		cin >> id;
		cout << endl;
		cout << "입금할 금액을 쓰시오 : ";
		cin >> money;
		cout << endl;

		for (int i = 0; i < accCnt; i++) {
			if (accArr[i]->GetAccId()==id) {
				accArr[i]->Deposit(money);
				cout << "입금후 잔액은 " << accArr[i]->GetBalance() << "입니다." << endl;
				return;
			}
			else
			{
				cout << "계좌번호가 존재하지 않습니다." << endl;
			}
		}
	}
	cout << endl;
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
	}
	else {
		for (int i = 0; i < accCnt; i++) {
			cout << "------" << i + 1 << "-----" << endl;
			accArr[i]->showAccInfo();
		}
	}
	cout << endl;
}
