#include "BankingCommonDecl.h"
#include "Account.h"


Account::Account(int id, int money, const String myname) :accId(id), balance(money) {	//생성자
	//name = new char[strlen(myname) + 1];
	//strcpy(name, myname);
	name = myname;
}

/*	String클래스 사용으로 인한 주석처리.
//동적할당인 문자열 name은 'name(copy.name)' 이런식으로 되지 않습니다.
Account::Account(const Account &copy) :accId(copy.accId), balance(copy.balance) {
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}
//Account 클래스는 깊은 복사를 진행하도록 복사 생성자 정의
Account& Account::operator=(const Account& ref){
	accId = ref.accId;
	balance = ref.balance;

	delete[]name;
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
	return *this;
}
*/


int Account::GetAccId() const { return accId; }

int Account::GetBalance() { return balance; }

void Account::Deposit(int money) {													//아래는 다른 메소드에 실행되는게 아닌 클래스 안에서 실행되는 캡슐화 & 정보은닉
	balance += money;
}

int Account::Withdraw(int money) {
	if (balance < money)
		return 0;

	balance -= money;
	return balance;
}
void Account::showAccInfo() const {
	cout << "계좌ID : " << accId << endl;
	cout << "이름 : " << name << endl;
	cout << "잔액 : " << balance << endl;
}
/*	String클래스 사용으로 인한 주석처리.
Account::~Account() {																	//소멸자
	delete[]name;
}
*/