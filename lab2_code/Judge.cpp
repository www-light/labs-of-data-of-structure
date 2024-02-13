#include <iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct
{
    char* base;
    char* top;
    int stacksize;
}SqStack;
Status InitStack(SqStack& S)
{//��ʼ��ջ
    S.base = new char[MAXSIZE];
    S.stacksize = MAXSIZE;
    S.top = S.base;
    return OK;
}
Status Push(SqStack& S)
{//��ջ
    if (S.top - S.base != MAXSIZE)
    {
        *S.top = 1;
        S.top++;
        return OK;
    }
    return ERROR;
}
Status Pop(SqStack& S)
{//��ջ
    --S.top;
    return OK;
}
Status IsEmpty(SqStack S)
{//�ж�ջ�Ƿ�Ϊ�գ��շ���1�����򷵻�0
    if (S.top == S.base)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool Judge(char a[], SqStack& S)
{//ջ�Ŀɲ����ж�
    char* p = a;
    int len = 0;
    while (*p != '\0')
    {
        len++;
        p++;
    }
    for (int i = 0; i < len; i++)
    {
        if (a[i] == 'I')
        {
            Push(S);
        }
        else if (a[i] == 'O')
        {
            if (!IsEmpty(S))
            {
                Pop(S);
            }
            else
            {
                return false;
            }
        }
    }
    if (IsEmpty(S))
    {
        return true;
    }
    return false;
}
int main()
{
    char a[100];
    while (cin >> a)
    {
        if (a[0] == '0') break;
        SqStack op;
        InitStack(op);
        if (Judge(a, op)) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;
    }
    return 0;
}