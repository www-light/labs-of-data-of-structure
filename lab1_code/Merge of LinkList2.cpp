#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//��巨����������
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
void MergeList(LinkList& LA, LinkList& LB, LinkList& LC)
{//���������������ǵݼ��������еĺϲ�   �����LC
    LinkList pa = new LNode;
        pa=LA->next;
        LinkList pb = new LNode;
        pb=LB->next;
    LC = new LNode;
    LC = LA;
    LC->data = LA->data + LB->data;
    LinkList pc = new LNode;
    pc = LC;
    while (pa != NULL && pb != NULL)//ease the link of original linking of LA and LB
    {
        if (pa->data < pb->data)//choose pa 
        {

            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {

            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    if (pa != NULL)
    {
        pc->next = pa;
    }
    if (pb != NULL)
    {
        pc->next = pb;
    }
    delete LB;
    LinkList pre = new LNode;
    pre = LA->next;
    LinkList cur = new LNode;
    for (int i = 0; i < LA->data - 1; i++)
    {
        pre = LA->next;//ÿ�δ���Ԫ�ڵ㿪ʼ
        for (int j = 0; j < LA->data- 1 - i; j++)
        {
            cur = pre->next;
            if (pre->data < cur->data)
            {
                int  temp = pre->data;
                pre->data = cur->data;
                cur->data = temp;
            }
            pre = pre->next;
        }
    }
}
void PrintList(LinkList& L)
{//��ӡ������������е�����
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
        LinkList LA, LB, LC;
        CreateList_R(LA, n);
        CreateList_R(LB, m);
        MergeList(LA, LB, LC);
        PrintList(LC);
    }
    return 0;
}