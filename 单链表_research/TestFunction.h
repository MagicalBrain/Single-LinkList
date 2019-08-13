#pragma once
#include <iostream>
#include <Windows.h>
#include "LinkList.h"
#include "func.h"

using namespace std;

int test_LinkListInput()
{
	LNodes* L;
	int tou;
	char in;

	cout << "����ͷ���[Y/N]��" << endl;
	cin >> in;

	switch (in)
	{
	case 'Y':
		tou = 1;
		break;
	case 'N':
		tou = 0;
		break;
	default:
		break;
	}

	L = LinkedListInit(tou);

	LinkedInput(L, tou);

	LinkedOutput(L, tou);
	return 0;
}

int test_Length()
{
	int tou,re;
	char in;
	LNodes* L;// = (LNodes*)malloc(sizeof(LNodes));

	cout << "����ͷ���[Y/N]��" << endl;
	cin >> in;

	switch (in)
	{
	case 'Y':
		tou = 1;
		break;
	case 'N':
		tou = 0;
		break;
	default:
		break;
	}

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	if (tou)
	{
		if (L->next != NULL)
		{
			re = Length(L, tou);
			cout << "re:" << re << endl;
			return re;
		}
	}
	else
	{
		if (L != NULL)
		{
			re = Length(L, tou);
			cout << "re:" << re << endl;
			return re;
		}
	}
	
	return 0;
}

int test_LocateElem()
{
	LNodes* L;
	int tou, e;
	char in;

	cout << "����ͷ���[Y/N]��" << endl;
	cin >> in;

	switch (in)
	{
	case 'Y':
		tou = 1;
		break;
	case 'N':
		tou = 0;
		break;
	default:
		break;
	}

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	cout << "����ҪѰ�ҵ�Ԫ�أ�" << endl;
	cin >> e;
	
	int re = LocateElem(L, tou, e);
	cout <<"λ��Ϊ��"<< re << endl;

	return -1;
}

int test_GetElem()
{
	LNodes* L;
	int tou, loca,re;
	char in;

	cout << "����ͷ���[Y/N]��" << endl;
	cin >> in;

	switch (in)
	{
	case 'Y':
		tou = 1;
		break;
	case 'N':
		tou = 0;
		break;
	default:
		break;
	}

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	cout << "����λ�����" << endl;
	cin >> loca;

	re = GetElem(L, tou, loca);
	cout << "λ��Ϊ��" << re << endl;
	return 0;
}

int test_LinkListInsert()
{
	LNodes* L;
	int tou, loca, re,e;
	char in;

	cout << "����ͷ���[Y/N]��" << endl;
	cin >> in;

	switch (in)
	{
	case 'Y':
		tou = 1;
		break;
	case 'N':
		tou = 0;
		break;
	default:
		break;
	}

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	cout << "����Ҫ�����λ�ã�" << endl;
	cin >> loca;
	cout << "�����ֵ��" << endl;
	cin >> e;

	re = LinkListInsert(L, tou, e, loca);

	LinkedOutput(L, tou);

	if (re)
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}

	return 0;
}

int test_LinkListDelete()
{
	LNodes* L;
	int tou, loca, *re=NULL;
	char in;

	cout << "����ͷ���[Y/N]��" << endl;
	cin >> in;

	switch (in)
	{
	case 'Y':
		tou = 1;
		break;
	case 'N':
		tou = 0;
		break;
	default:
		break;
	}

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	cout << "����Ҫɾ����ֵ��" << endl;
	cin >> loca;
	
	L=LinkListDelete(L, tou, loca);

	LinkedOutput(L, tou);

	if (L!=NULL)
	{
		cout << "ɾ������Ԫ�ؼ�ֵΪ��" << loca << endl;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "ɾ��ʧ�ܣ�" << endl;
	}

	cout << "����Ҫɾ����ֵ��" << endl;
	cin >> loca;

	LinkListDelete(L, tou, loca);

	LinkedOutput(L, tou);

	if (L != NULL)
	{
		cout << "ɾ������Ԫ�ؼ�ֵΪ��" << loca << endl;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "ɾ��ʧ�ܣ�" << endl;
	}

	return 0;
}

int test_LinkListDestroy()
{
	LNodes* L;
	int tou;
	char in;

	cout << "����ͷ���[Y/N]��" << endl;
	cin >> in;

	switch (in)
	{
	case 'Y':
		tou = 1;
		break;
	case 'N':
		tou = 0;
		break;
	default:
		break;
	}

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	L = LinkListDestroy(L, tou);

	if (tou==1)
	{
		if (L->next==NULL)
		{
			cout << "���ٳɹ���" << endl;
		}
		LinkedOutput(L, tou);
		return 1;
	}
	else if (tou==0)
	{
		if (L == NULL)
		{
			cout << "���ٳɹ���" << endl;
		}
		LinkedOutput(L, tou);
		return 1;
	}
	cout << "����ʧ�ܣ�" << endl;
	return 0;
}

int test_func01()
{
	LNodes* L;
	int tou=0, x;
	//char in;

	cout << "������ͷ���ģ�" << endl;
	
	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	cout << "����Ҫɾ����Ԫ��ֵ��" << endl;
	cin >> x;

	func01(L, x);

	LinkedOutput(L, tou);

	return 0;
}

int test_func02()
{
	LNodes* L;
	int tou = 1,  x;

	cout << "������ͷ���ģ�" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	cout << "����Ҫɾ����Ԫ��ֵ��" << endl;
	cin >> x;

	if (func02(L, x)==1)
	{
		cout << "ɾ���ɹ���" << endl;
	}
	else
		cout << "ɾ��ʧ�ܣ�" << endl;

	LinkedOutput(L, tou);
	return 0;
}

