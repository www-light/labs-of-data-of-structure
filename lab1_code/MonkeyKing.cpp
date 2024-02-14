#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateCirList(LinkList& L, int m)
{//后插法创建单向循环链表
    int i = 1;
    LinkList tail = new LNode;
    tail->next = NULL;
    L = new LNode;
    L->next = NULL;
    while (i <= m)//adding the New Node to the tail
    {
        if (i == 1)
        {
            L->data = i;
            tail = L;
        }
        else
        {
            LinkList p = new LNode;
            p->data = i;
            p->next = NULL;
            tail->next = p;
            tail = p;
        }
        i++;
    }
    tail->next = L;
}
void MonkeyKing(LinkList& L, int n)
{//猴子选大王（约瑟夫问题）     直接输出结果
    LinkList p = new LNode;
    LinkList temp = new LNode;
    p = L->next;
    int i = 1;
    int num = 1;
    while (p != L)
    {
        p = p->next;
        num++;
    }
    p = L;
    while (num > 0)
    {
        if ((i + 1) % n == 0)
        {
            temp = p;//save the front node before the node that conforms the condition
        }
        if (i % n == 0)//conform the condition,leave the circle
        {
            if (num != 1)
            {
                cout << p->data << " ";
            }
            else {
                cout << p->data;
            }
            temp->next = p->next;
            num--;
        }
        i++;
        p = p->next;
    }
    cout << endl;
    delete p;
}
int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        if (n == 0 && m == 0) break;
        LinkList L;
        CreateCirList(L, m);
        MonkeyKing(L, n);
    }
    return 0;
}