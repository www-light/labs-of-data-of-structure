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
{//��ʼ��ջ
	S.base = new char[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, char e)
{//��ջ
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top = e;
	S.top++;
	return OK;
}
Status Pop(SqStack& S)
{//��ջ
	if (S.top == S.base)
		return ERROR;
	--S.top;
	return OK;
}
char GetTop(SqStack S)
{//ȡջ��Ԫ��
	if (S.top == S.base)
		return ERROR;

		return *(S.top-1);
}
char Precede(char a, char b)
{//�Ƚ������a��b�����ȼ�
	if ((a == '(' && b == ')')||a==b)
		return '=';
	else if (a == '(' || a == '=' || b == '(' || (a == '+' || a == '-') && (b == '*' || b == '/'))
		return '<';
	else
		return '>';
}
void InfixToSuffix(SqStack OPTR, char s[])
{//����׺���ʽת��Ϊ��׺���ʽ����� 
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
	InitStack(OPTR);      //��ʼ��������ջOPTR
	Push(OPTR, '=');		//����ջ�׷���'='�����Ժ�ȽϷ������ȼ�	
	char s[100];
	while (cin >> s)
	{
		if (s[0] == '=')
			break;    	//�����ʽֻ��һ����=��ʱ��������� 
		else
			InfixToSuffix(OPTR, s); 	//����׺���ʽת��Ϊ��׺���ʽ�����	
	}
	return 0;
}