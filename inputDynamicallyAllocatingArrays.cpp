/*
	�Է¹��� �迭�� �����Ҵ����� ���
*/

#include <iostream>
using namespace std;

char inputarr(int *arrtemp, char *data, const int len) {
	char *context = NULL;
	int i = 0;
	char *temp_s = strtok_s(data, " ", &context);
	while (temp_s != NULL)            // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
	{
		arrtemp[i] = atoi(temp_s);             // ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ����
		i++;

		temp_s = strtok_s(NULL, " ", &context);   // ���� ���ڿ��� �߶� �����͸� ��ȯ
	}

	return *arrtemp;
}


int main(void) {

	int arrlen = 0;
	cout << "�迭ũ�⸦ �Է��ϼ���\n";
	cin >> arrlen;
	cin.ignore(1000, '\n');			//�迭�� �� �Է¹����� ���� �迭�� ���� �غ�(���ۺ��)
	cout << "�迭ũ�� : " << arrlen << endl;


	cout << "�迭�� �Է��ϼ��� '1 2 3 4' �̷������� : ";
	char temp[1000];
	std::cin.getline(temp, 99);

	int *arr = new int[arrlen];
	*arr = inputarr(arr, temp, arrlen);

	for (int j = 0; j < arrlen; j++) {
		cout << arr[j] << endl;
	}

	return 0;
}