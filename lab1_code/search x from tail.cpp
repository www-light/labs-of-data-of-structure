#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
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
void Search_k(LinkList L, int k)
{
    // 直接输出结果
    int i = 0;
    LinkList p = L;
    while (i <= L->data - k)
    {
        if (i == L->data - k)
        {
            cout << p->next->data<<endl;
        }
        p = p->next;
        i++;
    }
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        LinkList L;
        CreateList_R(L, n);
        int k;
        cin >> k;
        Search_k(L, k);
    }
    return 0;
}
