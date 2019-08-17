#include <iostream>
#include <string.h>
#include "LinkList.h"
//#include "CreatFunction.h"

using namespace std;

/*-------------------以下是以前写的函数（做的题）-------------------------------*/

//删除数值范围在mink~maxk的节点的函数
void Delete_min_max(LinkedList &L, int mink, int maxk);

//删除相同节点函数
void Delete_same_point(LinkedList &L);

//单链表就地逆置函数
////头插法
void Inv_danlianbiao(LinkedList &L);

//单链表合并函数
LinkedList Merge_danlianbiao_01(LinkedList L1, LinkedList L2);

//单链表合并函数
LinkedList Merge_danlianbiao_0201(LinkedList L1, LinkedList L2);

//单链表合并函数
//进行同时扫描，没有使用逆置函数
LinkedList Merge_danlianbiao_0202(LinkedList L1, LinkedList L2);

//单链表合并函数
LinkedList Merge_danlianbiao_03(LinkedList L1, LinkedList L2);
/*
进行同时扫描，没有使用逆置函数
要求递增有序
另外开启空间
*/

//删除数值范围在mink~maxk的节点的函数
void Delete_min_max(LinkedList &L, int mink, int maxk)
{
	//获取长度
	int num = 0;
	LNodes* p = L->next;
	LNodes* q = L;
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
		}
		//num++;
	}
}


//删除相同节点函数
void Delete_same_point(LinkedList &L)
{
	//获取长度
	int num = 0, flag = 0;
	LNodes* p = L->next;
	while (p != NULL)
	{
		p = p->next;
		num++;
	}

	//构建数组存储次数，计数
	int* count = (int *)malloc(num * sizeof(int));
	LNodes* q = L;
	num = 0;
	p = L->next;
	while (p != NULL)
	{
		if (num == 0)
		{
			count[num] = p->data;
			//num++;
		}
		else
		{
			flag = 0;
			for (int i = 0; i < num; i++)
			{
				if (p->data == count[i])
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{
				LNodes* m = p;
				q->next = m->next;
				free(m);
				p = q->next;
				//num++;
				continue;

			}
			else
			{
				count[num] = p->data;
			}

		}
		p = p->next;
		q = q->next;
		num++;
	}
}


//单链表就地逆置函数
////头插法
void Inv_danlianbiao(LinkedList &L)
{
	LinkedList p = L->next, q = p->next;
	//LinkedList x, z;

	L->next = NULL;
	while (p != NULL)
	{
		q = p->next;

		p->next = L->next;
		L->next = p;

		p = q;
	}

}


//单链表合并函数
LinkedList Merge_danlianbiao_01(LinkedList L1, LinkedList L2)
{
	LinkedList p1 = L1->next;
	LinkedList p2 = L2->next;
	LinkedList s2 = L2;

	while ((p1->next != NULL) && (p2 != NULL))
	{
		s2->next = p2->next;
		p2->next = p1->next;
		p1->next = p2;

		p1 = p1->next->next;
		p2 = s2->next;
	}
	if (p1->next == NULL && p2 != NULL)
	{
		p1->next = p2;
	}
	return L1;
}


//单链表合并函数
LinkedList Merge_danlianbiao_0201(LinkedList L1, LinkedList L2)
{
	LinkedList p1 = L1->next;
	LinkedList p2 = L2->next;
	LinkedList s = L2, s2 = L2, re = L1;

	if (p1->data > p2->data)
	{
		//s2 = p1;
		p1 = L2->next;
		p2 = L1->next;
		s = L1;
		s2 = L1;
		re = L2;
	}

	while ((p1->next != NULL))
	{
		p2 = s->next;
		s2 = s;
		while ((p2 != NULL))
		{
			if (p1->data <= p2->data && p1->next->data > p2->data)
			{
				s2->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;

				p1 = p1->next;
				p2 = s2->next;
			}
			else
			{
				s2 = s2->next;
				p2 = p2->next;
			}

		}
		p1 = p1->next;
	}
	if (p1->next == NULL && s->next != NULL)
	{
		p1->next = s->next;
	}

	Inv_danlianbiao(re);

	return re;
}


//单链表合并函数
//进行同时扫描，没有使用逆置函数
LinkedList Merge_danlianbiao_0202(LinkedList L1, LinkedList L2)
{
	LinkedList p1 = L1->next;
	LinkedList p2 = L2->next;
	LinkedList s1 = L1, s2 = L2, re = L1, st = L2;
	int flag = 0;

	if (p1->data > p2->data)
	{
		//s2 = p1;
		p1 = L2->next;
		p2 = L1->next;
		s1 = L2;
		s2 = L1;
		re = L2;
		st = L1;
	}

	p1 = p1->next;
	s1 = s1->next;

	while (p2 != NULL && p1 != NULL)
	{
		flag = 0;
		if (p1->data < p2->data)
		{
			s1->next = p1->next;

			p1->next = s2->next;
			s2->next = p1;
			s2 = s2->next;

			p1 = s1->next;
			//p2 = p2->next;
			flag = 1;
		}
		if (!flag)
		{
			p2 = p2->next;
			s2 = s2->next;
		}

	}

	p2 = st->next;
	while (p2 != NULL)
	{
		st->next = p2->next;

		p2->next = re->next;
		re->next = p2;
		p2 = st->next;
	}

	return re;
}


//单链表合并函数
/*
进行同时扫描，没有使用逆置函数
要求递增有序
另外开启空间
*/
LinkedList Merge_danlianbiao_03(LinkedList L1, LinkedList L2)
{
	LinkedList p1 = L1->next;
	LinkedList p2 = L2->next;
	LinkedList s1 = L1, s2 = L2, re, st;
	int flag = 0;

	re = (LinkedList)malloc(sizeof(LNodes));
	re->next = NULL;
	st = re;


	while (p2 != NULL && p1 != NULL)
	{
		LinkedList p0;
		p0 = (LinkedList)malloc(sizeof(LNodes));
		if (p1->data > p2->data)
		{
			p0->data = p2->data;

			p2 = p2->next;
		}
		else
		{
			p0->data = p1->data;

			p1 = p1->next;
		}
		p0->next = st->next;
		st->next = p0;
		st = st->next;
	}

	while (p1 != NULL || p2 != NULL)
	{

	}


	return re;
}