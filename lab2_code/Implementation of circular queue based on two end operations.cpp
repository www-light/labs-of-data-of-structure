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
{//构造一个空队列Q

	return OK;
}
Status EnQueue(SqQueue& Q, int e)
{//在Q的队头插入新元素e

	return OK;
}
Status DeQueue(SqQueue& Q)
{//删除Q的队尾元素，用e返回其值

}
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		SqQueue Q;
		InitQueue(Q);          //初始化循环队列
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