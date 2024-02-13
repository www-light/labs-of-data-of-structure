#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
//5
//1 2 3 4 5
//3
//1 5 6
//4
//15 2 3 4
//0
void CreateList_R(LinkList& L, int n)
{//后插法创建单链表
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
void Decollate(LinkList& L, LinkList& L1)
{//奇偶链表的分割
    LinkList p = L->next;
    LinkList p1 = new LNode;
    p1 = L;
    LinkList p2 = new LNode;
    p2 = L1;
    int i = 1;
    while (p)
    {
        if (i % 2 == 1)
        {
            p2->next = p;
            p2 = p2->next;
            p1->next = p->next;
            p->next = NULL;
            p = p1->next;
        }
        else
        {
            p1 = p1->next;
            p = p->next;
        }
        i++;
    }
    p2->next = L->next;
    delete L;
}
void PrintList(LinkList L)
{//依次输出链表中的数据
    LinkList p = L->next;
    while (p)
    {
        if (p->next != NULL) cout << p->data << " ";
        else cout << p->data;
        p = p->next;
    }
    cout << endl;
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        LinkList L = new LNode;
        CreateList_R(L, n);
        LinkList L1 = new LNode;    //申请新链表L1
        L1->next = NULL;
        Decollate(L, L1);      //奇偶链表的分割
        PrintList(L1);
    }
    return 0;
}
