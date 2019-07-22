#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "List.h"

int main()
{
	List list1,list2;

	ListInit(&list1);
	ListInit(&list2);

	ListPushBack(&list1, 5);
	ListPushBack(&list1, 8);
	ListPushBack(&list1, 9);
	ListPushFront(&list1, 2);
	ListPushFront(&list1, 1);

	ListPushBack(&list2, 6);
	ListPushBack(&list2, 7);
	ListPushBack(&list2, 10);
	ListPushFront(&list2, 4);
	ListPushFront(&list2, 3);
	//ListPopFront(&list1);
	//ListPopBack(&list1);

	//ListRemove(&list1, 8);
	//ListPrint(&list1);
	//ListPrint(&list2);

	//ListMerge(&list1,&list2);
	//ListDestory(&list1);
	ListMerge(&list1, &list2);
	ListPrint(&list1);
	ListPrint(&list2);
	system("pause");
	return 0;
}