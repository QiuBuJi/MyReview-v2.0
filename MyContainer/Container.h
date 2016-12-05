#pragma once
#include <windows.h>
#include "BaseWnd.h"
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
class CContainer:public CBaseWnd
{
private:
	CArea AreaSet[100];//“CArea-类型”数据的集合

public:
	//CContainer();
	CContainer(HINSTANCE hInstance);
	CContainer(HINSTANCE hInstance, SIZE  size);
	CContainer(HINSTANCE hInstance, POINT position);
	CContainer(HINSTANCE hInstance, POINT position, SIZE size);
   ~CContainer();


};

#endif // CONTAINER
