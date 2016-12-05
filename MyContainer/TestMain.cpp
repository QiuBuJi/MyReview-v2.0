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

	ULONG a = 10;//1000000


// 	for(ULONG i = 1; i < a; i++)
// 	{
// 		ll.Append(i + 1);
// 	}
	ll.Append('a');
	ll.Append('b');
	ll.Append('c');
	ll.Append('d');
	ll.Append('e');
	ll.Append('f');
	ll.Append('g');
	ll.Append('h');
	ll.Append('i');

#define file_name L"C:/Users/Administrator/Desktop/TheData.txt"
	ll.SaveToFile(file_name);
	ll.Clear();
	ll.ReadFromFile(file_name);
	

	//2016年12月4日23:24:10
	//2016年12月5日09:35:21
	//2016年12月5日10:04:30

	//ll.Append(1);

	//2016年12月5日10:16:00

	//cn.MessageQueue();
}

