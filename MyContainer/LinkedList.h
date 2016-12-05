#pragma once
#include <windows.h>
#ifndef LINKED_LIST
#define LINKED_LIST

//˫��ڵ�
template<class DataType>
struct CNod
{
	CNod(const DataType &Data){
		this->Data = Data;
	}
	DataType Data; //ģ������
	CNod<DataType>*Prior = NULL;//ǰ�ڵ�
	CNod<DataType>*Next  = NULL;//��ڵ�
};

enum Limit
{
	FIRST,//ͷ��
	LAST, //β��
};

/*
 * ��    ����CLinkedList
 * ��    �ߣ�����
 * ʱ    �䣺
 *          2016��12��3�� ~8h ������
 *          2016��12��4�� ~4h �޸�CLinkedList�࣬����Append��AddFirst��Insert�ȡ�
 *          2016��12��5�� ~6h �������
 *
 * ��    ע��
 */
template<class Type>
class CLinkedList
{
private:
	CNod<Type> *Home;   //ʼ�ڵ�
	CNod<Type> *Last;   //β�ڵ�
	ULONG       Sum;    //����
	
public:
	 CLinkedList();
	~CLinkedList();

	//��ӵ�β
	virtual bool Append(const Type &Data);
	//��ӵ���
	virtual bool AddFirst(const Type &Data);
	//�����м�
	virtual bool Insert(ULONG Index, const Type &Data);
	//�����м�
	virtual bool Insert(const Type &Data, Limit Fist_Or_Last = Last);
	//���ȫ��
	virtual void Clear();
	//ɾ���ڵ�
	virtual bool Delete(ULONG Index);
	//ɾ��ͷ���ڵ�
	virtual bool DeleteFirst();
	//ɾ��β���ڵ�
	virtual bool DeleteLast();
	//ɾ���ڵ�
	virtual bool Delete(Limit Fist_Or_Last = Last);
	//ȡ�ڵ�
	virtual CNod<Type>* GetNode(ULONG Index);
	//ȡ����
	virtual Type GetData(ULONG Index);
	//ȡ����
	virtual Type GetData(Limit Fist_Or_Last = Last);
	//ȡ�±�
	virtual ULONG IndexOf(const Type &Data, ULONG StartIndex = 0);
	//�ı�ָ������
	virtual bool Replace(ULONG Index, const Type &Data);
	//ȡ����
	virtual ULONG Length();
	//��������
	virtual bool Swap(ULONG Index1, ULONG Index2);
	//�������ݵ��ļ�
	virtual bool SaveToFile(TCHAR*_file_name);
	//�����ݴ��ļ�
	virtual bool ReadFromFile(TCHAR*_file_name);
	//��������� << ��ӵ�β
	CLinkedList<Type>& operator<<(const Type &data){
		Append(data);
		return *this;
	}
	//��������� >> ��ӵ���
	CLinkedList<Type>& operator>>(const Type &data){
		AddFirst(data);
		return *this;
	}
	//��������� []
	const Type& operator[](ULONG Index){
		CNod<Type>*nod = GetNode(Index);
		if (!nod)
			throw 1;
		return nod->Data;
	}
};
#define UL_MAX     0x80000000UL  //�Լ����Ű죬����ֻ�����ѡ���������̫���п��ܵ��±�����

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
	CNod<Type> *temp = new CNod<Type>(Data);//��ʼ��Ϊ��Data-���ݡ���
	//û�д���temp��ΪNULL���������Ϊ��̫���ܡ���֪�����32λ��ַ�������������� > 2G��

	if (Last){//��Last-β�ڵ㡱�����ݣ�׷�ӵ�β����

//		ע�ͣ�����ٶȡ�
//  	if(Sum == UL_MAX)//���������������ټ��롣
//  		return false;
		temp->Prior = Last;//�½ڵ㣬���á�ǰ���ڵ㡣 *���������ǡ�˫��������ԭ��֮һ��
		Last->Next  = temp;//�ɽڵ㣬���á��󡿽ڵ㡣 *...
		Last        = temp;//�����µģ�β�ڵ㡣
		Sum++;//���ӳ���
	}
	else{    //��Last-β�ڵ㡱ΪNULL����ʼ�����ݡ�
		Home = temp;
		Last = temp;
		Sum  = 1;
	}
	return true;
}

