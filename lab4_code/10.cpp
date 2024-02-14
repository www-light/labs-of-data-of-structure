#include<iostream>
#include <string.h>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
//二叉树一般遍历方法---递归
//先左孩子，然后回溯，右孩子开始，然后右孩子开始递归
//递归使用的是栈；
void CreateBiTree(BiTree& T, char S[], int& i)
{//先序建立二叉树
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
int Depth(BiTree T)
{//二叉树高度的计算
	int m = 0, n = 0;
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		m = Depth(T->lchild);//递归计算左右子树高度
		n = Depth(T->rchild);
		if (m > n)
		{
			return m + 1;//总比它的左右子树高一层
		}
		else
		{
			return n + 1;
		}
	}
}
using namespace std;

int main()
{
	char S[100];
	while (cin >> S)
	{
		if (strcmp(S, "0") == 0) break;
		int i = -1;
		BiTree T;
		CreateBiTree(T, S, ++i);
		cout << Depth(T) << endl;
	}
	return 0;
}