#include<iostream>
using namespace std;
#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
	char* base;
	char* top;
	int stacksize;
}SqStack;
//output
//931 - 3 * +12 / +
//12 +
Status InitStack(SqStack& S)
{//初始化栈
	S.base = new char[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, char e)
{//入栈
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top = e;
	S.top++;
	return OK;
}
Status Pop(SqStack& S)
{//出栈
	if (S.top == S.base)
		return ERROR;
	--S.top;
	return OK;
}
char GetTop(SqStack S)
{//取栈顶元素
	if (S.top == S.base)
		return ERROR;

		return *(S.top-1);
}
char Precede(char a, char b)
{//比较运算符a和b的优先级
	if ((a == '(' && b == ')')||a==b)
		return '=';
	else if (a == '(' || a == '=' || b == '(' || (a == '+' || a == '-') && (b == '*' || b == '/'))
		return '<';
	else
		return '>';
}
void InfixToSuffix(SqStack OPTR, char s[])
{//将中缀表达式转化为后缀表达式并输出 
	char c;
	int len = 0;
	int len1 = strlen(s);
	
	int i = 0;
	int j = 0;
	while(s[i]!='\0')
	{
		if (s[i] != '('&& s[i] != ')'&& s[i] != '=')
		{
			len++;
		}
		i++;
	}
	char Exp[MAXSIZE];
	char ch='0';
	for (int i = 0; i < len1; i++)
	{
		c = s[i];
		if (isdigit(c))// handle the number
		{
				Exp[j] = c;
				j++;
			
		}else if (c != '='||  GetTop(OPTR) != '=')//handle the operation
		{
			switch (c)
			{
			case')':
				while (GetTop(OPTR) != '(')
				{
						Exp[j] = GetTop(OPTR);
						j++;
					Pop(OPTR);
				}
				Pop(OPTR);
				break;
			case'(':
				Push(OPTR, c);
				break;
			default:
					switch (Precede(GetTop(OPTR), c))
					{
					case '<'://c > the top of OPTR
						Push(OPTR, c);
						break;
					default:
						while (GetTop(OPTR) != '='&& (Precede(GetTop(OPTR), c)=='>'|| Precede(GetTop(OPTR), c) == '='))
						{
							Exp[j] = GetTop(OPTR);
							j++;
							Pop(OPTR);
						}
						Push(OPTR, c);
						break;
					}
			}
		}
	}

	while (OPTR.base != OPTR.top)
	{
		ch = GetTop(OPTR);
		if (ch != '(')
		{
			Exp[j] = ch;
			j++;
		}
		Pop(OPTR);
	}
	for (int i = 0; i < len; i++)
	{
		if(Exp[i]!='=')
		cout << Exp[i];
	}
	cout << endl;
}
int main()
{
	SqStack OPTR;
	InitStack(OPTR);      //初始化操作符栈OPTR
	Push(OPTR, '=');		//先在栈底放入'='便于以后比较符号优先级	
	char s[100];
	while (cin >> s)
	{
		if (s[0] == '=')
			break;    	//当表达式只有一个“=”时，输入结束 
		else
			InfixToSuffix(OPTR, s); 	//将中缀表达式转化为后缀表达式并输出	
	}
	return 0;
}