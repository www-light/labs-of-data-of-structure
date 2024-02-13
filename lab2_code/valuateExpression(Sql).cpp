#include <iostream>
#include<iomanip>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct
{//运算符栈
	char* base;
	char* top;
	int stacksize;
}SqStack1;
Status InitStack1(SqStack1& S)
{//运算符栈初始化
	S.base = new char[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push1(SqStack1& S, char e)
{//运算符栈入栈
	if (S.top - S.base != MAXSIZE)
	{
		*S.top = e;
		S.top++;
		return OK;
	}
	return ERROR;
}
Status Pop1(SqStack1& S)
{//运算符栈出栈
	if (S.top != S.base)
	{
		--S.top;
		return OK;
	}
	return ERROR;
}
char GetTop1(SqStack1 S)
{//运算符栈取栈顶元素
	if (S.top != S.base)
	{
		return *(S.top-1);
	}
	return ERROR;
}
typedef struct
{//操作数栈
	double* base;
	double* top;
	int  stacksize;
}SqStack2;
Status InitStack2(SqStack2& S)
{//操作数栈初始化
	S.base = new double[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push2(SqStack2& S, double e)
{//操作数栈入栈
	if (S.top - S.base != MAXSIZE)
	{
		*S.top = e;
		S.top++;
		return OK;
	}
	return ERROR;
}
Status Pop2(SqStack2& S)
{//操作数栈出栈
	if (S.top != S.base)
	{
		--S.top;
		
		return OK;
	}
	return ERROR;
}
double GetTop2(SqStack2 S)
{//操作数栈取栈顶元素
	if (S.top != S.base)
	{
		return *(S.top - 1);
	}
	return ERROR;
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

char Precede(char a, char b)
{//比较运算符a和b的优先级
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
{//算术表达式求值的算符优先算法
 //设OPTR和OPND分别为运算符栈和操作数栈
 //表达式求值算法调用Precede函数和Calculate函数 
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
{//设OPTR和OPND分别为运算符栈和操作数栈
	SqStack1 OPTR;
	InitStack1(OPTR);    //初始化OPND栈
	SqStack2 OPND;
	InitStack2(OPND);    //初始化OPTR栈
	Push1(OPTR, '=');     //提前在OPTR栈中放入'='，便于以后比较符号优先级        
	char s[100];
	while (cin >> s)
	{//循环读入多组数据	



		if (s[0] == '=')
			break;    //当表达式只有一个“=”时，输入结束 
		//输出中缀算术表达式的值
		cout << fixed << setprecision(2) << EvaluateExpression(OPTR, OPND, s) << endl;
	}
	return 0;
}
