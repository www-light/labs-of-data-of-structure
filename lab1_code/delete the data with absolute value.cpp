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
void DeleteEqualNode(LinkList& L, int n)
{//删除链表中绝对值相等的结点
    LinkList newllist = new LNode;
    LinkList p1 = new LNode;
    newllist->next = NULL;
    LinkList p = new LNode;
    p = L;
    int flag = 0;
    LinkList tail = new LNode;
    tail->next = NULL;
    tail = newllist;
    while (p->next)
    {
        p1 = newllist;
        p = p->next;
        flag = 0;
        while (p1->next)
        {
            p1 = p1->next;
            if (p1 != NULL && p->data*p->data == p1->data*p1->data)
            {
                flag = 1;
                
                break;
            }
        }
        if (flag == 0)
        {
            LinkList one = new LNode;
            one->next = NULL;
            one->data = p->data;
            tail->next = one;
            tail = one;
        }
    }
    p1 = newllist;
    while (p1)
    {
        p1 = p1->next;
        if (p1->next->data == 0)
        {
            p1->next = p1->next->next;
        }
    }
    L = newllist;
}
void PrintList(LinkList& L)
{//打印依次输出链表中的数据
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
        LinkList L;
        CreateList_R(L, n);
        DeleteEqualNode(L, n);
        PrintList(L);
    }
    return 0;
}