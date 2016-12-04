#pragma once
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

/*
 * 类    名：CRect
 * 作    者：吴攀
 * 时    间：
 *          2016年12月2日 --- 创建类
 *
 * 备    注：
 */
struct CRect
{
	POINT Posi;//Position 位置
	SIZE  Size;//         尺寸
};


/*
 * 类    名：CArea
 * 作    者：吴攀
 * 时    间：
 *          2016年12月1日 ~6h 创建类
 *          2016年12月2日 --- (改)私有继承“CRect”类。给方法添加了virtual。
 * 
 * 备    注：
 */
class CArea :private CRect
{
private:

public:
	CArea *AreaParent = NULL;//父类的Area

public:
	CArea();
   ~CArea();
	CArea(SIZE  size);
	CArea(POINT position);
	CArea(POINT position, SIZE size);

	//获取位置
	virtual POINT GetPosi() const;
	//设置位置
	virtual void SetPosi(POINT position);
	//获取尺寸
	virtual SIZE GetSize() const;
	//设置尺寸
	virtual void SetSize(SIZE size);
	//“内部数据”转“字符串”输出。
	virtual PTCHAR ToString();
};

