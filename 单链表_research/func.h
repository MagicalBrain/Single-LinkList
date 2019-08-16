#pragma once

#include <iostream>
#include <Windows.h>
#include "LinkList.h"
#include "TestFunction.h"

using namespace std;

void func01(LinkedList &L,int x)
/*
王道 P38 T1
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
		p = L->next;
		q = p->next;
		L->next = NULL;

		while (p!=NULL)
		{
			q = p->next;

			p->next = L->next;
			L->next = p;

			p = q;
		}
		
		return 1;
	}
	return 0;
}

int func06(LNodes* L)
/*
对一个带有头结点的单链表排序，递增的
*/
{
	LNodes* p;
	int l = Length(L,1);
	int* n,t;

	if (L->next != NULL)
	{
		n = (int*)malloc(l * sizeof(int));
		p = L->next;
		for (int i = 0; i < l; i++)
		{
			n[i] = p->data;
			p = p->next;
		}

		//

		for (int i = 0; i < l; i++)
		{
			for (int j = 1; j < l-i; j++)
			{
				if (n[j] < n[j - 1])
				{
					t = n[j];
					n[j] = n[j - 1];
					n[j - 1] = t;
				}
			}
		}

		/*
		for (int i = 0; i < l; i++)
		{
			cout << n[i] << " ";
		}
		cout << endl;
		*/
		

		p = L->next;
		for (int i = 0; i < l; i++)
		{
			p->data = n[i];
			p = p->next;
		}

		return 1;
	}
	return 0;
}

int func07(LNodes*L,int mink,int maxk)
{
	LNodes* p, * q;
	int num = 0;

	p = L->next;
	q = L;
	
	while (p != NULL)
	{
		if (p->data <= mink || p->data >= maxk)
		{
			p = p->next;
			q = q->next;
		}
		else
		{
			LNodes* m = p;
			q->next = m->next;
			free(m);
			p = q->next;
			num++;
		}
	}
	cout << "删除的结点个数为：" << num << endl;
	return 1;
}

int func08(LNodes* L1, LNodes* L2)
{
	int l1=0, l2=0,t=0,c=0,d=0;
	LNodes* p1, * p2;

	if (L1 != NULL && L2 != NULL)
	{
		p1 = L1;
		p2 = L2;

		while (p1)
		{
			p1 = p1->next;
			l1++;
		}

		while (p2)
		{
			p2 = p2->next;
			l2++;
		}

		p1 = L1;
		p2 = L2;

		if (l1 < l2)
		{
			c = l2 - l1;
			d = l1;
			while (p2)
			{
				p2 = p2->next;
				
				if (t == c)
					break;
				t++;
			}
		}
		else
		{
			c = l1 - l2;
			d = l2;
			while (p1)
			{
				p1 = p1->next;

				if (t == c)
					break;
				t++;
			}
		}
		
		for (int i = 0; i < d; i++)
		{
			if (p1 == NULL || p2 == NULL)
				break;
			if (p1 == p2->next)
			{
				cout << p1->data << endl;
				//break;
			}
			p1 = p1->next;
			p2 = p2->next;
		}

		return 1;
	}

	return 0;
}

int func09(LNodes* L)
{
	LNodes* p, * q;
	int l = Length(L, 1), t;

	p = L->next;

	if (p != NULL)
	{
		q = p->next;
		for (int i = 0; i < l; i++)
		{
			while (q)
			{
				if (p->data > q->data)
				{
					t = q->data;
					q->data = p->data;
					p->data = t;
				}
				p = p->next;
				q = q->next;
			}
			p = L->next;
			q = p->next;
		}

		p = L->next;
		q = p->next;
		L->next = NULL;

		while (q)
		{
			cout << p->data << " ";
			free(p);

			p = q;
			q = p->next;
		}
		cout << endl;

		return 1;
	}
	return 0;
}

