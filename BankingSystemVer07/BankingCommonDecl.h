#ifndef __BANKINGCOMMONDECL_H__
#define __BANKINGCOMMONDECL_H__
#include <iostream>
#include <cstring>
#include <assert.h>

//메모리 누수를 위한 체크
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h> 
#include <crtdbg.h>  
// 메모리 누수 끝 ------

#define MAX 100	//이름과 잔고 최대 갯수를뜻함
/*
참고로 클래스 이름은 Accout 가 아닌 accout 임을 참고바람.

Ver06에 가상함수, 보통예금계좌, 신용계좌 추가되었다.
*/

using namespace std;

enum { MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

#endif // !__BANKINGCOMMONDECL_H__
