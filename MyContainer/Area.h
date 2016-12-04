#pragma once
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

/*
 * ��    ����CRect
 * ��    �ߣ�����
 * ʱ    �䣺
 *          2016��12��2�� --- ������
 *
 * ��    ע��
 */
struct CRect
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
class CArea :private CRect
{
private:

public:
	CArea *AreaParent = NULL;//�����Area

public:
	CArea();
   ~CArea();
	CArea(SIZE  size);
	CArea(POINT position);
	CArea(POINT position, SIZE size);

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

