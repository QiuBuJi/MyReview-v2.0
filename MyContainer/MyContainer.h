#pragma once
#include <windows.h>
#include "MyBaseWnd.h"
#ifndef CONTAINER
#define CONTAINER

/*
 * 类    名：CContainer
 * 作    者：吴攀
 * 时    间：
 *          2016年12月1日 ~1h 创建类
 *
 * 备    注：
 */
class CMyContainer:public CMyBaseWnd
{
private:
	CMyArea AreaSet[100];//“CArea-类型”数据的集合

public:
	//CContainer();
	CMyContainer(HINSTANCE hInstance);
	CMyContainer(HINSTANCE hInstance, SIZE  size);
	CMyContainer(HINSTANCE hInstance, POINT position);
	CMyContainer(HINSTANCE hInstance, POINT position, SIZE size);
   ~CMyContainer();


};

#endif // CONTAINER
