#include<iostream>
using namespace std;
char path[100];  //·�����飬�洢·����ÿ������ֵ

typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{//������������
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
{//������Ҷ�ӽ�㵽������·�������
	if (T != NULL)
	{
		if (T->lchild == NULL && T->rchild == NULL)//������Ҷ�ӽڵ�
		{
			path[pathlen] = T->data;
			for (int i = pathlen; i>=0;--i)//��Ҷ�ӽڵ���������ڵ�
				//�������·���ϵĽڵ��ֵ
			{
				cout << path[i];
			}
			cout << endl;
		}
		else//δ��Ҷ�ӽڵ�
		{
			path[pathlen] = T->data;
			pathlen++;//��Ҷ�ӽڵ㵽���ڵ�
			AllPath(T->lchild,path,pathlen);
			AllPath(T->rchild, path, pathlen);
			pathlen--;//��ʼ��Ҷ�ӽڵ����
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
		int pathlen = 0;         //��ʼ��·���������ĳ���Ϊ0
		AllPath(T, path, pathlen);
	}
	return 0;
}