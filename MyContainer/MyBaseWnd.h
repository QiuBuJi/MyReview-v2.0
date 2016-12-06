#pragma once
#include "MyArea.h"
#include <windows.h>
#include "MyWnd.h"
#ifndef BASE_WND
#define BASE_WND

/*
* ��    ����CBaseWnd
* ��    �ߣ�����
* ʱ    �䣺
*          2016��12��1�� ~1h ������
*          2016��12��2�� ~2h �̳���CMyWnd����ӣ�Show��Hide��WinProc��InitData�ȷ�����
*
* ��    ע��
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

	//����λ��
	virtual void SetPosi(POINT val);
	//���óߴ�	 
	virtual void SetSize(SIZE val);
	//��ʾ����
	virtual void Show(int nCmdShow = SW_NORMAL);
	//���ش���
	virtual void Hide();
	//���ٴ���
	virtual void DestroyWnd();
private:
	//���õġ��ص���������
	static LRESULT  CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	//��ʼ��
	virtual void InitData();
};

#endif // BASE_WND
