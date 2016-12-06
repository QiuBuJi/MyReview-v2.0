#include "MyWnd.h"

CMyWnd::CMyWnd(){
	InitClsData();
	InitWndData();
}

CMyWnd::CMyWnd(HINSTANCE hInstance) :CMyWnd(){
	hIns = hInstance;
}

CMyWnd::~CMyWnd()
{
}

LRESULT CALLBACK CMyWnd::DefWinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		PAINTSTRUCT ps;
		HDC         hDc;

		hDc = BeginPaint(hWnd, &ps);
		      EndPaint  (hWnd, &ps);
		break;
	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		default:
			break;
		}
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

void CMyWnd::InitClsData()
{
	HICON hIcon = LoadIcon(NULL, IDI_APPLICATION);
	int   Size = sizeof WndClsEx;
	ZeroMemory(&WndClsEx, Size);

	//////////////////////初始化-窗口类////////////////////////////////////////////////////
	WndClsEx.cbSize        = Size;
	WndClsEx.cbClsExtra    = 0;
	WndClsEx.cbClsExtra    = 0;
	WndClsEx.hInstance     = hIns;
	WndClsEx.hIcon         = hIcon;
	WndClsEx.hIconSm       = hIcon;
	WndClsEx.hCursor       = LoadCursor(NULL, IDC_ARROW);
	WndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClsEx.lpfnWndProc   = DefWinProc;
	WndClsEx.lpszClassName = CLASS_NAME;
	WndClsEx.lpszMenuName  = NULL;
	WndClsEx.style         = CS_HREDRAW | CS_VREDRAW;
}

void CMyWnd::InitWndData()
{
	ZeroMemory(&WndDataEx, sizeof WndDataEx);

	WndDataEx.dwExStyle    = NULL;
	WndDataEx.lpClassName  = CLASS_NAME;
	WndDataEx.lpWindowName = WINDO_NAME;
	WndDataEx.dwStyle      = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
	WndDataEx.x            = 0;
	WndDataEx.y            = 0;
	WndDataEx.nWidth       = 300;
	WndDataEx.nHeight      = 300;
	WndDataEx.hWndParent   = NULL;
	WndDataEx.hMenu        = NULL;
	WndDataEx.hInstance    = hIns;
	WndDataEx.lpParam      = NULL;
}

bool CMyWnd::CreateWnd()
{
	RegisterClassEx(&WndClsEx);//注册，窗口类。

	//////////////////////创建窗口////////////////////////////////////////////////////
	HWND hWnd = CreateWindowEx(
					WndDataEx.dwExStyle   ,
					WndDataEx.lpClassName ,
					WndDataEx.lpWindowName,
					WndDataEx.dwStyle     ,
					WndDataEx.x           ,
					WndDataEx.y           ,
					WndDataEx.nWidth      ,
					WndDataEx.nHeight     ,
					WndDataEx.hWndParent  ,
					WndDataEx.hMenu       ,
					WndDataEx.hInstance = hIns,
					WndDataEx.lpParam);

	this->hWnd = hWnd;
	if(!hWnd)
		return false;
	return true;
}

void CMyWnd::MessageQueue()
{
	MSG msg;
	while (GetMessage(&msg, hWnd, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage (&msg);
	}
}

HWND CMyWnd::GetWnd() const { return hWnd; }

HINSTANCE CMyWnd::GetIns() const { return hIns; }

