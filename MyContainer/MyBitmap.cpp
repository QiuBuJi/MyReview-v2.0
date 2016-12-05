#include "MyBitmap.h"


CMyBitmap::CMyBitmap(){}

CMyBitmap::CMyBitmap(HINSTANCE hInstance) : CMyWnd(hInstance){}

CMyBitmap::~CMyBitmap()
{
}

bool CMyBitmap::LoadBmp(TCHAR *Path)
{
	HBITMAP Bmp = LoadBitmap(0, Path);

	return false;
}

bool CMyBitmap::Show(int nCmdShow /*= SW_NORMAL*/)
{
	this->CreateWnd();
}
