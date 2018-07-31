#include <iostream>
using namespace std;

//�������
#ifndef __POINT_TEMPLATE_H_
#define __POINT_TEMPLATE_H_
template <typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	//�ܺο� �����ϱ�.
	//void ShowPosiotion() const {
	//	cout << '[' << xpos << ',' << ypos << ']' << endl;
	//}
	void ShowPosiotion() const;
};
#endif // !__POINT_TEMPLATE_H_
//������ϳ� /////////////////////////////////////////////////////


//�Ϲ� CPP ���� ����
template<typename T>
Point<T>::Point(T x, T y):xpos(x),ypos(y){}

template<typename T>
void Point<T>::ShowPosiotion() const{
	cout << '[' << xpos << ',' << ypos << ']' << endl;
}
//�Ϲ� CPP ���� �� ////////////////////////////////////////////////////////


//���� ���� ����
int main() {

	//���ø� Ŭ������  ��ü�� �����Ҷ� ���ø� �Լ������� �޸�, �ڷ��� ������ ������ �� ����.
	Point<int> p1(3, 4);
	p1.ShowPosiotion();
	Point<double> p2(2.3, 345.4);
	p2.ShowPosiotion();

	Point<char> p3('a', 'f');
	p3.ShowPosiotion();
}
//�������� �� //////////////////////////////////////////////////////