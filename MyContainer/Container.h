#pragma once
#include <windows.h>
#include "BaseWnd.h"
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
class CContainer:public CBaseWnd
{
private:
	CArea AreaSet[100];//��CArea-���͡����ݵļ���

public:
	//CContainer();
	CContainer(HINSTANCE hInstance);
	CContainer(HINSTANCE hInstance, SIZE  size);
	CContainer(HINSTANCE hInstance, POINT position);
	CContainer(HINSTANCE hInstance, POINT position, SIZE size);
   ~CContainer();


};

#endif // CONTAINER
