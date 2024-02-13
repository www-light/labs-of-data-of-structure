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
    L->data = n;
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
void Intersection(LinkList& LA, LinkList& LB)
{//求基于链表的两个集合的交集    结果存LA
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

            pc->next = pa;
            pc = pa;
            pa = pa->next;
            pb = pb->next;
            if (pa == NULL || pb == NULL)//judge if the ending of linklist
            {
                pc->next = NULL;
                break;
            }
        }
        else if (pa->data > pb->data)
        {
            pb = pb->next;
        }
        else
        {
            pa = pa->next;
        }
    }
    delete LB;
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
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        LinkList LA, LB;
        CreateList_R(LA, n);
        CreateList_R(LB, m);





        Intersection(LA, LB);
        PrintList(LA);
    }
    return 0;
}