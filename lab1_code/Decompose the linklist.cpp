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
void Decompose(LinkList& LA, LinkList& LB, LinkList& LC)
{//链表的分解    LA->LB、LC
    LinkList pa = new LNode;
    pa = LA->next;
    //save the the data that is greater than 0;
    LB = new LNode;
    LinkList pb = new LNode;
    LB->next = NULL;
    pb = LB;
    //save the the data that is lower than 0;
    LC = new LNode;
    LinkList pc = new LNode;
    LC->next = NULL;
    pc = LC;
    while(pa != NULL && pb != NULL)
    {
        if (pa->data > 0)
        {
            pb->next = pa;
            pb = pa;
            pa = pa->next;
        }
        else {
            pc->next = pa;
            pc = pa;
            pa= pa->next;
        }
    }
    pb->next = NULL;
    pc->next = NULL;
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
        LinkList LA, LB, LC;
        CreateList_R(LA, n);
        Decompose(LA, LB, LC);
        PrintList(LB);
        PrintList(LC);
    }
    return 0;
}