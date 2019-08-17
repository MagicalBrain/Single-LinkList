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

int test_func11()
{
	LNodes* L,*re;
	int tou = 1;

	cout << "������ͷ���ģ�" << endl;

	L = LinkedListInit(tou);
	re = LinkedListInit(tou);

	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	re = func11(L);

	if (re)
	{
		cout << "�ֽ�ɹ���" << endl;
		cout << "���Ա�1��" << endl;
		LinkedOutput(L, tou);

		cout << "���Ա�2��" << endl;
		LinkedOutput(re, tou);
	}
	else
	{
		cout << "�ֽ�ʧ�ܣ�" << endl;
	}
	
	return 0;
}

int test_func12()
{
	LNodes* L;
	int tou = 1;

	cout << "������ͷ���ģ�" << endl;

	L = LinkedListInit(tou);

	LinkedInput(L, tou,1);

	if (L->data == -1)
	{
		cout << "���Ǵ�ͷ���ĵ�����" << endl;
	}

	if (func12(L))
	{
		cout << "ɾ���ɹ���" << endl;
		LinkedOutput(L, tou);
	}
	else
	{
		cout << "ɾ��ʧ�ܣ�" << endl;
	}

	return 0;
}

int test_func13()
{
	LNodes* L1, * L2;
	int tou = 1;
	int a1[] = { 4 ,15 ,15 ,21 ,33 ,34 ,34 ,37 ,44 ,48 };
	int a2[] = { 1 ,4 ,4 ,8 ,10 ,11 ,13 ,15 ,17 ,19 ,22 ,23 ,36 ,39 ,41 ,45 ,45 ,45 ,46 ,48 ,49 ,49 ,51 ,54 ,54 ,56 ,57 ,61 ,62 ,66 ,68 ,69 ,73 ,78 ,81 ,81 ,83 ,84 ,85 ,86 ,89 ,89 ,89 ,92 ,92 ,92 ,93 ,95 ,97 ,97 ,98 };

	cout << "������ͷ���ģ�" << endl;

	L1 = LinkedListInit(tou);
	L2 = LinkedListInit(tou);

	cout << endl << "�����1" << endl;
	LinkedInput(L1, tou, 1);
	//LinkedInput(L1, a1, 10, tou);
	cout << "�����2" << endl;
	LinkedInput(L2, tou, 1);
	//LinkedInput(L2, a2, 51, tou);

	cout << endl << "�����1" << endl;
	LinkedOutput(L1, tou);
	cout << "�����2" << endl;
	LinkedOutput(L2, tou);

	if (func13(L1,L2))
	{
		cout << "�鲢�ɹ���" << endl;
		LinkedOutput(L1, tou);
	}
	else
		cout << "�鲢ʧ�ܣ�" << endl;

	return 0;
}

int test_func14()
{
	LNodes* L1, *L2;
	LinkedList re;
	int tou = 1;

	cout << "������ͷ���ģ�" << endl;

	L1 = LinkedListInit(tou);
	L2 = LinkedListInit(tou);

	cout << endl << "�����1" << endl;
	LinkedInput(L1, tou, 1);
	cout << "�����2" << endl;
	LinkedInput(L2, tou, 1);

	cout << endl << "�����1" << endl;
	LinkedOutput(L1, tou);
	cout << "�����2" << endl;
	LinkedOutput(L2, tou);

	re = func14(L1, L2);

	if (re != NULL)
	{
		cout << "���ɳɹ���" << endl;
		LinkedOutput(re, tou);

		cout << endl << "�����1" << endl;
		LinkedOutput(L1, tou);
		cout << "�����2" << endl;
		LinkedOutput(L2, tou);
	}
	else
		cout << "����ʧ�ܣ�" << endl;

	return 0;
}

int test_func15()
{
	LNodes* L1, * L2;
	LinkedList re;
	int tou = 1;

	cout << "������ͷ���ģ�" << endl;

	L1 = LinkedListInit(tou);
	L2 = LinkedListInit(tou);

	cout << endl << "�����1" << endl;
	LinkedInput(L1, tou, 1);
	
	cout << "�����2" << endl;
	LinkedInput(L2, tou, 1);
	

	cout << endl << "�����1" << endl;
	LinkedOutput(L1, tou);
	cout << "�����2" << endl;
	LinkedOutput(L2, tou);

	if (func15(L1, L2))
	{
		cout << "�鲢�ɹ���" << endl;
		LinkedOutput(L1, tou);
	}
	else
		cout << "�鲢ʧ�ܣ�" << endl;

	cout << endl << "�����1" << endl;
	LinkedOutput(L1, tou);
	cout << "�����2" << endl;
	LinkedOutput(L2, tou);

	return 0;
}

int test_func16()
{
	LNodes* L1, * L2;
	LinkedList re;
	int tou = 1;
	int a1[] = { 1 ,4 ,4 ,8 ,10 ,11 ,13 ,15 ,17 ,19  };
	int a2[] = { 4,4  ,10 };


	cout << "������ͷ���ģ�" << endl;

	L1 = LinkedListInit(tou);
	L2 = LinkedListInit(tou);

	cout << endl << "�����1" << endl;
	//LinkedInput(L1, tou, 1);
	LinkedInput(L1, a1, 10, tou);
	cout << "�����2" << endl;
	//LinkedInput(L2, tou, 1);
	LinkedInput(L2, a2, 3, tou);

	cout << endl << "�����1" << endl;
	LinkedOutput(L1, tou);
	cout << "�����2" << endl;
	LinkedOutput(L2, tou);

	if (func16(L1, L2))
	{
		cout << "�������У�" << endl;
		//LinkedOutput(L1, tou);
	}
	else
		cout << "���������У�" << endl;
	return 0;
}

int test_CirclrLinkedList()
{
	LinkedList L;
	LNodes*p;

	L = CircleLinkedListInit(1);

	CircleLinkedInput(L, 1);

	p = L->next;
	while (p != L)
	{
		p = p->next;
	}

	CircleLinkedOutput(p, 1);

	return 0;
}

int test_func18()
{
	LinkedList L1,L2;

	L1 = CircleLinkedListInit(1);
	L2 = CircleLinkedListInit(1);

	cout << "����L1:" << endl;
	CircleLinkedInput(L1, 1);
	cout << "����L2:" << endl;
	CircleLinkedInput(L2, 1);

	cout << "���L1:" << endl;
	CircleLinkedOutput(L1, 1);
	cout << "���L2:" << endl;
	CircleLinkedOutput(L2, 1);

	if (func18(L1, L2))
	{
		cout << "���ӳɹ���" << endl;
		CircleLinkedOutput(L1, 1);
	}
	else
		cout << "����ʧ�ܣ�" << endl;
	return 0;
}

int test_func19()
{
	LinkedList L;

	L = CircleLinkedListInit(1);
	
	CircleLinkedInput(L, 1);

	CircleLinkedOutput(L, 1);

	if (func19(L))
	{
		cout << "����ɹ���" << endl;
		CircleLinkedOutput(L, 1);
	}
	else
		cout << "����ʧ�ܣ�" << endl;
	return 0;
}