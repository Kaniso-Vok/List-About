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


void ListInit(List* plist);//初始化
void ListDestory(List* plist);//清空链表

void ListPushBack(List* plist, LTDataType x);//后插
void ListPopBack(List* plist);//后删
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);

ListNode* ListFind(List* plist, LTDataType x);//查找

void ListMerge(List* pList1, List* pList2);//将有序链表有序合并

void ListInsertFront(ListNode* pos, LTDataType x);
void ListInsertAfter(ListNode* pos, LTDataType x);
// ????pos??????????
void ListErase(ListNode* pos);//删除
void ListRemove(List* plist, LTDataType x);//移除指定
void ListRemoveAll(List* plist, LTDataType x);//移除指定的全部
void ListPrint(List* plist);//打印

#endif /*_LIST_H_*/