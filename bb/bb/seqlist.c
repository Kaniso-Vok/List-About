#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

void SeqListInit(SeqList* psl, size_t capacity)//��ʼ��
{
	psl->array = (SLDataType*)calloc(capacity, sizeof(SLDataType));
	psl->capacity = capacity;
	psl->size = 0;
}
void SeqListDestory(SeqList* psl);

void CheckCapacity(SeqList* psl)//���Ͷ�̬����
{
	if (psl->size >= psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, sizeof(SLDataType)*psl->capacity);
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)//β��
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)//βɾ
{
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)//�ײ�
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
void SeqListPopFront(SeqList* psl)//��ɾ
{
	int i;
	for (i = 0; i < psl->size-1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//��ѯ
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
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//����
{
	int i;
	for (i=psl->size-1; i>=pos; i--)
	{
		psl->array[i+1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)//ɾ��ָ���±�
{
	int i;
	for (i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x)//ɸѡɾ��
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