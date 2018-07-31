#ifndef __ACCOUTHANDLER_H__
#define __ACCOUTHANDLER_H__
#include "Account.h"
#include "AccountArray.h"
#include "BankingCommonDecl.h"

//accouHandler START----------------------------------------------------------------------------
class AccountHandler {
private:
	BoundCheckAccountPtrArray accArr;		//배열 클레스
	//Account * accArr[MAX];
	int accCnt;
public:
	AccountHandler();
	void menu()const;				//메뉴
	void deposit(void);			//입금
	void withdraw(void);		//출금
	void insertAcout(void);		//계좌계설
	void showAllAcount(void);	//전체 회원조회
	~AccountHandler();
protected:
	void insertNomalAccount(void);//보통계좌 계설
	void insertCreditAccount(void);//신용계좌 계설
};
#endif // !__ACCOUTHANDLER_H__