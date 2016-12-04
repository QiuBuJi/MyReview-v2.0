#pragma once
#include <windows.h>

//双向节点
template<class DataType>
struct CNod
{
	CNod(const DataType &Data){
		this->Data = Data;
	}
	DataType Data; //模板数据
	CNod<DataType>*Prior = NULL;//前节点
	CNod<DataType>*Next  = NULL;//后节点
};

enum Limit
{
	FIRST,//头部
	LAST, //尾部
};

/*
* 类    名：CLinkedList
* 作    者：吴攀
* 时    间：
*          2016年12月3日 ~8h 创建类
*
* 备    注：
*/
template<class Type>
class CLinkedList
{
private:
	CNod<Type> *Home;   //始节点
	CNod<Type> *Last;   //尾节点
	ULONG       Sum;    //长度
	
public:
	 CLinkedList();
	~CLinkedList();

	//添加到尾
	virtual bool Append(const Type &Data);
	//添加到首
	virtual bool AddFirst(const Type &Data);
	//插入中间
	virtual bool Insert(ULONG Index, const Type &Data);
	//插入中间
	virtual bool Insert(const Type &Data, Limit Fist_Or_Last = Last);
	//清除全部
	virtual void Clear();
	//删除节点
	virtual bool Delete(ULONG Index);
	//删除头部节点
	virtual bool DeleteFirst();
	//删除尾部节点
	virtual bool DeleteLast();
	//删除节点
	virtual bool Delete(Limit Fist_Or_Last = Last);
	//取节点
	virtual CNod<Type>* GetNode(ULONG Index);
	//取数据
	virtual Type GetData(ULONG Index);
	//取数据
	virtual Type GetData(Limit Fist_Or_Last = Last);
	//取下标
	virtual ULONG IndexOf(const Type &Data);

	//TODO: ? FindLocalData
	virtual ULONG FindLocalData(const UINT8 &Data, ULONG offset_in_byte = 0);

	//改变指定数据
	virtual bool Replace(ULONG Index, const Type &Data);
	//取长度
	virtual ULONG Length();
	//交换数据
	virtual bool Swap(ULONG Index1, ULONG Index2);

	//TODO: ? 保存数据

	//保存数据到文件
	virtual bool SaveToFile(char*_file_name);
	//读数据从文件
	virtual bool ReadFromFile(char*_file_name);
};
#define UL_MAX     0x80000000UL  //自己看着办，这里只是提醒。加入数据太大，有可能导致崩溃！

template<class Type>
inline CLinkedList<Type>::CLinkedList()
{
	
}

template<class Type>
inline CLinkedList<Type>::~CLinkedList()
{

}

template<class Type>
inline bool CLinkedList<Type>::Append(const Type &Data)
{
	CNod<Type> *temp = new CNod<Type>(Data);//初始化为“Data-数据”。
	//没有处理“temp”为NULL的情况，因为不太可能。已知情况：32位地址，加入数据容量 > 2G。

	if (Last){//“Last-尾节点”有数据，追加到尾部。

//		注释，提高速度。
//  	if(Sum == UL_MAX)//容量已满，不能再加入。
//  		return false;
		temp->Prior = Last;//新节点，设置【前】节点。 *这样，就是“双向链表”的原理之一。
		Last->Next  = temp;//旧节点，设置【后】节点。 *...
		Last        = temp;//设置新的，尾节点。
		Sum++;//增加长度
	}
	else{    //“Last-尾节点”为NULL，初始化数据。
		Home = temp;
		Last = temp;
		Sum  = 1;
	}
	return true;
}

template<class Type>
inline bool CLinkedList<Type>::AddFirst(const Type &Data)
{
	CNod<Type> *temp = new CNod<Type>(Data);//初始化为“Data-数据”。
	//没有处理“temp”为NULL的情况，因为不太可能。

	if (Home){//“Home-尾节点”有数据，追加到尾部。

//		注释，提高速度。
// 		if(Sum == UL_MAX)//容量已满，不能再加入。
//  		return false;
		temp->Next  = Home;//新节点，设置【后】节点。 *这样，就是“双向链表”的原理之一。
		Home->Prior = temp;//旧节点，设置【前】节点。 *...
		Home        = temp;//设置新的，始节点。
		Sum++;
	}
	else{    //“Home-尾节点”为NULL，初始化数据。
		Home = temp;
		Last = temp;
		Sum = 1;
	}
	return true;
}

template<class Type>
inline bool CLinkedList<Type>::Insert(ULONG Index, const Type &Data)
{
	CNod<Type> *temp = Home;//初始化为“Home-首数据”。

//	注释，提高速度。
// 	if(Sum == UL_MAX)//容量已满，不能再加入。
//  		return false;
//  else
	if(Sum == 0 && Index)//限制在“Sum-长度”为0时，只允许在“Index-下标”为0时插入。
		return false;
	else
	if (Index == 0  )AddFirst(Data);//用现成，对应的“AddFirst-添加到开头”方法。
	else
	if (Index == Sum)Append(Data);  //用现成，对应的“Append-追加到尾”方法。
	else
	if (Index >  Sum)//“Index-下标”超出“Sum-总数”范围。
		return false;
	else//正常插入链表
	{
		if(Index < (Sum / 2)){
			for(ULONG i = 0; i < Index; i++)//找到“Index-下标”位置的“Type-类型”数据。
				temp = temp->Next;
		}
		else{
			temp = Last;//初始化为“Last-首数据”。
			for(ULONG i = Sum; i > Index; i--)//找到“Index-下标”位置的“Type-类型”数据。
				temp = temp->Prior;
		}

		CNod<Type> *Nod = new CNod<Type>(Data);//初始化为“Data-数据”。
		//没有处理“temp”为NULL的情况，因为不太可能。

		temp->Prior->Next = Nod;        //为“temp”的前一节点，设置下个节点为“Nod”。
		 Nod->Prior       = temp->Prior;//为“Nod”设置前一节点，为“temp”的前一节点。
		 Nod->Next        = temp;       //为“Nod”设置下个节点，为“temp”。
		temp->Prior       = Nod;        //为“temp”设置下个节点，为“Nod”。
		Sum++;
	}
	return true;
}

