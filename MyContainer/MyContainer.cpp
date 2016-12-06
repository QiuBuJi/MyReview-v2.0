#include "MyContainer.h"

CMyContainer::CMyContainer(HINSTANCE hInstance) :CMyBaseWnd(hInstance){}

// CMyContainer::CMyContainer()
// {
// }

CMyContainer::CMyContainer(HINSTANCE hInstance, SIZE size) :CMyBaseWnd(hInstance, size){}

CMyContainer::CMyContainer(HINSTANCE hInstance, POINT position) : CMyBaseWnd(hInstance, position){}

CMyContainer::CMyContainer(HINSTANCE hInstance, POINT position, SIZE size) : CMyBaseWnd(hInstance, position, size){}

CMyContainer::~CMyContainer()
{
}


void CMyContainer::AddView(CMyArea *Area)
{
	Area->AreaParent = this;
}
