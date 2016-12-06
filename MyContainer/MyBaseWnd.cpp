#include "MyBaseWnd.h"


CMyBaseWnd::CMyBaseWnd()
{
}


CMyBaseWnd::~CMyBaseWnd()
{
}

CMyBaseWnd::CMyBaseWnd(HINSTANCE hInstance) :CMyWnd(hInstance){}

CMyBaseWnd::CMyBaseWnd(HINSTANCE hInstance, SIZE size) :CMyBaseWnd(hInstance){}

CMyBaseWnd::CMyBaseWnd(HINSTANCE hInstance, POINT position) : CMyBaseWnd(hInstance){}

CMyBaseWnd::CMyBaseWnd(HINSTANCE hInstance, POINT position, SIZE size) : CMyBaseWnd(hInstance){}

void CMyBaseWnd::InitData()
{
	SIZE  sz = GetSize();
	POINT pt = GetPosi();

	WndDataEx.x = pt.x;
	WndDataEx.y = pt.y;
	WndDataEx.nWidth = sz.cx;
	WndDataEx.nHeight = sz.cy;
	WndClsEx.lpfnWndProc = WinProc;
}

void CMyBaseWnd::SetPosi(POINT position){
	CMyArea::SetPosi(position);
	SIZE sz = GetSize();
	if (hWnd)
		SetWindowPos(hWnd, NULL, position.x, position.y, sz.cx, sz.cy, SWP_NOZORDER);
}

void CMyBaseWnd::SetSize(SIZE size)
{
	CMyArea::SetSize(size);
	POINT pt = GetPosi();
	if (hWnd)
		SetWindowPos(hWnd, NULL, pt.x, pt.y, size.cx, size.cy, SWP_NOZORDER);
}

void CMyBaseWnd::Show(int nCmdShow)
{
	if (!hWnd) {
		InitData();
		CreateWnd();
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG)this);//把本类，保存到hWnd的“GWLP_USERDATA”中去。便于WinProc回调函数，获取。
	}
	else
	{
		ShowWindow(hWnd, nCmdShow);
	}
}

void CMyBaseWnd::Hide()
{
	if (hWnd)
		ShowWindow(hWnd, SW_HIDE);
}

LRESULT CALLBACK CMyBaseWnd::WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	CMyBaseWnd *Con = NULL;
	Con = (CMyBaseWnd*)GetWindowLongPtr(hWnd, GWLP_USERDATA);

	switch (msg)
	{
	case WM_CREATE: {

	}break;
	case WM_PAINT: {
					   PAINTSTRUCT ps;
					   HDC         hDc;

					   hDc = BeginPaint(hWnd, &ps);
					   EndPaint(hWnd, &ps);
	}break;
	case WM_DESTROY: {
						 PostQuitMessage(0);
	}break;
	case WM_KEYDOWN: {
						 switch (wParam)
						 {
						 case VK_ESCAPE:
							 PostMessage(hWnd, WM_DESTROY, 0, 0);
							 break;
						 default:
							 break;
						 }
	}break;
	case WM_SIZE: {
					  if (Con != nullptr)
					  {
						  SIZE sz = { (LONG)HIWORD(lParam), (LONG)LOWORD(lParam) };
						  (*Con).CMyArea::SetSize(sz);
					  }

	}break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}
