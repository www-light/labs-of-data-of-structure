#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
//ps: this is a gradual-increase sequence
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
void Difference(LinkList& LA, LinkList& LB)
{//求基于链表的两个集合的差集
    LinkList LC = new LNode;
    LC->data = LA->data + LB->data;
    LC->next = NULL;
    LC = LA;
    LinkList pa = new LNode;
    pa = LA->next;
    LinkList pb = new LNode;
    pb = LB->next;
    LinkList pc = new LNode;
    pc = LC;
    while (pa != NULL && pb != NULL)//ease the link of original linking of LA and LB
    {
        if (pa->data == pb->data)//choose pa 
        {

            pa = pa->next;
            pb = pb->next;
            
        }
        else if(pa->data < pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else {
            pb = pb->next;
        }
    }
    if (pa != NULL)
    {
        pc->next = pa;
    }else if (pb != NULL)//if pb！=NULL,quit the rest of LB
    {
        pc->next = NULL;
    }
    else
    {
        pc->next = NULL;
    }
    
    delete LB;
}
void PrintList(LinkList& L)
{//依次输出链表中的数据和该集合的元素个数
    L = L->next;
    int s = 0;
    while (L)
    {
        if (L->next != NULL) cout << L->data << " ";
        else cout << L->data;
        L = L->next;
        s++;
    }
    cout << endl << s << endl;
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        LinkList LA, LB;
        CreateList_R(LA, n);
        CreateList_R(LB, m);
        Difference(LA, LB);
        PrintList(LA);
    }
    return 0;
}
