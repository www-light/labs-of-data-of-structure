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
    L = new LNode;
    L->data = n;
    LinkList tail = L;
    tail->next = NULL;
    while (i <= n)
    {
        int  temp;
        cin >> temp;
        LinkList p = new LNode;
        p->data = temp;
        p->next = NULL;
        tail->next = p;
        tail->next = p;
        tail = p;
        i++;
    }
}
int GetLength(LinkList L)
{//�ݹ���ⵥ�����еĽ�����
    int i = 1;
    if (L->next == NULL)
    {
        return 1;
    }
    else
    {
        return GetLength(L->next)+1;
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
        L = L->next;    //Lָ����Ԫ���
        cout << GetLength(L) << endl;
    }
    return 0;
}