#pragma comment(lib,"winmm.lib")
#include <iostream>
#include <Windows.h>
#include "danlianbiao.h"

using namespace std;

const int tou = 0;


//单链表合并函数
////进行同时扫描，没有使用逆置函数
////要求递增有序
////另外开启空间
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



//辅助计时函数
DWORD Second()
{
	DWORD Start = timeGetTime();    //记录开始的时间
	Sleep(1000);    //等待1秒
	DWORD End = timeGetTime();
	return Start - End;
}


int main()
{
	int a1[] = { 1,2,3,9,11,21,31,41,51,61,71 };
	int a2[] = { 8,11,45,91,120,210 };

	LinkedList L1 = LinkedListInit(tou);
	//LinkedList L2 = LinkedListInit();

	LinkedInput(L1, a1, sizeof(a1) / sizeof(int), tou);
	//LinkedInput(L2, a2, sizeof(a2) / sizeof(int),1);

	LinkedOutput(L1, tou);
	//LinkedOutput(L2,1);

	//无头结点的单链表的头插法实现
	for (int i = 0; i < 6; i++)
	{
		LinkedList L2 = (LinkedList)malloc(sizeof(LNodes));
		L2->data = a2[i];
		L2->next = L1;
		L1 = L2;

	}
	
	LinkedOutput(L1, tou);

	return 0;
}