template<class Type>
inline bool CLinkedList<Type>::AddFirst(const Type &Data)
{
	CNod<Type> *temp = new CNod<Type>(Data);//��ʼ��Ϊ��Data-���ݡ���
	//û�д���temp��ΪNULL���������Ϊ��̫���ܡ�

	if (Home){//��Home-β�ڵ㡱�����ݣ�׷�ӵ�β����

//		ע�ͣ�����ٶȡ�
// 		if(Sum == UL_MAX)//���������������ټ��롣
//  		return false;
		temp->Next  = Home;//�½ڵ㣬���á��󡿽ڵ㡣 *���������ǡ�˫��������ԭ��֮һ��
		Home->Prior = temp;//�ɽڵ㣬���á�ǰ���ڵ㡣 *...
		Home        = temp;//�����µģ�ʼ�ڵ㡣
		Sum++;
	}
	else{    //��Home-β�ڵ㡱ΪNULL����ʼ�����ݡ�
		Home = temp;
		Last = temp;
		Sum = 1;
	}
	return true;
}

template<class Type>
inline bool CLinkedList<Type>::Insert(ULONG Index, const Type &Data)
{
	CNod<Type> *temp = Home;//��ʼ��Ϊ��Home-�����ݡ���

//	ע�ͣ�����ٶȡ�
// 	if(Sum == UL_MAX)//���������������ټ��롣
//  		return false;
//  else
	if(Sum == 0 && Index)//�����ڡ�Sum-���ȡ�Ϊ0ʱ��ֻ�����ڡ�Index-�±ꡱΪ0ʱ���롣
		return false;
	else
	if (Index == 0  )AddFirst(Data);//���ֳɣ���Ӧ�ġ�AddFirst-��ӵ���ͷ��������
	else
	if (Index == Sum)Append(Data);  //���ֳɣ���Ӧ�ġ�Append-׷�ӵ�β��������
	else
	if (Index >  Sum)//��Index-�±ꡱ������Sum-��������Χ��
		return false;
	else//������������
	{
		if(Index < (Sum / 2)){
			for(ULONG i = 0; i < Index; i++)//�ҵ���Index-�±ꡱλ�õġ�Type-���͡����ݡ�
				temp = temp->Next;
		}
		else{
			temp = Last;//��ʼ��Ϊ��Last-�����ݡ���
			for (ULONG i = Sum - 1; i != Index; i--)//�ҵ���Index-�±ꡱλ�õġ�Type-���͡����ݡ�
				temp = temp->Prior;
		}

		CNod<Type> *Nod = new CNod<Type>(Data);//��ʼ��Ϊ��Data-���ݡ���
		//û�д���temp��ΪNULL���������Ϊ��̫���ܡ�

		temp->Prior->Next = Nod;        //Ϊ��temp����ǰһ�ڵ㣬�����¸��ڵ�Ϊ��Nod����
		 Nod->Prior       = temp->Prior;//Ϊ��Nod������ǰһ�ڵ㣬Ϊ��temp����ǰһ�ڵ㡣
		 Nod->Next        = temp;       //Ϊ��Nod�������¸��ڵ㣬Ϊ��temp����
		temp->Prior       = Nod;        //Ϊ��temp�������¸��ڵ㣬Ϊ��Nod����
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
			   *temp  = Home;//��ʼ��Ϊ��Home-�����ݡ���

	for (ULONG i = 0; i < Sum; i++)//�ҵ���Index-�±ꡱλ�õġ�Type-���͡����ݡ�
	{
		store = temp;      //��������
		temp  = temp->Next;//�Ƶ���һ�ڵ�
		delete  store;     //�ͷŻ���ڵ�Ŀռ�
	}
	Home = Last = NULL;//��ԭΪ��NULL������
	Sum  = 0;          //������0
}

template<class Type>
inline bool CLinkedList<Type>::Delete(ULONG Index)
{
	CNod<Type> *temp = Home;//��ʼ��Ϊ��Home-�����ݡ���

	ULONG Len = Sum - 1;
	if (Sum   == 0  )return false;
	else		    
	if (Index == 0  )DeleteFirst();
	else
	if (Index == Len)DeleteLast();
	else
	if (Index > Len)//��Index-�±ꡱ������Sum-��������Χ��
		return false;
	else//����ɾ������
	{
		for (ULONG i = 0; i < Index; i++)//�ҵ���Index-�±ꡱλ�õġ�Type-���͡����ݡ�
			temp = temp->Next;

		//��temp��ǰ��ڵ㣬����ֱ����ϵ��
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
	CNod<Type> *temp = Last;//��ʼ��Ϊ��Last-β���ݡ���

	if (Last){
		Last = Last->Prior;//��Last-β�ڵ㡱���õ�ǰһ�ڵ㡣
		delete temp;       //ɾ���ڵ�
		if (Last == NULL){ //���ΪNULL��������������ˡ�
			Home  = NULL;
			Sum   = 0;
		}
		else{
			Last->Next = NULL;//��ʱ��Last-β�ڵ㡱����һ�ڵ㣬�Ѿ�û���ˡ�
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
	CNod<Type> *temp = Home;//��ʼ��Ϊ��Home-β���ݡ���

	if (Home){
		Home = Home->Next;//��Home-β�ڵ㡱���õ���һ�ڵ㡣
		delete temp;       //ɾ���ڵ�
		if (Home == NULL){ //���ΪNULL��������������ˡ�
			Last  = NULL;
			Sum   = 0;
		}
		else{
			Home->Prior = NULL;//��ʱ��Last-β�ڵ㡱����һ�ڵ㣬�Ѿ�û���ˡ�
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

	CNod<Type> *temp = Home;//��ʼ��Ϊ��Home-�����ݡ���

	ULONG Len = Sum - 1;
	if (Sum   == 0)return NULL;
	else
	if (Index == 0)return Home;
	else
	if (Index == Len)return Last;
	else
	if (Index > Len)//��Index-�±ꡱ������Sum-��������Χ��
		return NULL;
	else//����ɾ������
	{
		for (ULONG i = 0; i < Index; i++)//�ҵ���Index-�±ꡱλ�õġ�Type-���͡����ݡ�
			temp = temp->Next;
	}
	return temp;
}

template<class Type>
inline Type CLinkedList<Type>::GetData(ULONG Index)
{
	CNod<Type> *Nod = GetNode(Index);
	if (!Nod)//����ڵ�Ϊ�գ��׳��쳣��
		throw 1;
	return Nod->Data;
}

template<class Type>
inline Type CLinkedList<Type>::GetData(Limit Fist_Or_Last /*= Last*/)
{
	Type data;
	switch (Fist_Or_Last)
	{
	case Limit::FIRST:data = GetData(0)      ; break;
	case Limit::LAST :data = GetData(Sum - 1); break;
	}
	return data;
}

template<class Type>
inline ULONG CLinkedList<Type>::IndexOf(const Type &Data, ULONG StartIndex)
{
	CNod<Type> *temp = Home;//��ʼ��Ϊ��Home-�����ݡ���

	for (ULONG i = 0; i < StartIndex; i++)//�ƶ�����StartIndex-��ʼ�±ꡱ����
		temp = temp->Next;
	for (ULONG i = StartIndex; i < Sum; i++)//�ҵ���Index-�±ꡱλ�õġ�Type-���͡����ݡ�
	{
		if (temp->Data == Data)//�������һ�£������±ꡣ
			return i; 
		temp = temp->Next;
	}
	return Sum;
}

template<class Type>
inline bool CLinkedList<Type>::Replace(ULONG Index, const Type &Data)
{
	CNod<Type> *nod = GetNode(Index);
	if (!nod)//û�ҵ��ڵ�
		return false;
	nod->Data = Data;//�滻����
	return true;
}

template<class Type>
inline ULONG CLinkedList<Type>::Length(){
	return Sum;
}

template<class Type>
inline bool CLinkedList<Type>::Swap(ULONG Index1, ULONG Index2)
{
	CNod<Type>*nod1 = GetNode(Index1);
	CNod<Type>*nod2 = GetNode(Index2);
	if (nod1 && nod2){//�����ڵ㣬Ҫ�ɹ���á�
		Type data = nod1->Data;
		nod1->Data = nod2->Data;
		nod2->Data = data;
		return true;
	}
	return false;
}

template<class Type>
inline bool CLinkedList<Type>::SaveToFile(TCHAR*FileName)
{
	FILE *file = NULL;
	int   val = _tfopen_s(&file, FileName, L"wb");//���ļ�

	if (!val && Sum > 0){           //�򿪳ɹ�
		int size = sizeof Sum;
		fwrite(&Sum, size, 1, file);//д����Sum����

		size = sizeof Type;
		CNod<Type> *temp = Home;       //��ʼ��Ϊ��Home-�����ݡ���
		for (ULONG i = 0; i < Sum; i++){//ѭ��Sum��
			fwrite(&temp->Data, size, 1, file);//д������
			temp = temp->Next;
		}
		fclose(file);//�ر��ļ�
		return true;
	}
	return false;
}

template<class Type>
inline bool CLinkedList<Type>::ReadFromFile(TCHAR*FileName)
{
	FILE *file = NULL;
	int   val = _tfopen_s(&file, FileName, L"rb");//���ļ�
	if (!val){//�򿪳ɹ�
		int Len = 0;
		int size = sizeof Len;
		fread_s(&Len, size, size, 1, file);//��ȡSum����

		size = sizeof Type;
		Type data;
		for (ULONG i = 0; i < Len; i++){//ѭ��Len��
			fread_s(&data, size, size, 1, file);//��ȡ����
			Append(data);
		}
		fclose(file);//�ر��ļ�
		return true;
	}
	return false;
}

#endif // LINKED_LIST
