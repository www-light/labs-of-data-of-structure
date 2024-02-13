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
{//初始化栈
    S.base = new char[MAXSIZE];
    S.stacksize = MAXSIZE;
    S.top = S.base;
    return OK;
}
Status Push(SqStack& S)
{//入栈
    if (S.top - S.base != MAXSIZE)
    {
        *S.top = 1;
        S.top++;
        return OK;
    }
    return ERROR;
}
Status Pop(SqStack& S)
{//出栈
    --S.top;
    return OK;
}
Status IsEmpty(SqStack S)
{//判断栈是否为空，空返回1，否则返回0
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
{//栈的可操作判断
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