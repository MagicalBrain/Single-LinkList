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

	cout << "有无头结点[Y/N]：" << endl;
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

	cout << "有无头结点[Y/N]：" << endl;
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

	cout << "有无头结点[Y/N]：" << endl;
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

	cout << "输入要寻找的元素：" << endl;
	cin >> e;
	
	int re = LocateElem(L, tou, e);
	cout <<"位置为："<< re << endl;

	return -1;
}

int test_GetElem()
{
	LNodes* L;
	int tou, loca,re;
	char in;

	cout << "有无头结点[Y/N]：" << endl;
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

	cout << "输入位置序号" << endl;
	cin >> loca;

	re = GetElem(L, tou, loca);
	cout << "位置为：" << re << endl;
	return 0;
}

int test_LinkListInsert()
{
	LNodes* L;
	int tou, loca, re,e;
	char in;

	cout << "有无头结点[Y/N]：" << endl;
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

	cout << "输入要插入的位置：" << endl;
	cin >> loca;
	cout << "输入键值：" << endl;
	cin >> e;

	re = LinkListInsert(L, tou, e, loca);

	LinkedOutput(L, tou);

	if (re)
	{
		cout << "插入成功！" << endl;
	}
	else
	{
		cout << "插入失败！" << endl;
	}

	return 0;
}

int test_LinkListDelete()
{
	LNodes* L;
	int tou, loca, *re=NULL;
	char in;

	cout << "有无头结点[Y/N]：" << endl;
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

	cout << "输入要删除的值：" << endl;
	cin >> loca;
	
	L=LinkListDelete(L, tou, loca);

	LinkedOutput(L, tou);

	if (L!=NULL)
	{
		cout << "删除掉的元素键值为：" << loca << endl;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "删除失败！" << endl;
	}

	cout << "输入要删除的值：" << endl;
	cin >> loca;

	LinkListDelete(L, tou, loca);

	LinkedOutput(L, tou);

	if (L != NULL)
	{
		cout << "删除掉的元素键值为：" << loca << endl;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "删除失败！" << endl;
	}

	return 0;
}

int test_LinkListDestroy()
{
	LNodes* L;
	int tou;
	char in;

	cout << "有无头结点[Y/N]：" << endl;
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
			cout << "销毁成功！" << endl;
		}
		LinkedOutput(L, tou);
		return 1;
	}
	else if (tou==0)
	{
		if (L == NULL)
		{
			cout << "销毁成功！" << endl;
		}
		LinkedOutput(L, tou);
		return 1;
	}
	cout << "销毁失败！" << endl;
	return 0;
}

int test_func01()
{
	LNodes* L;
	int tou=0, x;
	//char in;

	cout << "这是无头结点的！" << endl;
	
	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	cout << "输入要删除的元素值：" << endl;
	cin >> x;

	func01(L, x);

	LinkedOutput(L, tou);

	return 0;
}

int test_func02()
{
	LNodes* L;
	int tou = 1,  x;

	cout << "这是有头结点的！" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	cout << "输入要删除的元素值：" << endl;
	cin >> x;

	if (func02(L, x)==1)
	{
		cout << "删除成功！" << endl;
	}
	else
		cout << "删除失败！" << endl;

	LinkedOutput(L, tou);
	return 0;
}

int test_func03()
{
	LNodes* L;
	int tou = 1;

	cout << "这是有头结点的！" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	if (func03(L) == 1)
	{
		cout << "输出成功！" << endl;
	}
	else
		cout << "输出失败！" << endl;


	return 0;
}

int test_func04()
{
	LNodes* L;
	int tou = 1;

	cout << "这是有头结点的！" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	if (func04(L) == 1)
	{
		LinkedOutput(L, tou);
		cout << "删除成功！" << endl;
	}
	else
		cout << "删除失败！" << endl;

	

	return 0;
}

int test_func05()
{
	LNodes* L;
	int tou = 1;

	cout << "这是有头结点的！" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	if (func05(L) == 1)
	{
		LinkedOutput(L, tou);
		cout << "逆置成功！" << endl;
	}
	else
		cout << "逆置失败！" << endl;
	return 0;
}

int test_func06()
{
	LNodes* L;
	int tou = 1;

	cout << "这是有头结点的！" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	if (func06(L) == 1)
	{
		LinkedOutput(L, tou);
		cout << "排序成功！" << endl;
	}
	else
		cout << "排序失败！" << endl;
	return 0;
}

