#include <iostream>
#include "MyContainer.h"
#include "MyLinkedList.h"
#include "MyBitmap.h"
using namespace std;

int WINAPI WinMain(_In_     HINSTANCE hInstance, 
				   _In_opt_ HINSTANCE hPrevInstance, 
				   _In_     LPSTR     lpCmdLine, 
				   _In_     int       nShowCmd)
{
	//SIZE  sz = { 900,700 };
	//POINT pt = { 500,100 };
	//CContainer cn(hInstance, pt, sz);
	//
	//cn.Hide();
	//cn.Show();

	CMyBitmap mBmp(hInstance);

	mBmp.SetSize({ 1280,960 });
	mBmp.Show();
	mBmp.LoadBmp(L"C:/Users/Administrator/Desktop/src.bmp");
	mBmp.MessageQueue();

	//2016年12月4日23:24:10
	//2016年12月5日09:35:21
	//2016年12月5日10:04:30

	//ll.Append(1);

	//2016年12月5日10:16:00

	//cn.MessageQueue();
}

