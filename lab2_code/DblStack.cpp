#include<iostream>
using namespace std;
typedef int Status;
typedef struct
{
	int top[2], bot[2];//ջ����ջ��ָ��
	int* V;//ջ����
	int m;//ջ��������Ԫ�ظ���
}DblStack;
void InitDblStack(DblStack& S, int m)
{//��ʼ��һ����СΪm��˫��ջ
	//set the top of stack
	S.top[0] = -1;
	S.top[1] = m;
	S.m = m;   // ���ǳ�ʼ����������
	S.V = new int[m];
}
Status IsEmpty(DblStack S, int i)
{//�ж�ָ����i��ջ�Ƿ�Ϊ�գ��շ���1�����򷵻�0
	switch (i)
	{
	case 0:
		if (S.top[0] == -1)
		{
			return 1;
		}
		break;
	case 1:
		if (S.top[1] == S.m)
		{
			cout << "!!!" << S.top[1] << "S.m " << S.m << endl;
			return 1;
		}
		break;
	}
	return 0;
}
Status IsFull(DblStack S)
{//�ж�ջ�Ƿ��������򷵻�1�����򷵻�0
	if (S.top[0] + 1 == S.top[1])
	{
		return 1;
	}
	return 0;
}
void Push(DblStack& S, int i)
{//��ָ����i��ջ�в���Ԫ��x�����ƶ�ָ������ջ
	int x;
	cin >> x;
	if (!IsFull(S))//if not full
	{
		if (i == 0)
		{
			S.top[0]++;
			S.V[S.top[0]] = x;
		}
		else
		{
			S.top[1]--;
			S.V[S.top[1]] = x;
		}
	}
}

void Pop(DblStack& S, int i)
{//ɾ��ָ����i��ջ��ջ��Ԫ�أ��ȳ�ջ���ƶ�ָ��
	switch (i)
	{
	case 1:
		if (!IsEmpty(S, 1))
		{
			cout << S.V[S.top[1]] << " ";
			S.top[1]++;
		}
		break;
	case 0:
		if (!IsEmpty(S, 0))
		{
			cout << S.V[S.top[0]] << " ";
			S.top[0]--;
		}
		break;
	}
}
int main()
{
	DblStack S;
	int m, e0, e1, d0, d1;
	while (cin >> m)
	{
		if (m == 0) break;
		InitDblStack(S, m);
		cin >> e0 >> e1 >> d0 >> d1;
		while (e0--)
			Push(S, 0);
		while (e1--)
			Push(S, 1);
		cout << IsFull(S) << endl;
		while (d0--)
			Pop(S, 0);
		cout << !IsEmpty(S, 0) << endl;
		while (d1--) {
			Pop(S,1);
		}
		cout << !IsEmpty(S, 1) << endl;
	}
	return 0;
}