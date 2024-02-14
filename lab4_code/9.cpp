#include<iostream>
#include<string.h>
using namespace std;

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
void Count(BiTree T, int& a, int& b, int& c)
{//二叉树结点个数的统计
	if (T)
	{
		if (T->lchild != NULL && T->rchild != NULL) {//左右孩子都非空
			c++;
		}
		else if (T->lchild == NULL && T->rchild == NULL)//左右孩子都为空
		{
			a++;
		}
		else//只有一个孩子
		{
			b++;
		}
		Count(T->lchild,a,b,c);
		Count(T->rchild,a,b,c);
}
}
/*void Count(BiTree T, int& n)
{//二叉树结点个数的统计
	if (T == NULL)
{
	return ;
}
 if(T!=NULL)
 {
 	n++;
} 
Count(T->lchild, n);
//后++,返回的是右值
//前++返回的是左值
Count(T->rchild, n);
}*/
int main()
{

	char S[100];
	while (cin >> S)
	{
		if (strcmp(S, "0") == 0) break;
		int a = 0, b = 0, c = 0;
		int i = -1;
		BiTree T;
		CreateBiTree(T, S, ++i);
		Count(T, a, b, c);
		cout << a << " " << b << " " << c << endl;
	}
	return 0;
}

