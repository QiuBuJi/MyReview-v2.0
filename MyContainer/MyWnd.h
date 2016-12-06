#pragma once
#include <windows.h>

#ifndef MY_WND
#define MY_WND
#define CLASS_NAME L"CContainer"
#define WINDO_NAME L"cba"

/*
* 类    名：WNDDATAEX
* 作    者：吴攀
* 时    间：
*          2016年12月2日 ---
*
* 备    注：
*/
struct WNDDATAEX
{
	DWORD     dwExStyle;
	LPTSTR    lpClassName;
	LPTSTR    lpWindowName;
	DWORD     dwStyle;
	int       x;
	int       y;
	int       nWidth;
	int       nHeight;
	HWND      hWndParent;
	HMENU     hMenu;
	HINSTANCE hInstance;
	LPVOID    lpParam;
};

/*
 * 类    名：CMyWnd
 * 作    者：吴攀
 * 时    间：
 *          2016年12月2日 ~5h 创建类;增加方法：InitWndData、CreateWnd、MessageQueue、GetWnd、GetIns、InitClsData等。
 *
 * 备    注：
 */
class CMyWnd
{
protected:
	HWND      hWnd = NULL;//本容器，窗口句柄。
	HINSTANCE hIns = NULL;//实例句柄

public:
	WNDCLASSEX WndClsEx; //窗口，类数据。
	WNDDATAEX  WndDataEx;//窗口，创建时数据。

public:
	 CMyWnd();
	 CMyWnd(HINSTANCE hInstance);
	~CMyWnd();

	//获取窗口
	HWND GetWnd() const;
	//获取实例
	HINSTANCE GetIns() const;
	//处理“消息列队”的消息。
	void MessageQueue();

protected:
	//创建窗口，返回句柄。
	bool CreateWnd();

private:
	//公用的“回调函数”。
	static LRESULT CALLBACK DefWinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	//初始化，窗口类数据。
	void InitClsData();
	//初始化，窗口类数据。
	void InitWndData();
	//
	//
	//
};

#endif // MY_WND
