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
	int tou, loca, *re=NULL, e;
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
	int tou,re;
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
	int tou=0, re,x;
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
	int tou = 1, re, x;

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
	int tou = 1, re, x;

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
	int tou = 1, re, x;

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
	int tou = 1, re, x;

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

int test01()
{
	return 0;
}