int test_func07()
{
	LNodes* L;
	int tou = 1,mink,maxk;

	cout << "这是有头结点的！" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	cout << "输入删除结点的键值范围：" << endl;
	cin >> mink >> maxk;

	if (func07(L,mink,maxk) == 1)
	{
		LinkedOutput(L, tou);
		cout << "删除成功！" << endl;
	}
	else
		cout << "删除失败！" << endl;

	return 0;
}

int test_func08()
{
	LNodes* L1, * L2, * p1,* p2;
	int tou1, tou2, tou = 1, num = 0;

	cout << "是否有头结点是未知的，这里调成了随机生成。" << endl;

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
		cout << "L1这次是带头结点的！" << endl;
		if (tou2==1)
		{
			cout << "L2这次是带头结点的！" << endl;
		}
		else if (tou2==0)
		{
			cout << "L2这次是不带头结点的！" << endl;
		}
	}
	else if (tou1==0)
	{
		cout << "L1这次是不带头结点的！" << endl;
		if (tou2 == 1)
		{
			cout << "L2这次是带头结点的！" << endl;
		}
		else if (tou2 == 0)
		{
			cout << "L2这次是不带头结点的！" << endl;
		}
	}

	L1 = LinkedListInit(tou1);
	L2 = LinkedListInit(tou2);

	cout << "输入L1：" << endl;
	LinkedInput(L1, tou1);
	cout << "输入L2：" << endl;
	LinkedInput(L2, tou2);

	cout << "L1：" << endl;
	LinkedOutput(L1, tou1);
	cout << "L2：" << endl;
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

	cout << "L1：" << endl;
	LinkedOutput(L1, tou1);
	cout << "L2：" << endl;
	LinkedOutput(L2, tou2);

	if (func08(L1, L2) == 1)
	{
		//LinkedOutput(L, tou);
		cout << "查找公共结点成功！" << endl;
	}
	else
		cout << "查找公共结点失败！" << endl;

	return 0;
}

int test_func09()
{
	LNodes* L;
	int tou = 1;

	cout << "这是有头结点的！" << endl;

	L = LinkedListInit(tou);
	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	func09(L);

	LinkedOutput(L, tou);

	/*
	if (func09(L) == 1)
	{
		LinkedOutput(L, tou);
		cout << "删除成功！" << endl;
	}
	else
		cout << "删除失败！" << endl;
	*/
	
	return 0;
}

int test_func10()
{
	LNodes* L, * L1, * L2;
	int tou = 1;

	cout << "这是有头结点的！" << endl;

	L = LinkedListInit(tou);
	L1 = LinkedListInit(tou);
	L2 = LinkedListInit(tou);

	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	if (func10(L,L1, L2) == 1)
	{
		//LinkedOutput(L, tou);
		cout << "分解成功！" << endl;
		LinkedOutput(L1, tou);
		LinkedOutput(L2, tou);
	}
	else
		cout << "分解失败！" << endl;

	return 0;
}

int test_func11()
{
	LNodes* L,*re;
	int tou = 1;

	cout << "这是有头结点的！" << endl;

	L = LinkedListInit(tou);
	re = LinkedListInit(tou);

	LinkedInput(L, tou);

	LinkedOutput(L, tou);

	re = func11(L);

	if (re)
	{
		cout << "分解成功！" << endl;
		cout << "线性表1：" << endl;
		LinkedOutput(L, tou);

		cout << "线性表2：" << endl;
		LinkedOutput(re, tou);
	}
	else
	{
		cout << "分解失败！" << endl;
	}
	
	return 0;
}

int test_func12()
{
	LNodes* L;
	int tou = 1;

	cout << "这是有头结点的！" << endl;

	L = LinkedListInit(tou);

	LinkedInput(L, tou,1);

	if (L->data == -1)
	{
		cout << "这是带头结点的单链表" << endl;
	}

	if (func12(L))
	{
		cout << "删除成功！" << endl;
		LinkedOutput(L, tou);
	}
	else
	{
		cout << "删除失败！" << endl;
	}

	return 0;
}

