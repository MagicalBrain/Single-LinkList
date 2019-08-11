#pragma once
#include <iostream>
#include <Windows.h>
#include "LinkList.h"

using namespace std;

int test_LinkListInput()
{
	LNodes* L;// = (LNodes*)malloc(sizeof(LNodes));

	L = LinkedListInit(0);

	LinkedInput(L, 0);

	LinkedOutput(L, 0);
	return 0;
}

int test_Length()
{
	int tou,re;
	char in;
	LNodes* L = (LNodes*)malloc(sizeof(LNodes));

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

int test01()
{
	return 0;
}