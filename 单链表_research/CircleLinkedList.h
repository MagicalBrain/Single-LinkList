#pragma once
#include <iostream>
#include <string.h>
#include "CreatFunction.h"
#include "LinkList.h"

using namespace std;


//ѭ�����������������

////1����ʼ��ѭ��������
LinkedList CircleLinkedListInit(int tou) {
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
	{
		L->data = -1;
		L->next = L;
	}
	//��next����ΪNULL,��ʼ����Ϊ0�ĵ�����
	else
		L = L;//��next����ΪNULL,��ʼ����Ϊ0�ĵ�����   
	return L;
}


////7���������
//���ѭ��������������Ԫ�ص�����
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

	cout << "���ʧ�ܣ���Ϊ�գ�" << endl;
	return 0;
}


void CircleLinkedInput(LinkedList& L, int tou) {
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