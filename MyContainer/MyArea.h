#pragma once
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#ifndef AREA
#define AREA

/*
 * ��    ����CRect
 * ��    �ߣ�����
 * ʱ    �䣺
 *          2016��12��2�� --- ������
 *
 * ��    ע��
 */
struct CMyRect
{
	POINT Posi;//Position λ��
	SIZE  Size;//         �ߴ�
};


/*
 * ��    ����CArea
 * ��    �ߣ�����
 * ʱ    �䣺
 *          2016��12��1�� ~6h ������
 *          2016��12��2�� --- (��)˽�м̳С�CRect���ࡣ�����������virtual��
 * 
 * ��    ע��
 */
class CMyArea :private CMyRect
{
private:

public:
	CMyArea *AreaParent = NULL;//�����Area

public:
	CMyArea();
   ~CMyArea();
	CMyArea(SIZE  size);
	CMyArea(POINT position);
	CMyArea(POINT position, SIZE size);

	//��ȡλ��
	virtual POINT GetPosi() const;
	//����λ��
	virtual void SetPosi(POINT position);
	//��ȡ�ߴ�
	virtual SIZE GetSize() const;
	//���óߴ�
	virtual void SetSize(SIZE size);
	//���ڲ����ݡ�ת���ַ����������
	virtual PTCHAR ToString();
};

#endif // AREA
