#pragma once
#include <windows.h>
#include "MyBaseWnd.h"
#ifndef CONTAINER
#define CONTAINER

/*
 * ��    ����CContainer
 * ��    �ߣ�����
 * ʱ    �䣺
 *          2016��12��1�� ~1h ������
 *
 * ��    ע��
 */
class CMyContainer:public CMyBaseWnd
{
private:
	CMyArea AreaSet[100];//��CArea-���͡����ݵļ���

public:
	//CContainer();
	CMyContainer(HINSTANCE hInstance);
	CMyContainer(HINSTANCE hInstance, SIZE  size);
	CMyContainer(HINSTANCE hInstance, POINT position);
	CMyContainer(HINSTANCE hInstance, POINT position, SIZE size);
   ~CMyContainer();


};

#endif // CONTAINER
