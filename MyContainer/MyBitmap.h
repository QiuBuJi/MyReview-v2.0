#pragma once
#include <windows.h>
#include "MyBaseWnd.h"
#include <windowsx.h>
#pragma comment(lib,"Msimg32.lib")
#ifndef MY_BITMAP
#define MY_BITMAP

class CMyBitmap:public CMyBaseWnd
{
private:
	HDC     hDc    = NULL;
	HDC     hMemDc = NULL;
	HBITMAP hBmp   = NULL;
public:
	CMyBitmap();
	CMyBitmap(HINSTANCE hInstance);
	virtual ~CMyBitmap();

	//加载位图
	virtual bool LoadBmp(TCHAR *Path);
	//显示窗口
	virtual void Show(int nCmdShow = SW_NORMAL) override;
	
	
};

#endif // MY_BITMAP
