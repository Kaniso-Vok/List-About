#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

void SeqListInit(SeqList* psl, size_t capacity)//��ʼ��
{
	psl->array = (SLDataType*)calloc(capacity, sizeof(SLDataType));
	psl->capacity = capacity;
	psl->size = 0;
}
void SeqListDestory(SeqList* psl)
{
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->capacity = 0;
		psl->size = 0;
	}
}

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
	for (i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i+1] = psl->array[i];
		
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)//��ɾ
{
	size_t i;
	for (i = 0; i < psl->size-1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//��ѯ
{
	size_t i;
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
	size_t i;
	for (i=psl->size-1; i>=pos; i--)
	{
		psl->array[i+1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)//ɾ��ָ���±�
{
	size_t i;
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
	size_t i;
	for (i = 0; i <=psl->size - 1; i++)
	{
		if (psl->array == NULL)
		{
			printf("NULL");
			return;
		}
	    printf("%d->", psl->array[i]);
	}
	putchar('\n');
}

void SeqListBubbleSort(SeqList* psl)
{
	size_t i, j;
	SLDataType tmp;
	for (i = 0; i < psl->size - 1; i++)
	{
		for (j = 0; j < psl->size - 1; j++)
		{
			if (psl->array[j] > psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	int left = 0, right = psl->size;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		if (x < psl->array[mid])
		{
			right = mid-1;
		}
		if (x>psl->array[mid])
		{
			left = mid+1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	size_t i, gap = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			gap++;
		}
		else
		{
			psl->array[i - gap] = psl->array[i];
		}
	}
	psl->size -= gap;
}