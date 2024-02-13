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
	 S.top=S.base ;
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
bool isdigit(char ch) {//disgtinguish '.' and other operation
	if ((ch >= '0' && ch <= '9') || ch == '.') {
		return true;
	}
	else return false;
}
double EvaluateExpression(SqStack OPND, char s[])
{//��׺�������ʽ��ֵ
 //��OPNDΪ������ջ
 //���ʽ��ֵ�㷨����Calculate���� 
	int len = strlen(s);
	char c;
	double a1, a2;
	char ch;
	for (int i = 0; i < len; i++)
	{
		c = s[i];//save every char
		if (isdigit(c)) {
			double num = c - '0';
			double multiple = 0;
			bool flag = 0;
			while (i + 1 < len && isdigit(s[i + 1])) {//handle the whole part of decimals and integar

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
			Push(OPND, num);//when the ending of the operation of the whole part of number
		}
		else if (c != '=')
		{
			switch (c)
			{
			case ' ':
				break;
			case '=':
				break;
			default:
				a1 = GetTop(OPND);
				Pop(OPND);
				a2 = GetTop(OPND);
				Pop(OPND);
				Push(OPND, Calculate(a2, c, a1));
				break;
			}
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