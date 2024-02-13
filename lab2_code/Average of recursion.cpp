#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
//首先，我们需要明确一下递归函数的定义。在递归函数中，
// 我们将链表分为两部分：当前节点和剩余节点。
// 我们通过递归调用来计算剩余节点的平均值，并将其存储在变量avg中。
//接下来，我们需要计算当前节点的平均值。
// 当前节点的值为sum，而当前节点的计数为1。
// 我们将当前节点的值加到剩余节点的平均值上，并将计数加1。
// 这样，我们就得到了当前节点和剩余节点的总和以及总计数。
//为了计算当前节点的平均值，我们使用公式(avg* (n - 1) + sum) / n。
// 这个公式的含义是：将剩余节点的平均值乘以剩余节点的计数(n - 1)，然后加上当前节点的值sum，最后除以总计数n。
void CreateList_R(LinkList& L, int n)
{//后插法创建单链表
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
double GetAverage(LinkList L, int n)
{//递归求解单链表中的平均值
    if (L == NULL)
    {
        return 0.0;
    }
    double avg = GetAverage(L->next, n - 1);

    double sum = L->data;
    return (avg * (n - 1) + sum) / n;
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        LinkList L;
        CreateList_R(L, n);
        L = L->next;//L指向首元结点
        printf("%.2f\n", GetAverage(L, n));//输出保留两位小数
    }
    return 0;
}