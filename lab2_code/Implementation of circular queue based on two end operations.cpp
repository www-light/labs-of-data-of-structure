#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
	int* base;
	int front;
	int rear;
}SqQueue;
Status InitQueue(SqQueue& Q)
{//����һ���ն���Q

	return OK;
}
Status EnQueue(SqQueue& Q, int e)
{//��Q�Ķ�ͷ������Ԫ��e

	return OK;
}
Status DeQueue(SqQueue& Q)
{//ɾ��Q�Ķ�βԪ�أ���e������ֵ

}
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		SqQueue Q;
		InitQueue(Q);          //��ʼ��ѭ������
		for (int i = 0; i < n; i++)
		{//n��Ԫ�����
			int x; cin >> x;
			EnQueue(Q, x);
		}
		for (int i = 0; i < n - 1; i++)
			cout << DeQueue(Q) << " ";
		cout << DeQueue(Q) << endl;
	}
	return 0;
}