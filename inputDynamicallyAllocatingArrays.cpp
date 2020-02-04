/*
	입력받은 배열을 동적할당한후 출력
*/

#include <iostream>
using namespace std;

char inputarr(int *arrtemp, char *data, const int len) {
	char *context = NULL;
	int i = 0;
	char *temp_s = strtok_s(data, " ", &context);
	while (temp_s != NULL)            // 자른 문자열이 나오지 않을 때까지 반복
	{
		arrtemp[i] = atoi(temp_s);             // 문자열을 자른 뒤 메모리 주소를 문자열 포인터 배열에 저장
		i++;

		temp_s = strtok_s(NULL, " ", &context);   // 다음 문자열을 잘라서 포인터를 반환
	}

	return *arrtemp;
}


int main(void) {

	int arrlen = 0;
	cout << "배열크기를 입력하세요\n";
	cin >> arrlen;
	cin.ignore(1000, '\n');			//배열의 수 입력받은뒤 다음 배열을 받을 준비(버퍼비움)
	cout << "배열크기 : " << arrlen << endl;


	cout << "배열을 입력하세요 '1 2 3 4' 이런식으로 : ";
	char temp[1000];
	std::cin.getline(temp, 99);

	int *arr = new int[arrlen];
	*arr = inputarr(arr, temp, arrlen);

	for (int j = 0; j < arrlen; j++) {
		cout << arr[j] << endl;
	}

	return 0;
}