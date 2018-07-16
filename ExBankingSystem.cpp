#include <iostream>
#define MAX 20	//�̸��� �ܰ� �ִ� ����������

using namespace std;

void menu();				//�޴�
void deposit(void);			//�Ա�
void withdraw(void);		//���
void insertAcout(void);		//���°輳
void showAllAcount(void);	//��ü ȸ����ȸ

typedef struct {			//acout ���� ��
	int accId;
	int balance;
	char name[MAX];
}accout;

int accCnt = 0;				//���� ���� �ʱ�ȭ= 0
accout accArr[MAX];

int main(void) {
	int cho;				//�޴������ϴ� ����
	while (1) {
		menu();
		cout << "�޴��� �ش��ϴ� ���ڸ� �������ּ��� : ";
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
void insertAcout(void) {
	cout << "----���°輳-------" << endl;
	cout << "���¸� �輳�մϴ�." << endl;
	cout << "������ ��ȣ : ";
	cin >> accArr[accCnt].accId;
	cout << "�̸� : ";
	cin >> accArr[accCnt].name;
	accArr[accCnt].balance = 0;
	accCnt++;
	cout << "----------" << endl;
	cout << endl;
}
void deposit(void) {
	cout << "-----���� �Ա�-----" << endl;
	if (accCnt == 0) {
		cout << "�Աݰ����� ���°� �������� �ʽ��ϴ�.";
	}
	else {
		int Taccid;
		int Tbalance;
		cout << "�Ա��� ���¹�ȣ�� ���ÿ� : ";
		cin >> Taccid;
		cout << endl;
		cout << "�Ա��� �ݾ��� ���ÿ� : ";
		cin >> Tbalance;
		cout << endl;

		for (int i = 0; i < accCnt; i++) {
			if (accArr[i].accId == Taccid) {
				accArr[i].balance += Tbalance;
				cout << "�Ա��� �ܾ��� " << accArr[i].balance << "�Դϴ�." << endl;
				return;
			}
			else
			{
				cout << "���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
			}
		}
	}
	cout <<  endl;
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
			if (accArr[i].accId == Taccid) {
				if (accArr[i].balance > Tbalance) {
					accArr[i].balance -= Tbalance;
					cout << "����� �ܾ��� " << accArr[i].balance << "�Դϴ�." << endl;
					return;
				}else{
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
	}else{
		for (int i = 0; i < accCnt; i++) {
			cout << "------" << i+1 << "-----" << endl;
			cout << "���� : " << accArr[i].accId << endl;
			cout << "�ܾ� : " << accArr[i].balance << endl;
			cout << "�̸� : " << accArr[i].name << endl;
		}
	}
	cout << endl;
}