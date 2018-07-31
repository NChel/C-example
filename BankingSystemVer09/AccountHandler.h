#ifndef __ACCOUTHANDLER_H__
#define __ACCOUTHANDLER_H__
#include "Account.h"
#include "AccountArray.h"
#include "BankingCommonDecl.h"

//accouHandler START----------------------------------------------------------------------------
class AccountHandler {
private:
	BoundCheckAccountPtrArray accArr;		//�迭 Ŭ����
	//Account * accArr[MAX];
	int accCnt;
public:
	AccountHandler();
	void menu()const;				//�޴�
	void deposit(void);			//�Ա�
	void withdraw(void);		//���
	void insertAcout(void);		//���°輳
	void showAllAcount(void);	//��ü ȸ����ȸ
	~AccountHandler();
protected:
	void insertNomalAccount(void);//������� �輳
	void insertCreditAccount(void);//�ſ���� �輳
};
#endif // !__ACCOUTHANDLER_H__