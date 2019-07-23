#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
void QueueInit(Queue* pq)
{
	pq->front = pq->rear=pq->data;
	pq->size = 0;
}

void QueueDestory(Queue* pq)
{
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}

void QueuePush(Queue* pq, QuDataType x)
{
	if (pq->size + 1 == QueueMAX)//¶ÓÁĞÒÑÂú
	{
		return;
	}
	*pq->rear= x;
	pq->rear++;
	pq->size++;
	if (pq->rear - pq->data == QueueMAX)
	{
		pq->rear = pq->data;
	}
}
void QueuePop(Queue* pq)
{
	if (pq->size == 0)
	{
		return 0;
	}
	pq->front++;
	pq->size--;
	if (pq->rear - pq->data == QueueMAX)
	{
		pq->front = pq->data;
	}
}

QuDataType QueueFront(Queue* pq)
{
	if (pq->size == 0)
	{
		return (QuDataType)0;
	}
	return *pq->front;
}
QuDataType QueueBack(Queue* pq)
{
	if (pq->rear == pq->data)
	{
		return pq->data[QueueMAX - 1];
	}
	return *pq->rear;
}