int test_func13()
{
	LNodes* L1, * L2;
	int tou = 1;
	int a1[] = { 4 ,15 ,15 ,21 ,33 ,34 ,34 ,37 ,44 ,48 };
	int a2[] = { 1 ,4 ,4 ,8 ,10 ,11 ,13 ,15 ,17 ,19 ,22 ,23 ,36 ,39 ,41 ,45 ,45 ,45 ,46 ,48 ,49 ,49 ,51 ,54 ,54 ,56 ,57 ,61 ,62 ,66 ,68 ,69 ,73 ,78 ,81 ,81 ,83 ,84 ,85 ,86 ,89 ,89 ,89 ,92 ,92 ,92 ,93 ,95 ,97 ,97 ,98 };

	cout << "这是有头结点的！" << endl;

	L1 = LinkedListInit(tou);
	L2 = LinkedListInit(tou);

	cout << endl << "输入表1" << endl;
	LinkedInput(L1, tou, 1);
	//LinkedInput(L1, a1, 10, tou);
	cout << "输入表2" << endl;
	LinkedInput(L2, tou, 1);
	//LinkedInput(L2, a2, 51, tou);

	cout << endl << "输出表1" << endl;
	LinkedOutput(L1, tou);
	cout << "输出表2" << endl;
	LinkedOutput(L2, tou);

	if (func13(L1,L2))
	{
		cout << "归并成功！" << endl;
		LinkedOutput(L1, tou);
	}
	else
		cout << "归并失败！" << endl;

	return 0;
}

int test_func14()
{
	LNodes* L1, *L2;
	LinkedList re;
	int tou = 1;

	cout << "这是有头结点的！" << endl;

	L1 = LinkedListInit(tou);
	L2 = LinkedListInit(tou);

	cout << endl << "输入表1" << endl;
	LinkedInput(L1, tou, 1);
	cout << "输入表2" << endl;
	LinkedInput(L2, tou, 1);

	cout << endl << "输出表1" << endl;
	LinkedOutput(L1, tou);
	cout << "输出表2" << endl;
	LinkedOutput(L2, tou);

	re = func14(L1, L2);

	if (re != NULL)
	{
		cout << "生成成功！" << endl;
		LinkedOutput(re, tou);

		cout << endl << "输出表1" << endl;
		LinkedOutput(L1, tou);
		cout << "输出表2" << endl;
		LinkedOutput(L2, tou);
	}
	else
		cout << "生成失败！" << endl;

	return 0;
}

int test_func15()
{
	LNodes* L1, * L2;
	LinkedList re;
	int tou = 1;

	cout << "这是有头结点的！" << endl;

	L1 = LinkedListInit(tou);
	L2 = LinkedListInit(tou);

	cout << endl << "输入表1" << endl;
	LinkedInput(L1, tou, 1);
	
	cout << "输入表2" << endl;
	LinkedInput(L2, tou, 1);
	

	cout << endl << "输出表1" << endl;
	LinkedOutput(L1, tou);
	cout << "输出表2" << endl;
	LinkedOutput(L2, tou);

	if (func15(L1, L2))
	{
		cout << "归并成功！" << endl;
		LinkedOutput(L1, tou);
	}
	else
		cout << "归并失败！" << endl;

	cout << endl << "输出表1" << endl;
	LinkedOutput(L1, tou);
	cout << "输出表2" << endl;
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


	cout << "这是有头结点的！" << endl;

	L1 = LinkedListInit(tou);
	L2 = LinkedListInit(tou);

	cout << endl << "输入表1" << endl;
	//LinkedInput(L1, tou, 1);
	LinkedInput(L1, a1, 10, tou);
	cout << "输入表2" << endl;
	//LinkedInput(L2, tou, 1);
	LinkedInput(L2, a2, 3, tou);

	cout << endl << "输出表1" << endl;
	LinkedOutput(L1, tou);
	cout << "输出表2" << endl;
	LinkedOutput(L2, tou);

	if (func16(L1, L2))
	{
		cout << "是子序列！" << endl;
		//LinkedOutput(L1, tou);
	}
	else
		cout << "不是子序列！" << endl;
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

	cout << "输入L1:" << endl;
	CircleLinkedInput(L1, 1);
	cout << "输入L2:" << endl;
	CircleLinkedInput(L2, 1);

	cout << "输出L1:" << endl;
	CircleLinkedOutput(L1, 1);
	cout << "输出L2:" << endl;
	CircleLinkedOutput(L2, 1);

	if (func18(L1, L2))
	{
		cout << "链接成功！" << endl;
		CircleLinkedOutput(L1, 1);
	}
	else
		cout << "链接失败！" << endl;
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
		cout << "处理成功！" << endl;
		CircleLinkedOutput(L, 1);
	}
	else
		cout << "处理失败！" << endl;
	return 0;
}