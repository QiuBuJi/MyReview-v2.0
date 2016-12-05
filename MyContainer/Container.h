#pragma once
#include "Area.h"
#include <windows.h>
#include "MyWnd.h"
#ifndef CONTAINER
#define CONTAINER

/*
 * 类    名：CContainer
 * 作    者：吴攀
 * 时    间：
 *          2016年12月1日 ~1h 创建类
 *          2016年12月2日 ~2h 继承类CMyWnd，添加：Show、Hide、WinProc、InitData等方法。
 *
 * 备    注：
 */
class CContainer :public CArea, public CMyWnd
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

   //设置位置
   virtual void SetPosi(POINT val);
   //设置尺寸	 
   virtual void SetSize(SIZE val);
   //显示窗口
   void Show(int nCmdShow = SW_NORMAL);
   //隐藏窗口
   void Hide();
   //
   void AddView(CArea *Area);
private:
	//
	static LRESULT  CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	//初始化
	void InitData();
};

#endif // CONTAINER
