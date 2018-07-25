#include <iostream>
#include <cstring>
#define MAX 100	//�̸��� �ܰ� �ִ� ����������

/*
����� Ŭ���� �̸��� Accout �� �ƴ� accout ���� ����ٶ�.

	 Ver06�� �����Լ�, ���뿹�ݰ���, �ſ���� �߰��Ǿ���.
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
	accout(int id, int money, const char * myname) :accId(id), balance(money) {	//������
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	//�����Ҵ��� ���ڿ� name�� 'name(copy.name)' �̷������� ���� �ʽ��ϴ�.
	accout(const accout&copy) :accId(copy.accId), balance(copy.balance) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	int GetAccId() const { return accId; }
	int GetBalance() { return balance; }
	void Deposit(int money) {													//�Ʒ��� �ٸ� �޼ҵ忡 ����Ǵ°� �ƴ� Ŭ���� �ȿ��� ����Ǵ� ĸ��ȭ & ��������
		balance += money;
	}
	int Withdraw(int money) {
		if (balance < money)
			return 0;
		balance -= money;
		return balance;
	}
	void showAccInfo() const {
		cout << "����ID : " << accId << endl;
		cout << "�̸� : " << name << endl;
		cout << "�ܾ� : " << balance << endl;
	}
	~accout() {																	//�Ҹ���
		delete[]name;
	}
};
//accout list�� ������
//accout * accArr[MAX];		//������ ���� �迭
//int accCnt = 0;				//���� ���� �ʱ�ȭ= 0

//NormalAccount
class NormalAccount :public accout {
private:
	int interRait;
public:
	NormalAccount(int id, int money, const char * name, int rait) :accout(id, money, name), interRait(rait) {}
	void virtual Deposit(int money) {
		accout::Deposit(money);							//�����߰�
		accout::Deposit(money*(interRait / 100.0));		//������ �߰�
	}
};
//HighCreditAccount
class HighCreditAccount :public accout {
private:
	int revelRait;
public:
	HighCreditAccount(int id, int money, const char * name, int rait) :accout(id, money, name), revelRait(rait) {}
	void virtual Deposit(int money) {
		accout::Deposit(money);							//�����߰�
		accout::Deposit(money*(revelRait / 100.0));		//������ �߰�
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
	void menu();				//�޴�
	void deposit(void);			//�Ա�
	void withdraw(void);		//���
	void insertAcout(void);		//���°輳
	void insertNomalAccount(void);//������� �輳
	void insertCreditAccount(void);//�ſ���� �輳
	void showAllAcount(void);	//��ü ȸ����ȸ

};

accouHandler::accouHandler() :accCnt(0) {}


void accouHandler::menu() {
	cout << "-----�޴�-----" << endl;
	cout << "1. ���°輳" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. ���¹�ȣ ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << endl;
}
void accouHandler::insertAcout(void) {
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
void accouHandler::insertNomalAccount(void) {
	int id;									
	char name[MAX];
	int balance;
	int interRait;

	cout << "----���뿹�ݰ��°輳-------" << endl;
	cout << "������ ��ȣ : ";	cin >> id;
	cout << "�̸� : ";	cin >> name;
	cout << "�ʱ� �Աݾ� : ";	cin >> balance;
	cout << "���ڷ� : ";	cin >> interRait;
	accArr[accCnt++] = new NormalAccount(id, balance, name,interRait);
	cout << "----------" << endl;
	cout << endl;
}
//�ſ�ŷڰ���
void accouHandler::insertCreditAccount(void) {
	int id;										
	char name[MAX];
	int balance;
	int levelRait;

	cout << "----���뿹�ݰ��°輳-------" << endl;
	cout << "������ ��ȣ : ";	cin >> id;
	cout << "�̸� : ";	cin >> name;
	cout << "�ʱ� �Աݾ� : ";	cin >> balance;
	cout << "�ſ���(1.A���, 2.B���, 3.C���): "; cin >> levelRait;

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


	cout << "-----���� �Ա�-----" << endl;
	if (accCnt == 0) {
		cout << "�Աݰ����� ���°� �������� �ʽ��ϴ�.";
	}
	else {
		int money;
		int id;
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
			else
			{
				cout << "���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
			}
		}
	}
	cout << endl;
}
void accouHandler::withdraw(void) {
	cout << "-----���� ���-----" << endl;
	if (accCnt == 0) {
		cout << "��ݰ����� ���°� �������� �ʽ��ϴ�.";
	}
	else {
		int Taccid;
		int Tbalance;
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
			else
			{
				cout << "���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
			}
		}
	}
	cout << endl;
}
void accouHandler::showAllAcount(void) {
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

accouHandler::~accouHandler() {
	for (int i = 0; i < accCnt; i++)
		delete accArr[i];
}
//accouHandler END------------------------------------////////////////////////////////////////////////




int main(void) {
	int cho;				//�޴������ϴ� ����
	accouHandler manager;
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
			break;
		default:
			cout << "��ȿ���� �ʴ� ����Դϴ�." << endl;
			break;
		}
		if (cho == 5)
			break;
	}
	cout << "���α׷� ����" << endl;
	return 0;
}