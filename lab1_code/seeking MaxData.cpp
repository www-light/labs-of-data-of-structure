#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;

void CreateList_R(LinkList& L, int n)
{
    // 尾插法
    int i = 1;
    LinkList tail = new LNode;
    tail->next = NULL;
    L = new LNode;//initlize the headNode
    L->next = NULL;
    tail = L;//mark the tail
    L->data = n;
    while (i <= n)//adding the New Node to the tail
    {
        int temp;
        cin >> temp;
        LinkList p = new LNode;
        p->data = temp;
        p->next = NULL;
        tail->next = p;
        tail = p;
        i++;
    }
}

int MaxData(LinkList L)
{//确定单链表中值最大的结点
    int max = 0;
    LinkList p = new LNode;
    p = L->next;
    max = p->data;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        LinkList L = new LNode;
        CreateList_R(L, n);
        cout << MaxData(L) << endl;
    }
    return 0;
}