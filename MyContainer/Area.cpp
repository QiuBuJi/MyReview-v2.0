#include "Area.h"

CArea::CArea(){
	Posi = { 0, 0 };
	Size = { 0, 0 };
}

CArea::~CArea(){
}
CArea::CArea(SIZE size){
	SetSize(size);
}
CArea::CArea(POINT position){
	SetPosi(position);
}
CArea::CArea(POINT position, SIZE size){
	SetPosi(position);
	SetSize(size);
}

//////////////////////////Get��Set����////////////////////////////////////////////////
POINT CArea::GetPosi() const         { return Posi; }
void  CArea::SetPosi(POINT position) { Posi = position;  }
SIZE  CArea::GetSize() const         { return Size; }
void  CArea::SetSize(SIZE size)      { Size = size;  }

PTCHAR CArea::ToString(){
#define LENGTH 256
#define WIDE   20
	//////////////////////��ʼ��////////////////////////////////////////////////////
	static
	TCHAR buffer[LENGTH];//�ܻ���
	TCHAR number[WIDE];  //����ת�ַ��������ŵĻ��档
	ZeroMemory(buffer, LENGTH*sizeof TCHAR);
	ZeroMemory(number, WIDE  *sizeof TCHAR);

	//////////////////////�򻯷���-��////////////////////////////////////////////////////
#define TO_NUMBER(num) _ltot_s     (num, number, WIDE, 10)//�ѡ�num-��ֵ��ת��Ϊ���ַ��������洢����number-���桱��
#define APEND_STR(str) StringCchCat(buffer, LENGTH, str)  //�ѡ�str-�ַ�����׷�ӵ���buffer-���桱β����
#define APEND_NUM(num) TO_NUMBER   (num);APEND_STR(number)//�ϡ�2���ļ���

	//////////////////////�ѡ��ַ���������������ת�ַ�����׷�ӵ���buffer-���桱////////////////////////////////////////////////////
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
	return buffer;//��buffer-���桱���ڲ��ǡ�static-��̬�����͡�
}