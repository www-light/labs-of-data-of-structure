#include <iostream>
#include<iomanip>
#include <string>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct
{//������ջ
	double* base;
	double* top;
	int  stacksize;
}SqStack;
Status InitStack(SqStack& S)
{//������ջ��ʼ��
	S.base = new double[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, double e)
{//������ջ��ջ
	if (S.top - S.base != MAXSIZE)
	{
		*S.top = e;
		S.top++;
		return OK;
	}
	return ERROR;
}
Status Pop(SqStack& S)
{//������ջ��ջ
	if (S.top != S.base)
	{
		--S.top;
		return OK;
	}
	return ERROR;
}
double GetTop(SqStack S)
{//������ջȡջ��Ԫ��
	if (S.top != S.base)
	{
		return *(S.top - 1);
	}
	return ERROR;	//��������ջ��Ԫ���򷵻�ERROR
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
//++9.1 *-3.3 1.1 3.5/1 2.3=
double EvaluateExpression(SqStack OPND, char s[])
{//ǰ׺�������ʽ��ֵ
 //��OPNDΪ������ջ
 //���ʽ��ֵ�㷨����Calculate���� 
	char* p = s;
	int len = 0;
	while (*p != '\0')
	{
		len++;
		p++;
	}
	char ch = '0';
	double sum = 0.0;
	for (int i = len-2;i >=0; i--)
	{
		ch = s[i];
		if (isdigit(ch) || s[i] == '.')//judge if it is figure
		{
			double num=0;
			double num1 = 0;
				int flag=0;
				i++;
				while (i - 1 >= 0 && (isdigit(s[i - 1]) || s[i - 1] == '.'))//handle the whole part
				{
					if (s[i - 1] == '.')
					{
						flag = 1;
					}
					//first handle decimal and
					else if (flag==0)//handle the decimal
					{
						num = num * 0.1 + (s[i - 1] - '0') * 0.1;
					}
					else if (flag==1) {//handle the integer
						num1 = num1 * 10 + (s[i - 1] - '0');
					}
					i--;
				}
				num += num1;
				//if next part is without point 
				if (!flag) num *= 10;
				Push(OPND, num);
		}
			else if (ch =='+'|| ch == '-' || ch == '*' || ch == '/' )
			{
				double a = GetTop(OPND);
				Pop(OPND);
				double b = GetTop(OPND);
				Pop(OPND);
				Push(OPND, Calculate(a, ch, b));
			}
	}
	return GetTop(OPND);
}
int main()
{
	char s[100];
	//���ַ�����洢���ʽ��ÿ������Ԫ�ؽ���һ���ַ�
	while (1)
	{
		cin.getline(s, 100);		//����һ�к��ո�ĺ�׺���ʽ
		if (s[0] == '=')
			break;				//�����ʽֻ��һ��"="ʱ���������
		SqStack OPND;
		InitStack(OPND);		//��ʼ������ջ
		cout << fixed << setprecision(2) << EvaluateExpression(OPND, s) << fixed << setprecision(2) << endl;
	}
	return 0;
}