#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"SList.h"

void SListInit(SListNode** pphead)
{
	*pphead = NULL;
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* res = (SListNode*)malloc(sizeof(SListNode));
	res->data = x;
	res->next = NULL;
	return res;
}
void SListPushFront(SListNode** pphead, SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}
void SListPopFront(SListNode** pphead)
{
	SListNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}
void SListInsertAfter(SListNode* pos, SLTDataType x)//���
{
	SListNode* tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}
// ��pos��ǰ����в���
void SListEraseAfter(SListNode* pos)//��ɾ
{
	SListNode* tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
}

SListNode* SListFind(SListNode* phead, SLTDataType x)//����
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
	}
	return NULL;
}

void SListRemoveA(SListNode** pphead, SLTDataType x)//ɾ��ĳ��ֵ�����нڵ�
{
	SListNode* tmp;
	while(*pphead&&(*pphead)->data==x)
	{
		SListPopFront(pphead);
	}
	for (tmp = *pphead;tmp&&tmp->next; )
	{		
		if (tmp->next->data==x)
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->next;
		}
	}
}

void SListPrint(SListNode* phead)
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	if (tmp == NULL)
	{
		printf("NULL");
	}
	printf("\n");
}

void SListDestory(SListNode* phead)//����һ�����Ϻ�ɾ(�˴�)��������������ͷɾ
{
	while (phead->next)
	{
		SListEraseAfter(phead);
	}
	free(phead);
	//phead = NULL;
}