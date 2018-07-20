#include <iostream>
#include <cstring>
#define MAX 100	//�̸��� �ܰ� �ִ� ����������

/*
	����� Ŭ���� �̸��� Accout �� �ƴ� accout ���� ����ٶ�.
*/

using namespace std;

void menu();				//�޴�
void deposit(void);			//�Ա�
void withdraw(void);		//���
void insertAcout(void);		//���°輳
void showAllAcount(void);	//��ü ȸ����ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class accout {
private:
	int accId;
	int balance;
	char * name;
public:
	accout(int id, int money, const char * myname):accId(id),balance(money) {	//������
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	int GetAccId() { return accId; }
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
	void showAccInfo() {
		cout << "����ID : " << accId << endl;
		cout << "�̸� : " << name << endl;
		cout << "�ܾ� : " << balance << endl;
	}
	~accout() {																	//�Ҹ���
		delete[]name;
	}
};

accout * accArr[MAX];		//������ ���� �迭
int accCnt = 0;				//���� ���� �ʱ�ȭ= 0


int main(void) {
	int cho;				//�޴������ϴ� ����
	while (1) {
		menu();
		cout << "�޴��� �ش��ϴ� ���ڸ� �������ּ��� : ";
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
			cout << "��ȿ���� �ʴ� ����Դϴ�." << endl;
			break;
		}
		if (cho == 5)
			break;
	}
	cout << "���α׷� ����" << endl;
	return 0;
}

void menu() {
	cout << "-----�޴�-----" << endl;
	cout << "1. ���°輳" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. ���¹�ȣ ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << endl;
}
void insertAcout(void) {															//ó�� ����ü �����϶��� �޵忡�� ������ ������, Ŭ������ ����������
	int id;																			//Ŭ���� ���پ��̴� ������ �� ������
	char name[MAX];
	int balance;

	cout << "----���°輳-------" << endl;
	cout << "���¸� �輳�մϴ�." << endl;
	cout << "������ ��ȣ : ";
	cin >> id;
	cout << "�̸� : ";
	cin >> name;
	cout << "�ʱ� �Աݾ� : ";
	cin >> balance;
	accArr[accCnt++] = new accout(id, balance, name);
	cout << "----------" << endl;
	cout << endl;
}
void deposit(void) {
	

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
			if (accArr[i]->GetAccId()==id) {
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
void withdraw(void) {
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
void showAllAcount(void) {
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