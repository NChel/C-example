#include <iostream>
#include <cstring>
using namespace std;

enum RISK_LEVEL {
	RISK_A=30, RISK_B=20, RISK_C=10
};

class Employee {
private:
	char name[100];
public:
	Employee(const char * name) {
		strcpy(this->name, name);
	}
	void ShowYourName()const {
		cout << "name: " << name << endl;
	}
	//명시적으로 몸체를 정의하지 않았음.
	virtual int GetPay() const = 0;				//순수 가상함수
	virtual void ShowSalaryInfo() const = 0;	//순수 가상함수
};

class EmployeeHandler {
private:
	Employee * empList[50];
	int empNum;
public:
	EmployeeHandler() :empNum(0) {}
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo()const {

		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();	//Employee클레스의 가상함수를 둠으로써 에러나는 부분을 해결한다.

	}
	void ShowTotalSalary()const {
		int sum = 0;

		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();	//Employee클레스의 가상함수를 둠으로써 에러나는 부분을 해결한다.(GtPay())

		cout << "Salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};
class PermanentWorker :public Employee {
private:
	int salary;
public:
	PermanentWorker(const char* name, int money) :Employee(name), salary(money) {}
	int GetPay() const { return salary; }
	void ShowSalaryInfo()const {
		ShowYourName();
		cout << "Salary: " << GetPay() << endl << endl;
	}
};
class TemporaryWorker :public Employee {
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char * name, int pay) :Employee(name), workTime(0), payPerHour(pay) {}
	void AddworkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return payPerHour * workTime;
	}
	void ShowSalaryInfo() const{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char * name, int money, double ratio) :PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};
class ForeignSalesWorker :public SalesWorker {
private:
	const int riskLevel;
public:
	ForeignSalesWorker(const char * name, int money, double ratio, int risk) :SalesWorker(name, money, ratio), riskLevel(risk) {}
	int GetRiskPay() const{
		return (int)(SalesWorker::GetPay()*(riskLevel/100.0));
	}
	int GetPay()const {
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo()const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}


};

int main(void) {
	EmployeeHandler handler;

	//정규직
	handler.AddEmployee(new PermanentWorker("kim", 1000));
	handler.AddEmployee(new PermanentWorker("Hong", 1500));

	//임시직
	TemporaryWorker * alba = new TemporaryWorker("jung", 700);
	alba->AddworkTime(5);
	handler.AddEmployee(alba);

	//영업직
	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	//해외영업직 등록
	ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Hong?", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker * fseller2 = new ForeignSalesWorker("yOON?", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker * fseller3 = new ForeignSalesWorker("LEE?", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	//이번달 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	//이번달 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}