int test_func03()
{
	LNodes* L;
	int tou = 1;

	cout << "������ͷ���ģ�" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	if (func03(L) == 1)
	{
		cout << "����ɹ���" << endl;
	}
	else
		cout << "���ʧ�ܣ�" << endl;


	return 0;
}

int test_func04()
{
	LNodes* L;
	int tou = 1;

	cout << "������ͷ���ģ�" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	if (func04(L) == 1)
	{
		LinkedOutput(L, tou);
		cout << "ɾ���ɹ���" << endl;
	}
	else
		cout << "ɾ��ʧ�ܣ�" << endl;

	

	return 0;
}

int test_func05()
{
	LNodes* L;
	int tou = 1;

	cout << "������ͷ���ģ�" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	if (func05(L) == 1)
	{
		LinkedOutput(L, tou);
		cout << "���óɹ���" << endl;
	}
	else
		cout << "����ʧ�ܣ�" << endl;
	return 0;
}

int test_func06()
{
	LNodes* L;
	int tou = 1;

	cout << "������ͷ���ģ�" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	if (func06(L) == 1)
	{
		LinkedOutput(L, tou);
		cout << "����ɹ���" << endl;
	}
	else
		cout << "����ʧ�ܣ�" << endl;
	return 0;
}

int test_func07()
{
	LNodes* L;
	int tou = 1,mink,maxk;

	cout << "������ͷ���ģ�" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	cout << "����ɾ�����ļ�ֵ��Χ��" << endl;
	cin >> mink >> maxk;

	if (func07(L,mink,maxk) == 1)
	{
		LinkedOutput(L, tou);
		cout << "ɾ���ɹ���" << endl;
	}
	else
		cout << "ɾ��ʧ�ܣ�" << endl;

	return 0;
}

int test_func08()
{
	LNodes* L1, * L2, * p1,* p2;
	int tou1, tou2, tou = 1, num = 0;

	cout << "�Ƿ���ͷ�����δ֪�ģ����������������ɡ�" << endl;

	switch (tou)
	{
	case 1:
		tou1 = 1;
		tou2 = 1;
		break;
	case 2:
		tou1 = 0;
		tou2 = 0;
		break;
	case 3:
		tou1 = 0;
		tou2 = 1;
		break;
	case 4:
		tou1 = 1;
		tou2 = 0;
		break;
	default:
		break;
	}
	

	if (tou1==1)
	{
		cout << "L1����Ǵ�ͷ���ģ�" << endl;
		if (tou2==1)
		{
			cout << "L2����Ǵ�ͷ���ģ�" << endl;
		}
		else if (tou2==0)
		{
			cout << "L2����ǲ���ͷ���ģ�" << endl;
		}
	}
	else if (tou1==0)
	{
		cout << "L1����ǲ���ͷ���ģ�" << endl;
		if (tou2 == 1)
		{
			cout << "L2����Ǵ�ͷ���ģ�" << endl;
		}
		else if (tou2 == 0)
		{
			cout << "L2����ǲ���ͷ���ģ�" << endl;
		}
	}

	L1 = LinkedListInit(tou1);
	L2 = LinkedListInit(tou2);

	cout << "����L1��" << endl;
	LinkedInput(L1, tou1);
	cout << "����L2��" << endl;
	LinkedInput(L2, tou2);

	cout << "L1��" << endl;
	LinkedOutput(L1, tou1);
	cout << "L2��" << endl;
	LinkedOutput(L2, tou2);

	p1 = L1;
	p2 = L2;

	int r;
	r = Randnum(10);

	while (p2->next)
	{
		//if (num == Length(L2, tou2) - r)
		if (num == r)
			break;
		p2 = p2->next;
		num++;
	}
	num = 0;

	while (p1->next)
	{
		if (num == r)
			p1->next = p2;
		p1 = p1->next;
		num++;
	}

	cout << "L1��" << endl;
	LinkedOutput(L1, tou1);
	cout << "L2��" << endl;
	LinkedOutput(L2, tou2);

	if (func08(L1, L2) == 1)
	{
		//LinkedOutput(L, tou);
		cout << "���ҹ������ɹ���" << endl;
	}
	else
		cout << "���ҹ������ʧ�ܣ�" << endl;

	return 0;
}

int test_func09()
{
	LNodes* L;
	int tou = 1;

	cout << "������ͷ���ģ�" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	func09(L);

	LinkedOutput(L, tou);

	/*
	if (func09(L) == 1)
	{
		LinkedOutput(L, tou);
		cout << "ɾ���ɹ���" << endl;
	}
	else
		cout << "ɾ��ʧ�ܣ�" << endl;
	*/
	
	return 0;
}

int test_func10()
{
	LNodes* L, * L1, * L2;
	int tou = 1;

	cout << "������ͷ���ģ�" << endl;

	L = LinkedListInit(tou);
	L1 = LinkedListInit(tou);
	L2 = LinkedListInit(tou);

	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	if (func10(L,L1, L2) == 1)
	{
		//LinkedOutput(L, tou);
		cout << "�ֽ�ɹ���" << endl;
		LinkedOutput(L1, tou);
		LinkedOutput(L2, tou);
	}
	else
		cout << "�ֽ�ʧ�ܣ�" << endl;

	return 0;
}

int test01()
{
	return 0;
}