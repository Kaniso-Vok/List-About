#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

int main()
{
	SeqList test;

	SeqListInit(&test, 11);

	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 8);
	SeqListPushBack(&test, 8);
	SeqListPushBack(&test, 8);
	SeqListPushBack(&test, 8);
	SeqListPushBack(&test, 4);
	SeqListPushFront(&test, 8);
	SeqListPushFront(&test, 9);
	SeqListPushFront(&test, 10);
	
	//SeqListPopFront(&test);
	//SeqListPopFront(&test);
	//SeqListPopFront(&test);
	//SeqListPopFront(&test);
	//SeqListPopBack(&test);
	//SeqListPopBack(&test);
	//SeqListRemoveAll(&test, 8);

	SeqListBubbleSort(&test);

	//SeqListErase(&test, SeqListBinaryFind(&test, 7));

	SeqListPrint(&test);
	SeqListDestory(&test);
	SeqListPrint(&test);
	system("pause");
	return 0;
}