#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 0
#define OVERFLOW -1
#define ERROR -2
typedef int Status;
typedef struct
{
	int* base;
	int front, rear, tag;
}SqQueue;
Status InitQueue(SqQueue& Q)
{//构造一个空队列Q
	Q.base = new int[MAXSIZE];
	if (!Q.base) {
		return ERROR;
	}
	Q.front = Q.rear = 0;
	return OK;
}
Status EnQueue(SqQueue& Q, int e)
{//插入元素e为Q的新的队尾元素
	Q.front = (Q.front - 1 + MAXSIZE) % MAXSIZE;
	Q.base[Q.front] = e;
	return OK;
}
Status DeQueue(SqQueue& Q)
{//删除Q的队头元素，用e返回其值
	Q.rear = (Q.rear - 1 + MAXSIZE) % MAXSIZE;
	int e = Q.base[Q.rear];
	return e;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		SqQueue Q;
		InitQueue(Q);             //初始化循环队列
		for (int i = 0; i < n; i++)
		{//n个元素入队
			int x; cin >> x;
			EnQueue(Q, x);
		}
		for (int i = 0; i < n - 1; i++)
			cout << DeQueue(Q) << " ";
		cout << DeQueue(Q) << endl;
	}
	return 0;
}