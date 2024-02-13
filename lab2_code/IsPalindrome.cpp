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
{//ջ��ʼ��
	S.base = new char[MAXSIZE];
	S.stacksize = MAXSIZE;
	S.top = S.base;
	return OK;
}
Status Push(SqStack& S, char e)
{//��ջ
	if (S.top - S.base != MAXSIZE)
	{
		*S.top = e;
		S.top++;
		return OK;
	}
	return ERROR;
}
Status Pop(SqStack& S)
{//��ջ����ջ��Ԫ��
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
{//�ж�ջ�Ļ����ַ����У������򷵻���, ����򷵻�1
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