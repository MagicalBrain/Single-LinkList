#pragma comment(lib,"winmm.lib")
#include <iostream>
#include <Windows.h>
#include "LinkList.h"
#include "TestFunction.h"

using namespace std;

const int tou = 0;


//辅助计时函数
DWORD Second()
{
	DWORD Start = timeGetTime();    //记录开始的时间
	Sleep(1000);    //等待1秒
	DWORD End = timeGetTime();
	return Start - End;
}

/*
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
*/


int main()
{
	//test_LinkListInput();
	//test_Length();
	//test_LocateElem();
	//test_GetElem();
	test_LinkListInsert();

	return 0;
}