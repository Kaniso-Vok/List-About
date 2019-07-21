#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	SListNode* head;
	SListInit(&head);
	SListPushFront(&head, 3);
	SListPushFront(&head, 3);
	SListPushFront(&head, 2);
	SListPushFront(&head, 5);
	SListPushFront(&head, 3);
	SListPushFront(&head, 4);
	SListPushFront(&head, 3);
	SListPushFront(&head, 2);
	SListPushFront(&head, 1);
	SListPrint(head);

	SListRemoveA(&head, 3);
	SListPrint(head);

	SListDestory(head);
	head = NULL;
	SListPrint(head);
	
	system("pause");
	return 0;
}
