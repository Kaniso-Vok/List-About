#ifndef _LIST_H_
#define _LIST_H_
#include <stdio.h>
#include<stdlib.h>

typedef int LTDataType;
typedef struct ListNode {
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List {
	ListNode* _head;
}List;


void ListInit(List* plist);//��ʼ��
void ListDestory(List* plist);//�������

void ListPushBack(List* plist, LTDataType x);//���
void ListPopBack(List* plist);//��ɾ
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);

ListNode* ListFind(List* plist, LTDataType x);//����

void ListMerge(List* pList1, List* pList2);//��������������ϲ�

void ListInsertFront(ListNode* pos, LTDataType x);
void ListInsertAfter(ListNode* pos, LTDataType x);
// ????pos??????????
void ListErase(ListNode* pos);//ɾ��
void ListRemove(List* plist, LTDataType x);//�Ƴ�ָ��
void ListRemoveAll(List* plist, LTDataType x);//�Ƴ�ָ����ȫ��
void ListPrint(List* plist);//��ӡ

#endif /*_LIST_H_*/