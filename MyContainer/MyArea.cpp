#include "MyArea.h"

CMyArea::CMyArea(){
	Posi = { 0, 0 };
	Size = { 0, 0 };
}

CMyArea::~CMyArea(){
}
CMyArea::CMyArea(SIZE size){
	SetSize(size);
}
CMyArea::CMyArea(POINT position){
	SetPosi(position);
}
CMyArea::CMyArea(POINT position, SIZE size){
	SetPosi(position);
	SetSize(size);
}

//////////////////////////Get、Set方法////////////////////////////////////////////////
POINT CMyArea::GetPosi() const         { return Posi; }
void  CMyArea::SetPosi(POINT position) { Posi = position;  }
SIZE  CMyArea::GetSize() const         { return Size; }
void  CMyArea::SetSize(SIZE size)      { Size = size;  }

PTCHAR CMyArea::ToString(){
#define LENGTH 256
#define WIDE   20
	//////////////////////初始化////////////////////////////////////////////////////
	static
	TCHAR buffer[LENGTH];//总缓存
	TCHAR number[WIDE];  //数字转字符串，后存放的缓存。
	ZeroMemory(buffer, LENGTH*sizeof TCHAR);
	ZeroMemory(number, WIDE  *sizeof TCHAR);

	//////////////////////简化方法-宏////////////////////////////////////////////////////
#define TO_NUMBER(num) _ltot_s     (num, number, WIDE, 10)//把“num-数值”转换为“字符串”，存储到“number-缓存”。
#define APEND_STR(str) StringCchCat(buffer, LENGTH, str)  //把“str-字符串”追加到“buffer-缓存”尾部。
#define APEND_NUM(num) TO_NUMBER   (num);APEND_STR(number)//上↑2个的集合

	//////////////////////把“字符串常量”或“数字转字符串”追加到“buffer-缓存”////////////////////////////////////////////////////
	APEND_STR(L"posi{");  //posi
	APEND_NUM(Posi.x);
	APEND_STR(L",");
	APEND_NUM(Posi.y);
	APEND_STR(L"} size{");//size
	APEND_NUM(Size.cx);
	APEND_STR(L",");
	APEND_NUM(Size.cy);
	APEND_STR(L"} ");

#undef LENGTH
#undef WIDE
	return buffer;//“buffer-缓存”在内部是“static-静态”类型。
}