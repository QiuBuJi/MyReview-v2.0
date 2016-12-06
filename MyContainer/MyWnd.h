#pragma once
#include <windows.h>

#ifndef MY_WND
#define MY_WND
#define CLASS_NAME L"CContainer"
#define WINDO_NAME L"cba"

/*
* ��    ����WNDDATAEX
* ��    �ߣ�����
* ʱ    �䣺
*          2016��12��2�� ---
*
* ��    ע��
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
 * ��    ����CMyWnd
 * ��    �ߣ�����
 * ʱ    �䣺
 *          2016��12��2�� ~5h ������;���ӷ�����InitWndData��CreateWnd��MessageQueue��GetWnd��GetIns��InitClsData�ȡ�
 *
 * ��    ע��
 */
class CMyWnd
{
protected:
	HWND      hWnd = NULL;//�����������ھ����
	HINSTANCE hIns = NULL;//ʵ�����

public:
	WNDCLASSEX WndClsEx; //���ڣ������ݡ�
	WNDDATAEX  WndDataEx;//���ڣ�����ʱ���ݡ�

public:
	 CMyWnd();
	 CMyWnd(HINSTANCE hInstance);
	~CMyWnd();

	//��ȡ����
	HWND GetWnd() const;
	//��ȡʵ��
	HINSTANCE GetIns() const;
	//������Ϣ�жӡ�����Ϣ��
	void MessageQueue();

protected:
	//�������ڣ����ؾ����
	bool CreateWnd();

private:
	//���õġ��ص���������
	static LRESULT CALLBACK DefWinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	//��ʼ�������������ݡ�
	void InitClsData();
	//��ʼ�������������ݡ�
	void InitWndData();
	//
	//
	//
};

#endif // MY_WND
