#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void ListInit(List* plist)
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
void ListDestory(List* plist)
{
	while (plist->_head->_next != plist->_head)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPushBack(List* plist, LTDataType x)
{
	ListInsertFront(plist->_head, x);
}
void ListPopBack(List* plist)
{
	ListErase(plist->_head->_prev);
}
void ListPushFront(List* plist, LTDataType x)
{
	ListInsertAfter(plist->_head, x);
}
void ListPopFront(List* plist)
{
	ListErase(plist->_head->_next);
}

ListNode* ListFind(List* plist, LTDataType x)
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}

void ListMerge(List* pList1, List* pList2)//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
{
	ListNode* cur1=pList1->_head->_next, *cur2=pList2->_head->_next;
	ListNode* tmp1, *tmp2;
	while (cur1 != pList1->_head&&cur2 != pList2->_head)
	{
		if (cur1->_data > cur2->_data)
		{
			tmp1 = cur1->_prev;
			tmp2 = cur2->_next;

			tmp1->_next = cur2;
			cur2->_next = cur1;
			cur1->_prev = cur2;
			cur2->_prev = tmp1;
			cur2 = tmp2;
		}
		else
		{
			cur1 = cur1->_next;
		}
	}

	if (cur1 == pList1->_head)
	{
		tmp2 = pList2->_head->_prev;
		cur2->_prev = cur1->_prev;
		cur1->_prev->_next = cur2;
		tmp2->_next = cur1;
		cur1->_prev = tmp2;
	}
	free(pList2->_head);
	pList2->_head = NULL;
}

void ListInsertFront(ListNode* pos, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	cur->_next = pos;
	cur->_prev = pos->_prev;
	pos->_prev->_next = cur;
	pos->_prev = cur;
}
void ListInsertAfter(ListNode* pos, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	cur->_prev = pos;
	cur->_next = pos->_next;
	pos->_next->_prev = cur;
	pos->_next = cur;
}
// ????pos??????????
void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
void ListRemove(List* plist, LTDataType x)
{
	ListNode * cur = ListFind(plist, x);

	if (cur)
	{
		ListErase(cur);
	}
}
void ListRemoveAll(List* plist, LTDataType x)
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			ListErase(cur);
		}
	}
}

void ListPrint(List* plist)
{
	ListNode* cur;
	if (plist->_head == NULL)
	{
		printf("NULL\n");
		return;
	}
	printf("head->");
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printf("%d-> ",cur->_data);
	}
	printf("head\n");
}