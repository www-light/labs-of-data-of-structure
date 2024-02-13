#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//后插法创建单链表
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
void DeleteMinMax(LinkList& L, int mink, int maxk)
{//删除链表中满足区间值的结点
    LinkList pre = new LNode;
    LinkList cur = new LNode;
    pre = L;
    cur = L->next;
    LinkList temp = new LNode;
    LinkList deleteNode = new LNode;
    if (L->next->data >= mink && L->next->data > maxk)
    {
        pre = L->next->next;
        cur = pre->next;
        free(L->next);
    }
    while (cur)
    {
        if (cur->data >= mink && cur->data <= maxk)
        {
            temp = pre;
            deleteNode = cur;
            pre->next = cur->next;
            pre = temp;
            delete deleteNode;
            cur = pre->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
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
        int mink, maxk;
        cin >> mink >> maxk;

        DeleteMinMax(L, mink, maxk);
        PrintList(L);
    }
    return 0;
}