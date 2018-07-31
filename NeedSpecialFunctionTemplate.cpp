#include <iostream>
using namespace std;

template<typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

template<>
char * Max<char*>(char*a, char*b) {								//Max<char*>()
	cout << "char* MAx()호출" << endl;
	return strlen(a) > strlen(b) ? a : b;
}
template<>
const char * Max<const char*>(const char*a, const char*b) {		//Max() 여기에 자료형을 명시하지 않아도 상관없으나 가급적 하는게 좋음.
	cout << "사전용 const char Max()호출" << endl;				//Max<const char*>()
	return strcmp(a, b) > 0 ? a : b;
}
int main() {
	cout << Max(11, 15) << endl;
	cout << Max(24.5, 246.2) << endl;
	cout << Max("String", "String~?") << endl;

	cout << "문자열 비교" << endl;

	char str1[] = "String";
	char str2[] = "String~?";
	cout << Max(str1, str2) << endl;
}