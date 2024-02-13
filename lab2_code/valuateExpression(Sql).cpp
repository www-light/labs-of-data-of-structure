#include <iostream>
#include<iomanip>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct
{//�����ջ
	char* base;
	char* top;
	int stacksize;
}SqStack1;
Status InitStack1(SqStack1& S)
{//�����ջ��ʼ��
	S.base = new char[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push1(SqStack1& S, char e)
{//�����ջ��ջ
	if (S.top - S.base != MAXSIZE)
	{
		*S.top = e;
		S.top++;
		return OK;
	}
	return ERROR;
}
Status Pop1(SqStack1& S)
{//�����ջ��ջ
	if (S.top != S.base)
	{
		--S.top;
		return OK;
	}
	return ERROR;
}
char GetTop1(SqStack1 S)
{//�����ջȡջ��Ԫ��
	if (S.top != S.base)
	{
		return *(S.top-1);
	}
	return ERROR;
}
typedef struct
{//������ջ
	double* base;
	double* top;
	int  stacksize;
}SqStack2;
Status InitStack2(SqStack2& S)
{//������ջ��ʼ��
	S.base = new double[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push2(SqStack2& S, double e)
{//������ջ��ջ
	if (S.top - S.base != MAXSIZE)
	{
		*S.top = e;
		S.top++;
		return OK;
	}
	return ERROR;
}
Status Pop2(SqStack2& S)
{//������ջ��ջ
	if (S.top != S.base)
	{
		--S.top;
		
		return OK;
	}
	return ERROR;
}
double GetTop2(SqStack2 S)
{//������ջȡջ��Ԫ��
	if (S.top != S.base)
	{
		return *(S.top - 1);
	}
	return ERROR;
}
double Calculate(double a, char op, double b)
{//������ʽ��a op b����ֵ
	if (op == '-')
	{
		return a - b;
	}
	else if (op == '+')
	{
		return a + b;
	}
	else if (op == '*')
	{
		return a * b;
	}
	else if (op == '/')
	{
		return a / b;
	}
	return ERROR;
}

char Precede(char a, char b)
{//�Ƚ������a��b�����ȼ�
	if ((a == '(' && b == ')')||((a=='=')&&(b=='='))
		return '=';
	else if (a == '(' || a == '=' || b == '(' || (a == '+' || a == '-') && (b == '*' || b == '/'||b=='(')||(a=='*'||a=='/')&&(b=='('))
		return '<';
	else
		return '>';
}
bool isdigit(char ch) {//disgtinguish '.' and other operation
	if ((ch >= '0' && ch <= '9') || ch == '.') {
		return true;
	}
	else return false;
}
double EvaluateExpression(SqStack1 OPTR, SqStack2 OPND, char s[])
{//�������ʽ��ֵ����������㷨
 //��OPTR��OPND�ֱ�Ϊ�����ջ�Ͳ�����ջ
 //���ʽ��ֵ�㷨����Precede������Calculate���� 
	int len = strlen(s);
	char c;
	double a1,a2;
	char ch;
	for(int i=0;i<len;i++)
	{
		c = s[i];//save every char
		if (isdigit(c)) {
			double num = c - '0';
			double multiple = 0;
			bool flag = 0;
			while (i + 1 < len && isdigit(s[i + 1])) {
			
				if (s[i + 1] == '.') {
					multiple = 0.1;
					flag = 1;
				}
				else {// handle the number
					if (flag) {//decimals
						num += multiple * (s[i + 1] - '0');
						multiple *= 0.1;
					}
					else {//integer
						num = num * 10 + (s[i + 1] - '0');
					}
				}
				i++;
			}
			
				Push2(OPND, num);//when the ending of the operation of the whole part of number
		} 
		else if(c!='='||GetTop1(OPTR)!='=')
		{
			switch (Precede(GetTop1(OPTR), c))
			{
			case'<':
				Push1(OPTR, c);
				break;
			case'>':
				ch = GetTop1(OPTR);
				a1 = GetTop2(OPND);
				Pop1(OPTR);
				Pop2(OPND);
				a2 = GetTop2(OPND);
				Pop2(OPND);
				Push2(OPND, Calculate(a2, ch, a1));
				i--;
				break;
			case'=':
				Pop1(OPTR);
				break;
			}
		}
	}
	return GetTop2(OPND);
}
int main()
{//��OPTR��OPND�ֱ�Ϊ�����ջ�Ͳ�����ջ
	SqStack1 OPTR;
	InitStack1(OPTR);    //��ʼ��OPNDջ
	SqStack2 OPND;
	InitStack2(OPND);    //��ʼ��OPTRջ
	Push1(OPTR, '=');     //��ǰ��OPTRջ�з���'='�������Ժ�ȽϷ������ȼ�        
	char s[100];
	while (cin >> s)
	{//ѭ�������������	



		if (s[0] == '=')
			break;    //�����ʽֻ��һ����=��ʱ��������� 
		//�����׺�������ʽ��ֵ
		cout << fixed << setprecision(2) << EvaluateExpression(OPTR, OPND, s) << endl;
	}
	return 0;
}
