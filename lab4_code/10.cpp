#include<iostream>
#include <string.h>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
//������һ���������---�ݹ�
//�����ӣ�Ȼ����ݣ��Һ��ӿ�ʼ��Ȼ���Һ��ӿ�ʼ�ݹ�
//�ݹ�ʹ�õ���ջ��
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
int Depth(BiTree T)
{//�������߶ȵļ���
	int m = 0, n = 0;
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		m = Depth(T->lchild);//�ݹ�������������߶�
		n = Depth(T->rchild);
		if (m > n)
		{
			return m + 1;//�ܱ���������������һ��
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