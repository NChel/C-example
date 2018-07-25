#include "BankingCommonDecl.h"
#include "Account.h"


Account::Account(int id, int money, const char * myname) :accId(id), balance(money) {	//������
	name = new char[strlen(myname) + 1];
	strcpy(name, myname);
}
//�����Ҵ��� ���ڿ� name�� 'name(copy.name)' �̷������� ���� �ʽ��ϴ�.
Account::Account(const Account &copy) :accId(copy.accId), balance(copy.balance) {
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

int Account::GetAccId() const { return accId; }

int Account::GetBalance() { return balance; }

void Account::Deposit(int money) {													//�Ʒ��� �ٸ� �޼ҵ忡 ����Ǵ°� �ƴ� Ŭ���� �ȿ��� ����Ǵ� ĸ��ȭ & ��������
	balance += money;
}

int Account::Withdraw(int money) {
	if (balance < money)
		return 0;

	balance -= money;
	return balance;
}
void Account::showAccInfo() const {
	cout << "����ID : " << accId << endl;
	cout << "�̸� : " << name << endl;
	cout << "�ܾ� : " << balance << endl;
}
Account::~Account() {																	//�Ҹ���
	delete[]name;
}