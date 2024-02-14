#include<iostream>
using namespace std;
char path[100];  //路径数组，存储路径上每个结点的值

typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
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
void AllPath(BiTree T, char path[], int pathlen)
{//二叉树叶子结点到根结点的路径的求解
	if (T != NULL)
	{
		if (T->lchild == NULL && T->rchild == NULL)//遇到了叶子节点
		{
			path[pathlen] = T->data;
			for (int i = pathlen; i>=0;--i)//从叶子节点遍历到根节点
				//输出这条路径上的节点的值
			{
				cout << path[i];
			}
			cout << endl;
		}
		else//未到叶子节点
		{
			path[pathlen] = T->data;
			pathlen++;//从叶子节点到根节点
			AllPath(T->lchild,path,pathlen);
			AllPath(T->rchild, path, pathlen);
			pathlen--;//开始从叶子节点回溯
		}
	}
}
int main()
{
	char S[100];
	while (cin >> S && S[0] != '0')
	{
		int i = -1;
		BiTree T;
		CreateBiTree(T, S, ++i);
		int pathlen = 0;         //初始化路径到根结点的长度为0
		AllPath(T, path, pathlen);
	}
	return 0;
}