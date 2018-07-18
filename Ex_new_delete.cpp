/*
*	2차원 평면상에서의 좌표를 표현할 수 있는 구조체를 다음과같이 정의됨
*	typedef struct __Point {
*		int xpos;
*		int ypos;
*	}Point;
*	위의 구조체를 기반으로 두점의 합을 계산하는 함수를 다음의 형태로 정의하고
*	(덧셈결과는 함수의 반환을 통해서 얻게 한다.)
*	Point& PntAdder(const Point &p1, const Point &p2)
*	
*	임의의 두 점을 선언한뒤, 위 함수를 이용해 덧셈연산을 진행하는 main 함수를 정의해보자.
*	단, 구조체 Point 과녈ㄴ 변수의 선언은 무조건 new 연산자를 이용해서 진행해야 하며, 할당된 
*	메모리 공간의 소멸도 철저해야 한다.
*	1. 동적할당 한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가?
*	2. 함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가 ?
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2) {
	Point * res = new Point;
	res->xpos = p1.xpos + p2.xpos;
	res->ypos = p1.ypos + p2.ypos;
	return *res;
	//delete res;
}

int main(void) {
	//실수한 부분들. 이렇게 선언하면 안됨 실행은 되나 잘못됨.
	//Point p3 = { 1, 2 };
	//Point p4 = { 2,3 };
	//PntAdder(p3, p4);

	//pptr1 주소를 선언 하고 x,y의 값을 대입
	Point *pptr1 = new Point;
	pptr1->xpos = 1;
	pptr1->ypos = 1;

	//pptr2 주소를 선언 하고 x,y의 값을 대입
	Point *pptr2 = new Point;
	pptr2->xpos = 2;
	pptr2->ypos = 2;

	//pref주소값으로 리턴되는 PntAdder함수를 실행
	Point &pref = PntAdder(*pptr1, *pptr2);
	cout << "("<< pref.xpos << "," << pref.ypos << ")"<< endl;
	//동적할당된 변수들 모두 해제.
	delete pptr1;
	delete pptr2;
	delete &pref;
}
