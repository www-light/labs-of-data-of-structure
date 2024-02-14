#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct BiTNode
{//二叉树的双链表存储表示
	double data;          //结点数据域
	bool ischaracter;      //判断结点是否为字符
	struct BiTNode* lchild, * rchild;    //左右孩子指针
}BiTNode, * BiTree;
typedef struct
{//字符栈的存储结构
	char* base;     //栈底指针
	char* top;       //栈顶指针
	int stacksize;   //栈可用的最大容量
}SqStack1;
typedef struct
{//结点栈的存储结构
	BiTree* base;
	BiTree* top;
	int stacksize;
}SqStack2;
void InitStack1(SqStack1& s)
{//字符栈的初始化
	s.base = new char[MAXSIZE];
	s.top = s.base;
	s.stacksize =MAXSIZE;
}
void InitStack2(SqStack2& s)
{//结点栈的初始化
	s.base = new BiTree[MAXSIZE];
	s.top = s.base;
	s.stacksize = MAXSIZE;
}
void Push1(SqStack1& s, char ch)
{//字符入栈操作
	if (s.top - s.base != s.stacksize)
	{
		*(s.top) = ch;
		s.top++;
	}
	else
	{
		return;
	}
}
void Push2(SqStack2& s, BiTree t)
{//结点入栈操作
	if (s.top - s.base != s.stacksize)
	{
		*(s.top) = t;
		s.top++;
	}
	else
	{
		return;
	}
}
void Pop1(SqStack1& s, char& ch)
{//字符出栈操作
	if (s.top!=s.base)
	{
		ch = *(--s.top);
	}
	else
	{
		return;
	}
}
void Pop2(SqStack2& s, BiTree& t)
{//结点出栈操作
	if (s.top != s.base)
	{
		t = *(--s.top);
	}
	else
	{
		return;
	}
}
char GetTop(SqStack1 s)
{//取字符栈的栈顶元素
	if (s.base == s.top)
	{
		return -1;
	}
	return *(s.top - 1);
}
bool EmptyStack(SqStack1 s)
{//栈的判空操作
	if (s.top == s.base)
	{
		return true;
	}
	else
	{
		return false;
	}
}
char Precede(char a, char b)
{//判断符号的优先级
	if ((a == '(' && b == ')') || (a == '=' && b == '='))
		return '=';
	else if ((a == '+' || a == '-') && (b == '+' || b == '-' || b == ')' || b == '='))
		return '>';
	else if ((a == '*' || a == '/') && (b == '+' || b == '-' || b == '*' || b == '/' || b == ')' || b == '='))
		return '>';
	else if (a == ')')
		return '>';
	else
		return '<';
}
double Operate(double a, char ch, double b)
{//运算操作，返回相应的数值结果
	if (ch == '-')
	{
		return a - b;
	}
	else if (ch == '+')
	{
		return a + b;
	}
	else if (ch == '*')
	{
		return a * b;
	}
	else if (ch == '/')
	{
		return a / b;
	}
}
bool IsCharacter(char ch)
{//判断ch是否为+、-、*、/、(、)、= 这类的字符，是则返回true
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=')
		return true;
	else
		return false;
}
double InOrder(BiTree T)
{//中序遍历二叉树并求表达式的值
	double a, b;
	char optr;
	if (T != NULL)
	{
		if (T->ischaracter == false)//不是字符时
			return T->data;    
		else
		{
			a = InOrder(T->lchild);   //递归遍历左子树，返回相应数值
			optr = (char)(T->data);     
			b = InOrder(T->rchild);  
			return Operate(a, optr, b);   //把左右子树都遍历了，将左右子树的值和父母节点的运算符加以运算，返回运算结果
		}
	}
	else //树空
		return 0;   
}
void CreateBT(char ch[], BiTree& t, SqStack1 optr, SqStack2 expt)//重点
{//创建二叉树
	int i = 0;
	char opnd1,opnd2;
	char opnd;
	char optr1;
	BiTree b1, b2;
	double num;
	for (i = 0; i < strlen(ch); i++)
	{
		if (!IsCharacter(ch[i]))//处理运算数
		{
			opnd = ch[i];
			BiTree temp = new BiTNode;
			num = opnd - '0';
			temp->ischaracter = false;
			temp->data = num;
			temp->lchild = NULL;
			temp->rchild = NULL;
			Push2(expt, temp);
		}
		else//处理运算符
		{
			switch (Precede(GetTop(optr), ch[i]))    
			{
			case '<':                
				Push1(optr, ch[i]);               
				break;
			case '>':              
				Pop1(optr, optr1);     //运算符栈的元素出栈
				Pop2(expt, b1);      //	运算数栈的栈顶元素出栈
				Pop2(expt, b2);
				t = new BiTNode;      
				t->ischaracter = true;     
				t->data = optr1;        
				t->lchild = b2;        
				t->rchild = b1;        
				Push2(expt, t);
				i--;
				break;
			case '=':        
				Pop1(optr, optr1);                
				break;
			}
		}
	}
}
int main()
{
	char ch[MAXSIZE];
	while (cin >> ch)
	{
		if (ch[0] == '=') break;
		BiTree t;
		SqStack1 optr;      //运算符栈optr
		SqStack2 expt;        //数字栈expt
		InitStack1(optr);     //初始化栈
		InitStack2(expt);     //初始化栈
		Push1(optr, '=');    //先在运算符栈底放入一个'='

		CreateBT(ch, t, optr, expt);       //创建二叉树
		double answer = InOrder(t);
		cout << answer << endl;
	}
	return 0;
}
