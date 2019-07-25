#ifndef _BTREE_H_
#define _BTREE_H_
#define ENDTAG '#'
#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
BTNode* BinaryTreeCreate(BTDataType* a);
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

#endif