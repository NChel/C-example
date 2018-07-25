#include <iostream>
#include <cstring>
#define MAX 100	//이름과 잔고 최대 갯수를뜻함

/*
참고로 클래스 이름은 Accout 가 아닌 accout 임을 참고바람.

	 Ver06에 가상함수, 보통예금계좌, 신용계좌 추가되었다.
*/

using namespace std;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

class accout {
private:
	int accId;
	int balance;
	char * name;
public:
	accout(int id, int money, const char * myname) :accId(id), balance(money) {	//생성자
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	//동적할당인 문자열 name은 'name(copy.name)' 이런식으로 되지 않습니다.
	accout(const accout&copy) :accId(copy.accId), balance(copy.balance) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	int GetAccId() const { return accId; }
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
	void showAccInfo() const {
		cout << "계좌ID : " << accId << endl;
		cout << "이름 : " << name << endl;
		cout << "잔액 : " << balance << endl;
	}
	~accout() {																	//소멸자
		delete[]name;
	}
};
//accout list로 만들자
//accout * accArr[MAX];		//저장을 위한 배열
//int accCnt = 0;				//계좌 갯수 초기화= 0

//NormalAccount
class NormalAccount :public accout {
private:
	int interRait;
public:
	NormalAccount(int id, int money, const char * name, int rait) :accout(id, money, name), interRait(rait) {}
	void virtual Deposit(int money) {
		accout::Deposit(money);							//원금추가
		accout::Deposit(money*(interRait / 100.0));		//이자율 추가
	}
};
//HighCreditAccount
class HighCreditAccount :public accout {
private:
	int revelRait;
public:
	HighCreditAccount(int id, int money, const char * name, int rait) :accout(id, money, name), revelRait(rait) {}
	void virtual Deposit(int money) {
		accout::Deposit(money);							//원금추가
		accout::Deposit(money*(revelRait / 100.0));		//이자율 추가
	}
};


//accouHandler START----------------------------------------------------------------------------
class accouHandler{
private:
	accout * accArr[MAX];
	int accCnt;
public:
	accouHandler();
	~accouHandler();
	void menu();				//메뉴
	void deposit(void);			//입금
	void withdraw(void);		//출금
	void insertAcout(void);		//계좌계설
	void insertNomalAccount(void);//보통계좌 계설
	void insertCreditAccount(void);//신용계좌 계설
	void showAllAcount(void);	//전체 회원조회

};

accouHandler::accouHandler() :accCnt(0) {}


void accouHandler::menu() {
	cout << "-----메뉴-----" << endl;
	cout << "1. 계좌계설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌번호 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << endl;
}
void accouHandler::insertAcout(void) {
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
void accouHandler::insertNomalAccount(void) {
	int id;									
	char name[MAX];
	int balance;
	int interRait;

	cout << "----보통예금계좌계설-------" << endl;
	cout << "계좌의 번호 : ";	cin >> id;
	cout << "이름 : ";	cin >> name;
	cout << "초기 입금액 : ";	cin >> balance;
	cout << "이자률 : ";	cin >> interRait;
	accArr[accCnt++] = new NormalAccount(id, balance, name,interRait);
	cout << "----------" << endl;
	cout << endl;
}
//신용신뢰계좌
void accouHandler::insertCreditAccount(void) {
	int id;										
	char name[MAX];
	int balance;
	int levelRait;

	cout << "----보통예금계좌계설-------" << endl;
	cout << "계좌의 번호 : ";	cin >> id;
	cout << "이름 : ";	cin >> name;
	cout << "초기 입금액 : ";	cin >> balance;
	cout << "신용등급(1.A등급, 2.B등급, 3.C등급): "; cin >> levelRait;

	switch (levelRait) {
	case 1:
		accArr[accCnt++] = new NormalAccount(id, balance, name, LEVEL_A);
		break;
	case 2:
		accArr[accCnt++] = new NormalAccount(id, balance, name, LEVEL_B);
		break;
	case 3:
		accArr[accCnt++] = new NormalAccount(id, balance, name, LEVEL_C);
	}
	cout << "----------" << endl;
	cout << endl;
}

void accouHandler::deposit(void) {


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
			if (accArr[i]->GetAccId() == id) {
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
void accouHandler::withdraw(void) {
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
void accouHandler::showAllAcount(void) {
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

accouHandler::~accouHandler() {
	for (int i = 0; i < accCnt; i++)
		delete accArr[i];
}
//accouHandler END------------------------------------////////////////////////////////////////////////




int main(void) {
	int cho;				//메뉴선택하는 변수
	accouHandler manager;
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