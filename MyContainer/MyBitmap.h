#pragma once
#include <windows.h>
#include "MyWnd.h"
#ifndef MY_BITMAP
#define MY_BITMAP
class CMyBitmap :public CMyWnd
{
public:
	CMyBitmap();
	CMyBitmap(HINSTANCE hInstance);
	virtual ~CMyBitmap();

	virtual bool LoadBmp(TCHAR *Path);

	virtual bool Show(int nCmdShow = SW_NORMAL);
};

#endif // MY_BITMAP
