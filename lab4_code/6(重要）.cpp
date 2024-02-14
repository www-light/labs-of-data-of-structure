#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
//�������ı����Ĺ��̾�����ÿһ�����˼·
void CreateBiTree(BiTree& T, char S[], int& i)
{//������������
	if (S[i]=='0')
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
int max_len;
void LongestPath(BiTree T, BiTree l[], int& longest)
{//�������·������� 
	//�����longestҲ��Ϊ�����±꣬l����洢·���ϵĽڵ�
	//ʹ�õݹ����
	if (T) {
		if (T->lchild || T->rchild) {
			longest++;
			l[longest] = T;
			LongestPath(T->rchild, l, longest);
			LongestPath(T->lchild, l, longest);
			longest--;
			if (longest == 0) {
				longest = max_len;
				max_len = 0;
			}
		}
		else {
			longest++;
			if (longest >= max_len || max_len == 0) {
				l[longest] = T;
				max_len = longest;
			}
			longest--;
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
		BiTree l[MAXSIZE];
		int longest = 0;
		CreateBiTree(T, S, ++i);
		LongestPath(T, l, longest);
		cout << longest << endl;
		for (int k = 1; k <= longest; k++)
			cout << l[k]->data;
		cout << endl;
	}
	return 0;
}
