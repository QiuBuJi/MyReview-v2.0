#include "Area.h"
#include <iostream>
#include "Container.h"
#include "LinkedList.h"
using namespace std;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//SIZE  sz = { 900,700 };
	//POINT pt = { 500,100 };
	//CContainer cn(hInstance, pt, sz);
	//
	//cn.Hide();
	//cn.Show();

	CLinkedList<ULONG> ll;
	ll.Insert(0, 1);

	ULONG a = 10;//1000000
	for(ULONG i = 1; i < a; i++)
	{
		ll.Insert(i - 1, i);
	}

	int b = 1;

	//2016年12月4日23:24:10
	//2016年12月5日09:35:21

	//ll.Append(1);


	//cn.MessageQueue();
}

