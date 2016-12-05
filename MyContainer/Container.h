#pragma once
#include "Area.h"
#include <windows.h>
#include "MyWnd.h"
#ifndef CONTAINER
#define CONTAINER

/*
 * ��    ����CContainer
 * ��    �ߣ�����
 * ʱ    �䣺
 *          2016��12��1�� ~1h ������
 *          2016��12��2�� ~2h �̳���CMyWnd����ӣ�Show��Hide��WinProc��InitData�ȷ�����
 *
 * ��    ע��
 */
class CContainer :public CArea, public CMyWnd
{
private:
	CArea AreaSet[100];//��CArea-���͡����ݵļ���

public:
	//CContainer();
	CContainer(HINSTANCE hInstance);
	CContainer(HINSTANCE hInstance, SIZE  size);
	CContainer(HINSTANCE hInstance, POINT position);
	CContainer(HINSTANCE hInstance, POINT position, SIZE size);
   ~CContainer();

   //����λ��
   virtual void SetPosi(POINT val);
   //���óߴ�	 
   virtual void SetSize(SIZE val);
   //��ʾ����
   void Show(int nCmdShow = SW_NORMAL);
   //���ش���
   void Hide();
   //
   void AddView(CArea *Area);
private:
	//
	static LRESULT  CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	//��ʼ��
	void InitData();
};

#endif // CONTAINER