int func10(LNodes* L,LinkedList& L1,LinkedList &L2)
{
	LNodes* p, * p1, * p2,*q;
	int num = 0;

	if (L->next != NULL)
	{
		p = L->next;
		q = p->next;
		p1 = L1;
		p2 = L2;

		while (p)
		{
			if (num % 2)
			{
				p->next = p2->next;
				p2->next = p;
				p2 = p2->next;
			}
			else
			{
				p->next = p1->next;
				p1->next = p;
				p1 = p1->next;
			}
			p = q;
			if (p)
				q = p->next;
			num++;
		}

		return 1;
	}
	return 0;
}

LinkedList func11(LNodes* L)
{
	LNodes* p, * p1, * q1, * q;
	int num = 0, l = Length(L, 1);

	LinkedList re = LinkedListInit(1);

	if (L->next != NULL)
	{
		p = L->next;
		q = L;
		q1 = p->next;

		p1 = re;

		while (q)
		{

			if (num % 2)
			{
				q->next = p->next;
				p->next = p1->next;
				p1->next = p;

				p1 = p1->next;
				//cout << "表2：" << p1->data << endl;

				if (q1 == NULL)
				//线性表长度为偶数时跳出循环的条件
				{
					break;
				}
				else if (q1->next == NULL)
				//线性表长度为奇数时跳出循环的条件
					break;
				//能不能想个办法统一起来？
			
				p = q1;
				q1 = p->next;
			}
			else
			{
				//cout << "表1：" << p->data << endl;
				q = q->next;
				p = p->next;
				q1 = q1->next;
			}
			num++;
		}
		return re;
	}
	return NULL;
}

int func12(LNodes* L)
{
	LNodes* p, * q;

	if (L->data == -1)
	{
		if (L->next != NULL)
		{
			p = L->next;
			q = L;

			while (p)
			{
				if (p->data == q->data)
				{
					q->next = p->next;
				}
				else
					q = q->next;
				p = p->next;
			}

			return 1;
		}
	}
	else
	{
		q = L;
		p = L->next;

		while (p)
		{
			if (p->data == q->data)
			{
				q->next = p->next;
			}
			else
				q = q->next;
			p = p->next;
		}

		return 1;
	}

	return 0;
}

int func13(LinkedList& L1, LinkedList L2)
//默认为带头结点的单链表
{
	LNodes* p1, * p2, * q1, * q2, * r1, * r2, * re;

	if (L1->next == NULL && L2->next == NULL)
	{
		return 0;
	}

	p1 = L1->next;
	p2 = L2->next;

	q1 = p1->next;
	q2 = p2->next;

	re = L1;
	re->next = NULL;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			q1 = p1->next;

			p1->next = re->next;
			re->next = p1;

			p1 = q1;
		}
		else
		{
			q2 = p2->next;

			p2->next = re->next;
			re->next = p2;

			p2 = q2;
		}
	}

	if (p1 != NULL)
	{
		q1 = p1->next;
		while (p1)
		{
			q1 = p1->next;

			p1->next = re->next;
			re->next;

			p1 = q1;
		}
	}

	if (p2 != NULL)
	{
		q2 = p2->next;
		while (p2)
		{
			q2 = p2->next;

			p2->next = re->next;
			re->next = p2;

			p2 = q2;
		}
	}
	
	return 1;
}

LinkedList func14(LNodes* L1,LNodes* L2)
{
	int tou = 1;
	LinkedList re;
	LNodes*p1, *p2,*t;
	re = LinkedListInit(tou);

	
	p1 = L1->next;
	p2 = L2->next;


	if (L1->next != NULL && L2->next != NULL)
	{
		while (p1 != NULL)
		{
			p2 = L2->next;
			while (p2 != NULL)
			{
				if (p1->data == p2->data)
				{
					t = (LNodes*)malloc(sizeof(LNodes));
					t->data = p1->data;

					t->next = re->next;
					re->next = t;
				}
				p2 = p2->next;
			}
			
			p1 = p1->next;
			
		}
		

		return re;
	}
	return NULL;
}