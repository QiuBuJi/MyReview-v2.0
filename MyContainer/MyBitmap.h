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
	HDC hDc    = NULL;
	HDC hMemDc = NULL;
	
public:
	CMyBitmap();
	CMyBitmap(HINSTANCE hInstance);
	virtual ~CMyBitmap();

	//º”‘ÿŒªÕº
	virtual bool LoadBmp(TCHAR *Path);

	virtual void Show(int nCmdShow = SW_NORMAL) override;
	
	
};

#endif // MY_BITMAP
