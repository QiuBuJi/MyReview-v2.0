#include "MyBitmap.h"
//#include <atlimage.h>
//#include <afx.h>
//#include <afxwin.h>
//#include <afxstr.h>

CMyBitmap::CMyBitmap(){}

CMyBitmap::CMyBitmap(HINSTANCE hInstance) : CMyBaseWnd(hInstance){
}

CMyBitmap::~CMyBitmap()
{
	if(hDc)
	{
		ReleaseDC(hWnd, hDc);
		hDc = NULL;
	}
	if(hMemDc)
	{
		ReleaseDC(hWnd, hMemDc);
		hMemDc = NULL;
	}
}

bool CMyBitmap::LoadBmp(TCHAR *Path)
{
	HBITMAP hbmp = (HBITMAP)LoadImage(hIns, Path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
	//HBITMAP bmp = CreateCompatibleBitmap(hDc, 200, 200);
	//SelectObject(hMemDc, hbmp);
	SelectBitmap(hMemDc, hbmp);

	//BLENDFUNCTION bf;
	//bf.AlphaFormat = AC_SRC_ALPHA;
	//bf.BlendOp = AC_SRC_OVER;
	//bf.BlendFlags = 0;
	//bf.SourceConstantAlpha = 255;
	//AlphaBlend(hDc, 0, 0, 1000, 900, hMemDc, 0, 0, 1000, 900, bf);
	//SetStretchBltMode(hMemDc,)
	//CreateFile(L"")
	//CImage cimg;
	//CFile cfile;
	//CDC dc;
	//dc.CreateCompatibleDC(&dc);
	

	//BitBlt(NULL, 0, 0, 5, 5, NULL, 0, 0, SRCCOPY);
	//StretchBlt(hDc, 0, 0, 1000, 900, hMemDc, 0, 0, 1000, 900, SRCCOPY);
	DeleteObject(hbmp);

	return false;
}

void CMyBitmap::Show(int nCmdShow /*= SW_NORMAL*/)
{
	CMyBaseWnd::Show(nCmdShow);
	hDc    = GetDC(hWnd);
	hMemDc = CreateCompatibleDC(hDc);;
// 	HANDLE handle = CreateFile(L"", 0, 0, 0, 0, 0, 0);
// 	ReadFile(handle, NULL, 0, 0, 0);
// 	GetFileSize(handle, 0);
// 	CloseHandle(handle);
	//CreateDIBSection()
}
