#include<iostream>
#include<cstring>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{//先序建立二叉树
	if (S[i] == '0')//值为0，则该节点为空
	{
		T = NULL;
	}
	else//递归建树
	{
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
void ChangeRL(BiTree& T)
{//二叉树左右孩子的交换
	//递归交换左右孩子
	if (T == NULL)return;
	if (T->lchild == NULL && T->rchild == NULL)
	{
		return;//只有根节点也返回
	}
	else//其他情况交换左右孩子
	{
		BiTree temp = new BiTNode;
		temp = T->rchild;
		T->rchild = T->lchild;
		T->lchild = temp;
	}
	//递归继续交换下面的左右孩子
	ChangeRL(T->lchild);
	ChangeRL(T->rchild);
}
void PreOrderTraverse(BiTree T)
{//先序遍历
	if (T != NULL)//若该节点非空，则继续遍历
	{
		cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
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
		ChangeRL(T);
		PreOrderTraverse(T);
		cout << endl;
	}
	return 0;
}
