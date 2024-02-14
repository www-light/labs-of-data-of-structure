#include<iostream>
#include<cstring>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{//������������
	if (S[i] == '0')//ֵΪ0����ýڵ�Ϊ��
	{
		T = NULL;
	}
	else//�ݹ齨��
	{
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
void ChangeRL(BiTree& T)
{//���������Һ��ӵĽ���
	//�ݹ齻�����Һ���
	if (T == NULL)return;
	if (T->lchild == NULL && T->rchild == NULL)
	{
		return;//ֻ�и��ڵ�Ҳ����
	}
	else//��������������Һ���
	{
		BiTree temp = new BiTNode;
		temp = T->rchild;
		T->rchild = T->lchild;
		T->lchild = temp;
	}
	//�ݹ����������������Һ���
	ChangeRL(T->lchild);
	ChangeRL(T->rchild);
}
void PreOrderTraverse(BiTree T)
{//�������
	if (T != NULL)//���ýڵ�ǿգ����������
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
