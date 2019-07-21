
#ifndef _SLIST_H_
#define _SLIST_H_

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListInit(SListNode** phead);
void SListDestory(SListNode* phead);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SListNode** phead, SLTDataType x);
void SListPopFront(SListNode** phead);
SListNode* SListFind(SListNode* phead, SLTDataType x);

void SListInsertAfter(SListNode* pos, SLTDataType x);

void SListEraseAfter(SListNode* pos);
void SListRemoveA(SListNode** phead, SLTDataType x);
void SListPrint(SListNode* phead);
void TestSList();

#endif

