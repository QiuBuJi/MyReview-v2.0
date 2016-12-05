#include "Container.h"

CContainer::CContainer(HINSTANCE hInstance) :CBaseWnd(hInstance){}

//CContainer::CContainer()
//{
//}

CContainer::CContainer(HINSTANCE hInstance, SIZE size) :CContainer(hInstance, size){}

CContainer::CContainer(HINSTANCE hInstance, POINT position) : CContainer(hInstance, position){}

CContainer::CContainer(HINSTANCE hInstance, POINT position, SIZE size) : CContainer(hInstance, position, size){}

CContainer::~CContainer()
{
}
