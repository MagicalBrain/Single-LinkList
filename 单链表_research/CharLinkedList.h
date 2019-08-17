#pragma once
#include <string.h>
#include <list>
#include "CreatFunction.h"

using namespace std;

//#define ElemType int

//元素键值类型为字符型
typedef struct SLNodes
{
	char data;
	struct SLNodes *next;
} SLNodes, *SLinkedList;

////1、初始化链表
SLinkedList SLinkedListInit(int tou) {
	/*参数:
	tou:
	1:初始化成带头结点的
	0：~不带头节点的
	*/
	SLinkedList L;
	L = (SLinkedList)malloc(sizeof(SLNodes));   //申请结点空间   
	if (L == NULL) { //判断是否有足够的内存空间   
		printf("申请内存空间失败\n");
	}
	if (tou)
	{
		L->data = 0;
		L->next = NULL;
	}
	//将next设置为NULL,初始长度为0的单链表
	else
		L = NULL;//将next设置为NULL,初始长度为0的单链表   
	return L;
}


////7、输出操作
//输出链表内所有元素的数据
int SLinkedOutput(SLinkedList L, int tou)
{
	//put(str);
	if (tou)
	{
		if (L->next != NULL)
		{
			SLNodes* p = L->next;
			while (p != NULL)
			{
				cout << p->data << " ,";
				p = p->next;

			}
			cout << endl;
			return 1;
		}

	}
	else
	{
		if (L != NULL)
		{
			SLNodes* p = L;
			while (p != NULL)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
			return 1;
		}

	}

	cout << "输出失败！表为空！" << endl;
	return 0;
}


void SLinkedInput(SLinkedList& L, char a[], int length, int tou) {
	/*参数:
	tou:
	1:初始化成带头结点的
	0：~不带头节点的
	*/
	
	if (tou)
	{
		SLinkedList q = L;
		for (int i = length-1; i >= 0; --i)
		{
			SLNodes* p = (SLinkedList)malloc(sizeof(SLNodes));
			p->data = a[i];
			p->next = q->next;
			q->next = p;
		}
	}
	else
	{
		SLinkedList q = L;
		//q->data = a[0];
		for (int i = length; i >= 0; --i)
		{
			SLNodes* p = (SLinkedList)malloc(sizeof(SLNodes));
			p->data = a[i];
			p->next = L;
			L = p;
		}
	}

}