#include "Area.h"
#include <iostream>
#include "Container.h"
#include "LinkedList.h"
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

	CLinkedList<char> ll;

	ULONG a = 10;//1000000


// 	for(ULONG i = 1; i < a; i++)
// 	{
// 		ll.Append(i + 1);
// 	}
	ll.Append('a');
	ll.Append('b');
	ll.Append('c');
	ll.Append('d');

	ll << 'E' << 'F';
	ll >> 'S' >> 'B';

	char da = ll[6];

	//2016年12月4日23:24:10
	//2016年12月5日09:35:21
	//2016年12月5日10:04:30

	//ll.Append(1);

	//2016年12月5日10:16:00

	//cn.MessageQueue();
}

