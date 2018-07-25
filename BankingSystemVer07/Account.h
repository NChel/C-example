#ifndef __ACCOUT_H_
#define __ACCOUT_H_

class Account {
private:
	int accId;
	int balance;
	char * name;
public:
	Account(int id, int money, const char * myname);//생성자
	Account(const Account&copy);
	int GetAccId() const;
	int GetBalance();
	virtual void Deposit(int money);
	int Withdraw(int money);
	void showAccInfo() const;
	~Account();
};
//accout list로 만들자
//accout * accArr[MAX];		//저장을 위한 배열
//int accCnt = 0;				//계좌 갯수 초기화= 0
#endif // __ACCOUT_H_