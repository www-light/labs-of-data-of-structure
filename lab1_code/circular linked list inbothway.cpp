#include<iostream>
using namespace std;
typedef struct DuLNode
{
	int data;
	struct DuLNode* next;
	struct DuLNode* prior;
}DuLNode, * DuLinkList;
void CreateList(DuLinkList& L, int n)
{//建立双向循环链表
	L = new DuLNode;
	L->next = NULL;
	int i = 1;
	DuLinkList tail = new DuLNode;
	tail = L;
	L->prior = NULL;
	L->next = NULL;
	while (i <= n)
	{   
		DuLinkList one = new DuLNode;
		cin >> one->data;
		tail->next = one;
		one->prior = tail;
		one->next = NULL;
		tail = one;
		i++;
	}
}
void Exchange(DuLinkList& L, int loc)
{//双向循环链表中结点的交换
	int i = 0;
	DuLinkList p=new DuLNode;
	p = L;
	while (i < loc-1)
	{
		if (p != NULL)
		{
			p = p->next;
			i++;
	}
	}
	//swap the node of  front and rear point 
	int temp = p->data;
	p->data = p->next->data;
	p->next->data = temp;
}
void PrintList(DuLinkList& L)
{//依次输出链表中的数据
	DuLinkList p = L->next;
	while (p->next && p->next != L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		DuLinkList L;
		CreateList(L, n);
		int loc;
		cin >> loc;
		if (n == 1)          //链表仅有一个元素时输出其自身
		{
			cout << L->next->data << endl;
			continue;
		}
		Exchange(L, loc);
		PrintList(L);
	}
	return 0;
}