template<class Type>
inline bool CLinkedList<Type>::Insert(const Type &Data, Limit Fist_Or_Last /*= Last*/)
{
	bool state = false;
	switch (Fist_Or_Last)
	{
	case Limit::FIRST:state = AddFirst(Data); break;
	case Limit::LAST :state = Append(Data)  ; break;
	}
	return state;
}

template<class Type>
inline void CLinkedList<Type>::Clear()
{
	CNod<Type> *store = NULL,
			   *temp  = Home;//初始化为“Home-首数据”。

	for (ULONG i = 0; i < Sum; i++)//找到“Index-下标”位置的“Type-类型”数据。
	{
		store = temp;      //缓存起来
		temp  = temp->Next;//移到下一节点
		delete  store;     //释放缓存节点的空间
	}
	Home = Last = NULL;//复原为“NULL”数据
	Sum  = 0;          //长度置0
}

template<class Type>
inline bool CLinkedList<Type>::Delete(ULONG Index)
{
	CNod<Type> *temp = Home;//初始化为“Home-首数据”。

	ULONG Len = Sum - 1;
	if (Sum   == 0)return false;
	else
	if (Index == 0)DeleteFirst();
	else
	if (Index == Len)DeleteLast();
	else
	if (Index > Len)//“Index-下标”超出“Sum-总数”范围。
		return false;
	else//正常删除链表
	{
		for (ULONG i = 0; i < Index; i++)//找到“Index-下标”位置的“Type-类型”数据。
			temp = temp->Next;

		//“temp”前后节点，设置直接联系。
		temp->Prior->Next = temp->Next;
		temp->Next->Prior = temp->Prior;
		delete temp;
		Sum--;
	}
	return true;
}

template<class Type>
bool CLinkedList<Type>::DeleteLast()
{
	CNod<Type> *temp = Last;//初始化为“Last-尾数据”。

	if (Last){
		Last = Last->Prior;
		delete temp;
		if (Last == NULL){
			Home  = NULL;
			Sum   = 0;
		}
		else{
			Last->Next = NULL;
			Sum--;
		}
	}
	else
		return false;
	return true;
}

template<class Type>
bool CLinkedList<Type>::DeleteFirst()
{
	CNod<Type> *temp = Home;//初始化为“Home-尾数据”。

	if (Home){
		Home = Home->Next;
		delete temp;
		if (Home == NULL){
			Last  = NULL;
			Sum   = 0;
		}
		else{
			Home->Prior = NULL;
			Sum--;
		}
	}
	else
		return false;
	return true;
}

template<class Type>
inline bool CLinkedList<Type>::Delete(Limit Fist_Or_Last /*= Last*/)
{
	bool state = false;
	switch (Fist_Or_Last)
	{
	case FIRST:state = DeleteFirst();break;
	case LAST :state = DeleteLast() ;break;
	}
	return state;
}

template<class Type>
inline CNod<Type>* CLinkedList<Type>::GetNode(ULONG Index)
{

	CNod<Type> *temp = Home;//初始化为“Home-首数据”。

	ULONG Len = Sum - 1;
	if (Sum   == 0)return NULL;
	else
	if (Index == 0)return Home;
	else
	if (Index == Len)return Last;
	else
	if (Index > Len)//“Index-下标”超出“Sum-总数”范围。
		return false;
	else//正常删除链表
	{
		for (ULONG i = 0; i < Index; i++)//找到“Index-下标”位置的“Type-类型”数据。
			temp = temp->Next;
	}
	return temp;
}

template<class Type>
inline Type CLinkedList<Type>::GetData(ULONG Index)
{
	CNod<Type> *Nod = GetNode(Index);
	if (!Nod)
		throw 1;
	return Nod->Data;
}

template<class Type>
inline Type CLinkedList<Type>::GetData(Limit Fist_Or_Last /*= Last*/)
{
	Type data;
	switch (Fist_Or_Last)
	{
	case Limit::FIRST:data = GetData(0)    ; break;
	case Limit::LAST :data = GetData(Sum - 1); break;
	}
	return data;
}

template<class Type>
inline ULONG CLinkedList<Type>::IndexOf(const Type &Data)
{

	return 1;
}

template<class Type>
inline ULONG CLinkedList<Type>::FindLocalData(const UINT8 &Data, ULONG offset_in_byte /*= 0*/)
{

	return 1;
}

template<class Type>
inline bool CLinkedList<Type>::Replace(ULONG Index, const Type &Data)
{

	return true;
}

template<class Type>
inline ULONG CLinkedList<Type>::Length(){
	return Sum;
}

template<class Type>
inline bool CLinkedList<Type>::Swap(ULONG Index1, ULONG Index2)
{

	return true;
}

template<class Type>
inline bool CLinkedList<Type>::SaveToFile(char*_file_name)
{

	return true;
}

template<class Type>
inline bool CLinkedList<Type>::ReadFromFile(char*_file_name)
{

	return true;
}
