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
{//操作数栈
	double* base;
	double* top;
	int  stacksize;
}SqStack;
Status InitStack(SqStack& S)
{//操作数栈初始化
	S.base = new double[MAXSIZE];
	 S.top=S.base ;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, double e)
{//操作数栈入栈
	if (S.top - S.base != MAXSIZE)
	{
		*S.top = e;
		S.top++;
		return OK;
	}
	return ERROR;
}
Status Pop(SqStack& S)
{//操作数栈出栈
	if (S.top != S.base)
	{
		--S.top;
		return OK;
	}
	return ERROR;
}
double GetTop(SqStack S)
{//操作数栈取栈顶元素
	if (S.top != S.base)
	{
		return *(S.top - 1);
	}
	return ERROR;	//若不存在栈顶元素则返回ERROR
}
double Calculate(double a, char op, double b)
{//计算表达式“a op b”的值
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
{//后缀算术表达式求值
 //设OPND为操作数栈
 //表达式求值算法调用Calculate函数 
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
	//用字符数组存储表达式，每个数组元素仅存一个字符
	while (1)
	{
		cin.getline(s, 100);		//输入一行含空格的后缀表达式
		if (s[0] == '=')
			break;				//当表达式只有一个"="时，输入结束
		SqStack OPND;
		InitStack(OPND);		//初始化数字栈
		cout << fixed << setprecision(2) << EvaluateExpression(OPND, s) << fixed << setprecision(2) << endl;
	}
	return 0;
}