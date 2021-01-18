#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "btree.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* src, int n, int* idx)
{
	if (src[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = src[*idx];
	(*idx)++;

	node->_left = BinaryTreeCreate(src, n, idx);
	node->_right = BinaryTreeCreate(src, n, idx);
	return node;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root)
	{
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
		*root = NULL;
	}
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root)
	{
		if (root->_data == x)
			return root;
		BTNode* node = BinaryTreeFind(root->_left, x);
		if (node)
			return node;
		else
			return BinaryTreeFind(root->_right, x);
	}
	else
	{
		return NULL;
	}
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* node = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", node->_data);
		if (node->_left)
			QueuePush(&q, node->_left);
		if (node->_right)
			QueuePush(&q, node->_right);
	}
	printf("\n");
}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* node = QueueFront(&q);
		QueuePop(&q);

		if (node)
		{
			QueuePush(&q, node->_left);
			QueuePush(&q, node->_right);
		}
		else
			break;
	}
	while (!QueueEmpty(&q))
	{
		BTNode* node = QueueFront(&q);
		QueuePop(&q);
		if (node)
			return 0;
	}
	return 1;
}

// ���������
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeHeight(root->_left) > BinaryTreeHeight(root->_right) ? BinaryTreeHeight(root->_left) + 1 : BinaryTreeHeight(root->_right) + 1;
}

void test()
{
	char src[] = "ABD##E#H##CF##G##";
	int idx = 0;
	BTNode* node = BinaryTreeCreate(src, 0, &idx);
	BinaryTreePrevOrder(node);
	printf("\n");
	BinaryTreeInOrder(node);
	printf("\n");
	BinaryTreePostOrder(node);
	printf("\n");
	BinaryTreeLevelOrder(node);
	printf("\n");
	printf("%d ", BinaryTreeComplete(node));
}

int main()
{
	test();
	return 0;
}