#include <iostream>p.
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
void MergeList(LinkList& LA, LinkList& LB)
{//求基于链表的两个递增有序序列的合并    存入LA
    LinkList LC = new LNode;
    LC->data = LA->data + LB->data;
    LC->next = NULL;
    LC = LA;
    LinkList pA =new LNode;
    pA = LA->next;
    LinkList pB = new LNode;
    pB = LB->next;
    LinkList pC = new LNode;
    pC = LC;
    while (pA != NULL && pB != NULL)//ease the link of original linking of LA and LB
    {
        if (pA->data < pB->data)//choose pA 
        {
            
                pC->next = pA;
                pC = pA;
                pA = pA->next;
        }
        else if(pA->data > pB->data)
        {
   
            pC->next = pB;
            pC = pB;
            pB= pB->next;
        }
        else {
            pA = pA->next;
            continue;
        }
   }
    if (pA!= NULL)
    {
        pC->next = pA;
    }
    if (pB != NULL)
    {
        pC->next = pB;
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
        MergeList(LA, LB);
        PrintList(LA);
    }
    return 0;
}