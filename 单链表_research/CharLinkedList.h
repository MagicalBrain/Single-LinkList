#pragma once
#include <string.h>
#include <list>
#include "CreatFunction.h"

using namespace std;

//#define ElemType int

//Ԫ�ؼ�ֵ����Ϊ�ַ���
typedef struct SLNodes
{
	char data;
	struct SLNodes *next;
} SLNodes, *SLinkedList;

////1����ʼ������
SLinkedList SLinkedListInit(int tou) {
	/*����:
	tou:
	1:��ʼ���ɴ�ͷ����
	0��~����ͷ�ڵ��
	*/
	SLinkedList L;
	L = (SLinkedList)malloc(sizeof(SLNodes));   //������ռ�   
	if (L == NULL) { //�ж��Ƿ����㹻���ڴ�ռ�   
		printf("�����ڴ�ռ�ʧ��\n");
	}
	if (tou)
	{
		L->data = 0;
		L->next = NULL;
	}
	//��next����ΪNULL,��ʼ����Ϊ0�ĵ�����
	else
		L = NULL;//��next����ΪNULL,��ʼ����Ϊ0�ĵ�����   
	return L;
}


////7���������
//�������������Ԫ�ص�����
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

	cout << "���ʧ�ܣ���Ϊ�գ�" << endl;
	return 0;
}


void SLinkedInput(SLinkedList& L, char a[], int length, int tou) {
	/*����:
	tou:
	1:��ʼ���ɴ�ͷ����
	0��~����ͷ�ڵ��
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