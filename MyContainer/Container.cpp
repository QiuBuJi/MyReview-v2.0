#include "Container.h"

CContainer::CContainer(HINSTANCE hInstance) :CMyWnd(hInstance){
}

//CContainer::CContainer()
//{
//}

CContainer::CContainer(HINSTANCE hInstance, SIZE size) :CContainer(hInstance){
	CArea::SetSize(size);
}

CContainer::CContainer(HINSTANCE hInstance, POINT position) :CContainer(hInstance){
	CArea::SetPosi(position);
}

CContainer::CContainer(HINSTANCE hInstance, POINT position, SIZE size) :CContainer(hInstance){
	CArea::SetPosi(position);
	CArea::SetSize(size);
}

CContainer::~CContainer()
{
}

void CContainer::InitData()
{
	SIZE  sz = GetSize();
	POINT pt = GetPosi();

	WndDataEx.x          = pt.x;
	WndDataEx.y          = pt.y;
	WndDataEx.nWidth     = sz.cx;
	WndDataEx.nHeight    = sz.cy;
	WndClsEx.lpfnWndProc = WinProc;
}

void CContainer::SetPosi(POINT position){
	CArea::SetPosi(position);
	SIZE sz = GetSize();
	if(hWnd)
		SetWindowPos(hWnd, NULL, position.x, position.y, sz.cx, sz.cy, SWP_NOZORDER);
}

void CContainer::SetSize(SIZE size)
{
	CArea::SetSize(size);
	POINT pt = GetPosi();
	if (hWnd)
		SetWindowPos(hWnd, NULL, pt.x, pt.y, size.cx, size.cy, SWP_NOZORDER);
}

void CContainer::Show(int nCmdShow)
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

void CContainer::Hide()
{
	if(hWnd)
		ShowWindow(hWnd, SW_HIDE);
}

void CContainer::AddView(CArea *Area)
{
	Area->AreaParent = this;
}

LRESULT CALLBACK CContainer::WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	CContainer *Con = NULL;
	Con = (CContainer*)GetWindowLongPtr(hWnd, GWLP_USERDATA);

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
			switch(wParam)
			{
			case VK_ESCAPE:
				PostMessage(hWnd, WM_DESTROY, 0, 0);
				break;
			default:
				break;
			}
		}break;
	case WM_SIZE: {
			if(Con != nullptr)
			{
				SIZE sz = { (LONG)HIWORD(lParam), (LONG)LOWORD(lParam) };
				(*Con).CArea::SetSize(sz);
			}
			
		}break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

