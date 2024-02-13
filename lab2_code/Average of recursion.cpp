#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
//���ȣ�������Ҫ��ȷһ�µݹ麯���Ķ��塣�ڵݹ麯���У�
// ���ǽ������Ϊ�����֣���ǰ�ڵ��ʣ��ڵ㡣
// ����ͨ���ݹ����������ʣ��ڵ��ƽ��ֵ��������洢�ڱ���avg�С�
//��������������Ҫ���㵱ǰ�ڵ��ƽ��ֵ��
// ��ǰ�ڵ��ֵΪsum������ǰ�ڵ�ļ���Ϊ1��
// ���ǽ���ǰ�ڵ��ֵ�ӵ�ʣ��ڵ��ƽ��ֵ�ϣ�����������1��
// ���������Ǿ͵õ��˵�ǰ�ڵ��ʣ��ڵ���ܺ��Լ��ܼ�����
//Ϊ�˼��㵱ǰ�ڵ��ƽ��ֵ������ʹ�ù�ʽ(avg* (n - 1) + sum) / n��
// �����ʽ�ĺ����ǣ���ʣ��ڵ��ƽ��ֵ����ʣ��ڵ�ļ���(n - 1)��Ȼ����ϵ�ǰ�ڵ��ֵsum���������ܼ���n��
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
double GetAverage(LinkList L, int n)
{//�ݹ���ⵥ�����е�ƽ��ֵ
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
        L = L->next;//Lָ����Ԫ���
        printf("%.2f\n", GetAverage(L, n));//���������λС��
    }
    return 0;
}