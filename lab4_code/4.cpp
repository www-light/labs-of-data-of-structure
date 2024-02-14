#include<iostream>
#include <string.h>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{//先序建立二叉树 //重点体会，比较简单呈现递归思想
	if (S[i] == '0')
	{
		T = NULL;
	}
	else
	{
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
void DoubleTraverse(BiTree T)
{//双序遍历二叉树T的递归算法
	if (T != NULL)
	{
		cout << T->data;//先访问这个节点
		DoubleTraverse(T->lchild);//在双序遍历它的左子树
		cout << T->data;//再访问这个节点
		DoubleTraverse(T->rchild);//在双序遍历它的右子树
	}
}
int main()
{
	char S[100];
	while (cin >> S)
	{
		if (strcmp(S, "0") == 0) break;
		int i = -1;
		BiTree T;
		CreateBiTree(T, S, ++i);
		DoubleTraverse(T);
		cout << endl;
	}
	return 0;
}