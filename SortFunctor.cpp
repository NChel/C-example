/*	
*	() Functor or Function Object
*	어떠한 경우에 사용되는가?
*	- 함수 또는 객체의 동적 방식에 유연함을 제공할때 주로 사용된다.
*/

#include <iostream>
using namespace std;

class SortRule {
public:
	virtual bool operator()(int num1, int num2) const = 0;
};
class AsendingSort :public SortRule {	//오름차순
public:
	bool operator()(int num1, int num2) const {
		if (num1 > num2)
			return true;
		else
			return false;
	}
};
class DesendingSort : public SortRule {	//내림차순
	bool operator()(int num1, int num2) const {
		if (num1 < num2)
			return true;
		else
			return false;
	}
};
class DataStorage {
private:
	int * arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) :idx(0), MAX_LEN(arrlen) {
		arr = new int[MAX_LEN];
	}
	void AddData(int num) {
		if (MAX_LEN <= idx) {
			cout << "No more data can be entered into the storage.";
			return;
		}
		arr[idx++] = num;
	}
	void ShowAllData() {
		for (int i = 0; i < idx; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}
	void SortData(const SortRule& functor) {
		for (int i = 0; i < (idx - 1); i++) {
			for (int j = 0; j < (idx - 1); j++) {
				if (functor(arr[j], arr[j + 1])) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};
int main() {
	DataStorage storage(5);
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);

	storage.SortData(AsendingSort());
	storage.ShowAllData();

	storage.SortData(DesendingSort());
	storage.ShowAllData();

	return 0;
}