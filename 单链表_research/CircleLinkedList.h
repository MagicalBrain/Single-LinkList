#pragma once
#include <iostream>
#include <string.h>
#include "CreatFunction.h"
#include "LinkList.h"

using namespace std;


//循环单链表基本操作：

////1、初始化循环单链表
LinkedList CircleLinkedListInit(int tou) {
	/*参数:
	tou:
	1:初始化成带头结点的
	0：~不带头节点的
	*/
	LinkedList L;
	L = (LinkedList)malloc(sizeof(LNodes));   //申请结点空间   
	if (L == NULL) { //判断是否有足够的内存空间   
		printf("申请内存空间失败\n");
	}
	if (tou)
	{
		L->data = -1;
		L->next = L;
	}
	//将next设置为NULL,初始长度为0的单链表
	else
		L = L;//将next设置为NULL,初始长度为0的单链表   
	return L;
}


////7、输出操作
//输出循环单链表内所有元素的数据
int CircleLinkedOutput(LinkedList L, int tou)
{
	//put(str);
	if (tou)
	{
		if (L->next != L)
		{
			LNodes* p = L->next;
			while (p != L)
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
			LNodes* p = L;
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


void CircleLinkedInput(LinkedList& L, int tou) {
	/*参数:
	tou:
	1:初始化成带头结点的
	0：~不带头节点的
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