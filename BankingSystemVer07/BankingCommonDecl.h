#ifndef __BANKINGCOMMONDECL_H__
#define __BANKINGCOMMONDECL_H__
#include <iostream>
#include <cstring>
#include <assert.h>

//�޸� ������ ���� üũ
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h> 
#include <crtdbg.h>  
// �޸� ���� �� ------

#define MAX 100	//�̸��� �ܰ� �ִ� ����������
/*
����� Ŭ���� �̸��� Accout �� �ƴ� accout ���� ����ٶ�.

Ver06�� �����Լ�, ���뿹�ݰ���, �ſ���� �߰��Ǿ���.
*/

using namespace std;

enum { MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

#endif // !__BANKINGCOMMONDECL_H__
