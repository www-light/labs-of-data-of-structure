#include <iostream>
using namespace std;
typedef struct LNode
{
    char data;
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
        char temp;
        cin >> temp;
        LinkList p = new LNode;
        p->data = temp;
        p->next = NULL;
        tail->next = p;
        tail = p;
        i++;
    }
}
void FindSuffix(LinkList str1, LinkList str2, int n, int m)
{//查找两个单词链表共同后缀的起始结点    直接输出字母
    char *str3 = new char[n];
    char *str4 = new char[m];
    LinkList p = new LNode;
    p = str1->next;
    int i = 0;
    //transform linklist to array
    while (p)
    {
        str3[i] = p->data;
        p = p->next;
        i++;
    }
    i = 0;
    p = str2->next;
    while (p)
    {
        str4[i] = p->data;
        p = p->next;
        i++;
    }
    for (int i = n-1, j = m-1; i >= 0, j >= 0; i--, j--)//finding the last common character
    {
        if (str3[i] != str4[j])
        {
            cout << str3[i + 1] << endl;
            break;
        }
    }
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        LinkList str1, str2, p;
        CreateList_R(str1, n);
        CreateList_R(str2, m);
        FindSuffix(str1, str2, n, m);
    }
    return 0;
}
