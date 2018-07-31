#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__
#include "NormalAccount.h"
#include "String.h"
//HighCreditAccount
class HighCreditAccount :public NormalAccount {
private:
	int revelRait;
public:
	//HighCreditAccount(int id, int money, const char * name, int rait,int special) :NormalAccount(id, money, name,rait), revelRait(special) {}
	HighCreditAccount(int id, int money, const String name, int rait, int special) :NormalAccount(id, money, name, rait), revelRait(special) {}
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);							//원금추가
		Account::Deposit(money*(revelRait / 100.0));		//이자율 추가
	}
};
#endif // !__HIGHCREDITACCOUNT_H__
