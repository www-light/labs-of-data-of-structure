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

void Inverse(LinkList& L)
{//逆置带头结点的单链表L
    LinkList p = new LNode;
    p = L->next;
    L->next = NULL;
    LinkList q = new LNode;
    while (p)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}
void PrintList(LinkList& L)
{
    L = L->next;
    while (L) {
        if (L->next != NULL) cout << L->data << " ";
        else cout << L->data;
        L = L->next;
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
        Inverse(L);
        PrintList(L);
    }
    return 0;
}