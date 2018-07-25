#ifndef __ACCOUT_H_
#define __ACCOUT_H_

class Account {
private:
	int accId;
	int balance;
	char * name;
public:
	Account(int id, int money, const char * myname);//������
	Account(const Account&copy);
	int GetAccId() const;
	int GetBalance();
	virtual void Deposit(int money);
	int Withdraw(int money);
	void showAccInfo() const;
	~Account();
};
//accout list�� ������
//accout * accArr[MAX];		//������ ���� �迭
//int accCnt = 0;				//���� ���� �ʱ�ȭ= 0
#endif // __ACCOUT_H_