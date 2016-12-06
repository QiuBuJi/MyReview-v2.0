#pragma once
#include "MyArea.h"
#include <windows.h>
#include "MyWnd.h"
#ifndef BASE_WND
#define BASE_WND

/*
* 类    名：CBaseWnd
* 作    者：吴攀
* 时    间：
*          2016年12月1日 ~1h 创建类
*          2016年12月2日 ~2h 继承类CMyWnd，添加：Show、Hide、WinProc、InitData等方法。
*
* 备    注：
*/
class CMyBaseWnd :public CMyArea, public CMyWnd
{
public:
	CMyBaseWnd();
	~CMyBaseWnd();
	CMyBaseWnd(HINSTANCE hInstance);
	CMyBaseWnd(HINSTANCE hInstance, SIZE  size);
	CMyBaseWnd(HINSTANCE hInstance, POINT position);
	CMyBaseWnd(HINSTANCE hInstance, POINT position, SIZE size);

	//设置位置
	virtual void SetPosi(POINT val);
	//设置尺寸	 
	virtual void SetSize(SIZE val);
	//显示窗口
	virtual void Show(int nCmdShow = SW_NORMAL);
	//隐藏窗口
	virtual void Hide();
	//销毁窗口
	virtual void DestroyWnd();
private:
	//公用的“回调函数”。
	static LRESULT  CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	//初始化
	virtual void InitData();
};

#endif // BASE_WND
