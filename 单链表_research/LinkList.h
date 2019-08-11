#pragma once
#include <iostream>
#include <string.h>
#include "CreatFunction.h"

using namespace std;

#define ElemType int

typedef struct LNodes
{
	ElemType data;
	struct LNodes *next;
} LNodes, *LinkedList;

//����������

////1����ʼ������
LinkedList LinkedListInit(int tou) {
	/*����:
	tou:
	1:��ʼ���ɴ�ͷ����
	0��~����ͷ�ڵ��
	*/
	LinkedList L;
	L = (LinkedList)malloc(sizeof(LNodes));   //������ռ�   
	if (L == NULL) { //�ж��Ƿ����㹻���ڴ�ռ�   
		printf("�����ڴ�ռ�ʧ��\n");
	}
	if (tou)
		L->next = NULL;
	//��next����ΪNULL,��ʼ����Ϊ0�ĵ�����
	else
		L = NULL;//��next����ΪNULL,��ʼ����Ϊ0�ĵ�����   
	return L;
}

////2�����
int Length(LNodes* L,int tou)
{
	LNodes* p;
	int re = 0;
	if (tou)
	{
		if (L->next == NULL)
			return 0;
		else
		{
			p = L->next;
			while (p)
			{
				re++;
				p = p->next;
			}

			return re;
		}
	}
	else
	{
		if (L == NULL)
			return 0;
		else
		{
			p = L;
			while (p)
			{
				re++;
				p = p->next;
			}
			return re;
		}
	}

	return 0;
}

////3����ֵ����
int LocateElem(LNodes* L, int tou,int e)
{
	LNodes* p;
	int num = 0;
	switch (tou)
	{
	case 1:
		if (L->next != NULL)
		{
			p = L->next;
			while (p)
			{
				if (p->data == e)
				{
					return num;
				}
				p = p->next;
				num++;
			}
		}
		break;
	case 0:
		if (L != NULL)
		{
			p = L;
			while (p)
			{
				if (p->data == e)
				{
					return num;
				}
				p = p->next;
				num++;
			}
		}
		break;
	default:
		break;
	}

	return -1;
}


////4������Ų���
int GetElem(LNodes* L, int tou, int loca)
{
	LNodes* p;
	int num = 0;
	if (loca < 0)
	{
		return -1;
	}
	if (tou == 1)
	{
		if (L->next != NULL)
		{
			p = L->next;
			while (p)
			{
				if (num == loca)
					return p->data;
				num++;
				p = p->next;
			}
		}
	}
	else if (tou == 0)
	{
		if (L != NULL)
		{
			p = L;
			while (p)
			{
				if (num == loca)
					return p->data;
				num++;
				p = p->next;
			}
		}
	}
	return -1;
}

////5���������
int LinkListInsert(LNodes* L, int tou, int e, int loca)
{
	LNodes* p, * q;
	int num = 0;
	if (loca < 0)
	{
		return -1;
	}
	if (tou == 1)
	{
		if (L->next != NULL)
		{
			p = L->next;

			if (loca == 0)
			{
				q = (LNodes*)malloc(sizeof(LNodes));
				q->data = e;

				q->next = p->next;
				p->next = q;

				int t;
				t = q->data;
				q->data = p->data;
				p->data = t;
				return 1;
			}

			while (p)
			{
				num++;
				if (num == loca)
				{
					q = (LNodes*)malloc(sizeof(LNodes));
					q->data = e;

					q->next = p->next;
					p->next = q;
					return 1;
				}
				
				p = p->next;
			}
		}
	}
	else if (tou == 0)
	{
		if (L != NULL)
		{
			p = L;

			if (loca == 0)
			{
				q = (LNodes*)malloc(sizeof(LNodes));
				q->data = e;

				q->next = p->next;
				p->next = q;

				int t;
				t = q->data;
				q->data = p->data;
				p->data = t;
				return 1;
			}

			while (p)
			{
				num++;
				if (num == loca)
				{
					q = (LNodes*)malloc(sizeof(LNodes));
					q->data = e;

					q->next = p->next;
					p->next = q;
					return 1;
				}
				p = p->next;
			}
		}
	}
	return 0;
}

////6��ɾ������

////7���������
//�������������Ԫ�ص�����
void LinkedOutput(LinkedList L, int tou)
{
	//put(str);
	if (tou)
	{
		LNodes* p = L->next;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;

		}
	}
	else
	{
		LNodes* p = L;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}

	cout << endl;
}

////8���пղ���
int isEmpty(LNodes* L, int tou)
{
	if (tou)
	{
		if (L->next == NULL)
			return 1;
		else
			return 0;
	}
	else
	{
		if (L == NULL)
			return 1;
		else
			return 0;
	}
	return 0;
}

////9�����ٲ���


//��������������
////��ͷ����
void LinkedInput(LinkedList &L, int a[], int length,int tou) {
	/*����:
	tou: 
		1:��ʼ���ɴ�ͷ����
		0��~����ͷ�ڵ��
	*/
	if (tou)
	{
		LinkedList q = L;
		for (int i = length - 1; i >= 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = q->next;
			q->next = p;
		}
	}
	else
	{
		LinkedList q = L;
		//q->data = a[0];
		for (int i = length - 1; i >= 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = L;
			L = p;
		}
	}
	
}


void LinkedInput(LinkedList& L, int tou) {
	/*����:
	tou:
		1:��ʼ���ɴ�ͷ����
		0��~����ͷ�ڵ��
	*/
	int* a;
	a = CreatRand(0);
	int length = a[0];
	if (tou)
	{
		LinkedList q = L;
		for (int i = length; i > 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = q->next;
			q->next = p;
		}
	}
	else
	{
		LinkedList q = L;
		//q->data = a[0];
		for (int i = length; i > 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = L;
			L = p;
		}
	}

}

//ɾ����ֵ��Χ��mink~maxk�Ľڵ�ĺ���
void Delete_min_max(LinkedList &L, int mink, int maxk)
{
	//��ȡ����
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


//ɾ����ͬ�ڵ㺯��
void Delete_same_point(LinkedList &L)
{
	//��ȡ����
	int num = 0, flag = 0;
	LNodes* p = L->next;
	while (p != NULL)
	{
		p = p->next;
		num++;
	}

	//��������洢����������
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


//������͵����ú���
////ͷ�巨
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


//������ϲ�����
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


//������ϲ�����
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


//������ϲ�����
//����ͬʱɨ�裬û��ʹ�����ú���
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


//������ϲ�����
/*
����ͬʱɨ�裬û��ʹ�����ú���
Ҫ���������
���⿪���ռ�
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