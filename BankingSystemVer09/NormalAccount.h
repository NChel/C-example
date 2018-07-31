#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__
#include "Account.h"
#include "String.h"

//NormalAccount
class NormalAccount :public Account {
private:
	int interRait;
public:
	//NormalAccount(int id, int money, const char * name, int rait) :Account(id, money, name), interRait(rait) {}
	NormalAccount(int id, int money, const String name, int rait) :Account(id, money, name), interRait(rait) {}
	virtual void Deposit(int money) {
		Account::Deposit(money);							//�����߰�
		Account::Deposit(money*(interRait / 100.0));		//������ �߰�
	}
};
#endif // !__NORMALACCOUNT_H__
