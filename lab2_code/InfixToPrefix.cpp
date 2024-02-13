#include<iostream>
using namespace std;
#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
//pro
//���������ղ���λ
typedef struct
{
	char* base;
	char* top;
	int stacksize;
}SqStack;
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

	return *(S.top - 1);
}
char Precede(char a, char b)
{//�Ƚ������a��b�����ȼ�
	if ((a == '(' && b == ')') || a == b || (a == '+' && b == '-') || (a == '-' && b == '+'))//judge '='
		return '=';
	else if (a == '(' || a == '=' || b == '(' || (a == '+' || a == '-') && (b == '*' || b == '/'))
		return '<';
	else
		return '>';
}
void InfixToPrefix(SqStack OPTR, char s[])
{//����׺���ʽת��Ϊǰ׺���ʽ����� 
	int len = 0;//the length of prefix
	char* p;
	p = s;
	int len1 = strlen(s);//the length of infix
	while (*p != '\0')//calculate the length of suffix
	{
		if (*p != '=' && *p != '(' && *p != ')')
		{
			len++  ;
		}
		if (*p == '(')//replace '('and')'
		{
			*p = ')';
		}else if (*p == ')')
		{
			*p = '(';
		}
		p++;
	}
	char* s1 = new char[len1];//the expression after reversion
	int j = 0;
	for (int i = len1-2;i >=0; i--,j++)//reverse the expression
	{
		s1[j] = s[i];
	}
	s1[j] = '=';//the ending sign of expression
	s1[j + 1] = '\0';
	char Exp[MAXSIZE];
	char c = '0';
	j = 0;//reset 
	for (int i = 0; i < len1; i++)
	{
		c = s1[i];
		if (isdigit(c))
		{
			Exp[j] = s1[i];
			j++;
		}
		else if (c != '=' || GetTop(OPTR) != '=')
		{
			switch (c)
			{
			case'(':
				Push(OPTR, c);
				break;
			case')':
				while (GetTop(OPTR) != '(')
				{
					Exp[j] = GetTop(OPTR);
					j++;
					Pop(OPTR);
				}
				Pop(OPTR);
				break;
			default:
				switch (Precede(GetTop(OPTR), c))
				{
				case '<':
					Push(OPTR, c);
					break;
				default:
					while (GetTop(OPTR)!='='&&Precede(GetTop(OPTR),c)=='>')//С�ڲų�ջ
					{
						Exp[j] = GetTop(OPTR);
						j++;
						Pop(OPTR);
					}
					Push(OPTR,c);
					break;
				}
			}
		}
}
	char ch = '0';
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
	for (int i = len; i >=0; i--)
	{
		if (Exp[i] != '=')
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
			InfixToPrefix(OPTR, s); 	//����׺���ʽת��Ϊǰ׺���ʽ�����	
	}
	return 0;
}