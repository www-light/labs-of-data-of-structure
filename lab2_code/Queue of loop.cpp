#include<iostream>
using namespace std;
typedef int Status;
typedef struct QNode
{//队列的链式存储结构
    int data;
    struct QNode* next;
}QNode, * QueuePtr;
typedef struct
{
    QueuePtr rear;    //只设一个队尾指针
}LinkQueue;
Status EmptyQueue(LinkQueue Q)
{//判断队列是否为空，空返回1，否则返回0
//队列只有一个头结点，即当头结点的指针域指向自己时，队列为空
	if (Q.rear->next == Q.rear)
	{
		return 1;
	}
	return 0;
}
void EnQueue(LinkQueue& Q, int e)
{//入队，插入元素e为Q的新的队尾元素
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	p->next = Q.rear->next;
	Q.rear->next = p;
	Q.rear = p;
}
void DeQueue(LinkQueue& Q)
{//出队，输出Q的队头元素值，后将其删除
	if (Q.rear->next == Q.rear)
	{
		return;
	}
	QNode* temp;
	temp = Q.rear->next->next;
	Q.rear->next->next = temp->next;
	if (temp == Q.rear)////当队列中只有一个结点时，p结点出队后，要将队尾指针指向头结点 
	{
		Q.rear = Q.rear->next;
	}
		cout << temp->data << " ";
		delete temp;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		LinkQueue Q;           //初始化一个带头结点的循环链表
		Q.rear = new QNode;
		Q.rear->next = Q.rear;
		while (n--)
		{//n个元素入队
			int e; cin >> e;
			EnQueue(Q, e);
		}
		while (m--)            //m个元素出队
			DeQueue(Q);
		if (EmptyQueue(Q))
			cout << "0" << endl;
		else
			cout << "1" << endl;
	}
	return 0;
}
