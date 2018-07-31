#include <iostream>
using namespace std;

//헤더파일
#ifndef __POINT_TEMPLATE_H_
#define __POINT_TEMPLATE_H_
template <typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	//외부에 정의하기.
	//void ShowPosiotion() const {
	//	cout << '[' << xpos << ',' << ypos << ']' << endl;
	//}
	void ShowPosiotion() const;
};
#endif // !__POINT_TEMPLATE_H_
//헤더파일끝 /////////////////////////////////////////////////////


//일반 CPP 파일 시작
template<typename T>
Point<T>::Point(T x, T y):xpos(x),ypos(y){}

template<typename T>
void Point<T>::ShowPosiotion() const{
	cout << '[' << xpos << ',' << ypos << ']' << endl;
}
//일반 CPP 파일 끝 ////////////////////////////////////////////////////////


//메인 파일 시작
int main() {

	//템플릿 클래스는  객체를 생성할때 템플릿 함수형과는 달리, 자료형 정보를 생략할 수 없다.
	Point<int> p1(3, 4);
	p1.ShowPosiotion();
	Point<double> p2(2.3, 345.4);
	p2.ShowPosiotion();

	Point<char> p3('a', 'f');
	p3.ShowPosiotion();
}
//메인파일 끝 //////////////////////////////////////////////////////