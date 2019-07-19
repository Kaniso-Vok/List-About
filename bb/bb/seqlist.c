#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

void SeqListInit(SeqList* psl, size_t capacity)//初始化
{
	psl->array = (SLDataType*)calloc(capacity, sizeof(SLDataType));
	psl->capacity = capacity;
	psl->size = 0;
}
void SeqListDestory(SeqList* psl);

void CheckCapacity(SeqList* psl)//检查和动态开辟
{
	if (psl->size >= psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, sizeof(SLDataType)*psl->capacity);
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)//尾插
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)//尾删
{
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)//首插
{
	int i;
	CheckCapacity(psl);
	for (i = 1; i < psl->size-1; i++)
	{
		psl->array[i] = psl->array[i - 1];
		
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)//首删
{
	int i;
	for (i = 0; i < psl->size-1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//查询
{
	int i;
	for (i = 0; i < psl->size - 1; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//插入
{
	int i;
	for (i=psl->size-1; i>=pos; i--)
	{
		psl->array[i+1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)//删除指定下标
{
	int i;
	for (i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x)//筛选删除
{
	SeqListErase(psl, SeqListFind(psl, x));
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	psl->array[pos] = x;
}
void SeqListPrint(SeqList* psl)
{
	int i;
	for (i = 0; i < i < psl->size - 1; i++)
	{
		printf("%d->", psl->array[i]);
	}
	putchar('\n');
}

void SeqListBubbleSort(SeqList* psl)
{
	int i, j;
	SLDataType tmp;
	for (i = 0; i < psl->size - 1; i++)
	{
		for (j = 0; i < psl->size - 1; j++)
		{
			if (psl->array[j]>psl->array[j + 1])
			{
				psl->array[j] = tmp;
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{

}
void SeqListRemoveAll(SeqList* psl, SLDataType x);