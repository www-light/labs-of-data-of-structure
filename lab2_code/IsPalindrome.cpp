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
{//栈初始化
	S.base = new char[MAXSIZE];
	S.stacksize = MAXSIZE;
	S.top = S.base;
	return OK;
}
Status Push(SqStack& S, char e)
{//入栈
	if (S.top - S.base != MAXSIZE)
	{
		*S.top = e;
		S.top++;
		return OK;
	}
	return ERROR;
}
Status Pop(SqStack& S)
{//出栈返回栈顶元素
	--S.top;
	return OK;
}
char Gettop(SqStack S)
{
	if (S.top != S.base)
	{
		return *(S.top - 1);
	}
}
Status IsPalindrome(SqStack& S, char* t)
{//判断栈的回文字符序列，不等则返回零, 相等则返回1
	char* p = t;
	int len = 0;
	int flag = 0;
	while (*p!='\0')
	{
		len++;
		p++;
	}
	char* Palindrome = new char[len];
	for (int i = 0; i < len; i++)
	{
		Push(S, t[i]);
	}
	for (int i = 0; i < len; i++)
	{
		if (Gettop(S) != t[i])
		{
			flag = 1;
			break;
		}
		Pop(S);
	}
	if (flag == 1)
	{
		return 0;
	}
	return 1;
}
int main()
{
	char t[100];
	while (cin >> t && t[0] != '0')
	{
		SqStack S;
		InitStack(S);
		if (IsPalindrome(S, t) == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}