#pragma comment(lib,"winmm.lib")
#include <iostream>
#include <Windows.h>
#include "danlianbiao.h"

using namespace std;

const int tou = 0;


//������ϲ�����
////����ͬʱɨ�裬û��ʹ�����ú���
////Ҫ���������
////���⿪���ռ�
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



//������ʱ����
DWORD Second()
{
	DWORD Start = timeGetTime();    //��¼��ʼ��ʱ��
	Sleep(1000);    //�ȴ�1��
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

	//��ͷ���ĵ������ͷ�巨ʵ��
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