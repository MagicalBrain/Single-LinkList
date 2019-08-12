#pragma once

#include <iostream>
#include <Windows.h>
#include "LinkList.h"
#include "TestFunction.h"

using namespace std;

void func01(LinkedList &L,int x)
/*
删除不带头节点的单链表L中所有值为x的结点
递归实现
*/
{
	LNodes* p;
	if (L == NULL)
	{
		return;
	}
	if (L->data == x)
	{
		p = L;
		L = L->next;
		free(p);
		func01(L, x);
	}
	else
	{
		func01(L->next, x);
		//return L;
	}
	//return;
}

int func02(LNodes* L,int e)
/*
带头结点的单链表
删除所有值为x的结点
*/
{
	LNodes* p, * q,* t;
	if (L->next != NULL)
	{
		q = L;
		p = L->next;
		while (p)
		{
			if (p->data == e)
			{
				t = p;
				q->next = p->next;
				p = p->next;
				free(t);
				//LinkListDelete(L, 1, e);
			}
			else
			{
				p = p->next;
				q = q->next;
			}
			
		}
		return 1;
	}
	return 0;
}

int func03(LNodes*L)
/*
带头结点的单链表
*/
{
	LNodes* p;
	int l = Length(L, 1), n = l;
	int* re = (int*)malloc(l * sizeof(int));

	if (L->next !=NULL)
	{
		p = L->next;
		while (p)
		{
			re[n - 1] = p->data;
			n--;
			p = p->next;
		}

		for (int i = 0; i < l; i++)
		{
			cout << re[i] << " ";
		}
		cout << endl;

		return 1;
	}
	return 0;
}

int func04(LNodes* L)
/*带头结点的单链表，最小值唯一，高效算法删除该最小值*/
{
	LNodes* p, * q;
	int t;
	if (L->next != NULL)
	{
		q = L;
		p = L->next;
		q->data = p->data;
		while (p->next)
		{
			if (q->data < p->data)
			{
				t = q->data;
				q->data = p->data;
				p->data = t;
			}
			p = p->next;
			q = q->next;
		}

		//LinkedOutput(L, 1);

		if (q->data < p->data)
		{
			q->next = p->next;
			t = q->data;
			q->data = p->data;
			p->data = t;
			free(p);
		}
		

		return 1;
	}
	return 0;
}

int func05(LNodes* L)
{
	LNodes* p, * q;
	int l = Length(L, 1);

	if (L->next != NULL)
	{
		q = L;
		p = L->next;
		while (p->next)
		{
			q = q->next;
			p = p->next;
		}
		q->next = NULL;
		q = L->next;
		p->next = q;
		L->next = q;
		
		return 1;
	}
	return 0;
}