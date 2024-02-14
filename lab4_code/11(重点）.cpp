#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct BiTNode
{//��������˫����洢��ʾ
	double data;          //���������
	bool ischaracter;      //�жϽ���Ƿ�Ϊ�ַ�
	struct BiTNode* lchild, * rchild;    //���Һ���ָ��
}BiTNode, * BiTree;
typedef struct
{//�ַ�ջ�Ĵ洢�ṹ
	char* base;     //ջ��ָ��
	char* top;       //ջ��ָ��
	int stacksize;   //ջ���õ��������
}SqStack1;
typedef struct
{//���ջ�Ĵ洢�ṹ
	BiTree* base;
	BiTree* top;
	int stacksize;
}SqStack2;
void InitStack1(SqStack1& s)
{//�ַ�ջ�ĳ�ʼ��
	s.base = new char[MAXSIZE];
	s.top = s.base;
	s.stacksize =MAXSIZE;
}
void InitStack2(SqStack2& s)
{//���ջ�ĳ�ʼ��
	s.base = new BiTree[MAXSIZE];
	s.top = s.base;
	s.stacksize = MAXSIZE;
}
void Push1(SqStack1& s, char ch)
{//�ַ���ջ����
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
{//�����ջ����
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
{//�ַ���ջ����
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
{//����ջ����
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
{//ȡ�ַ�ջ��ջ��Ԫ��
	if (s.base == s.top)
	{
		return -1;
	}
	return *(s.top - 1);
}
bool EmptyStack(SqStack1 s)
{//ջ���пղ���
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
{//�жϷ��ŵ����ȼ�
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
{//���������������Ӧ����ֵ���
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
{//�ж�ch�Ƿ�Ϊ+��-��*��/��(��)��= ������ַ������򷵻�true
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=')
		return true;
	else
		return false;
}
double InOrder(BiTree T)
{//�������������������ʽ��ֵ
	double a, b;
	char optr;
	if (T != NULL)
	{
		if (T->ischaracter == false)//�����ַ�ʱ
			return T->data;    
		else
		{
			a = InOrder(T->lchild);   //�ݹ������������������Ӧ��ֵ
			optr = (char)(T->data);     
			b = InOrder(T->rchild);  
			return Operate(a, optr, b);   //�����������������ˣ�������������ֵ�͸�ĸ�ڵ��������������㣬����������
		}
	}
	else //����
		return 0;   
}
void CreateBT(char ch[], BiTree& t, SqStack1 optr, SqStack2 expt)//�ص�
{//����������
	int i = 0;
	char opnd1,opnd2;
	char opnd;
	char optr1;
	BiTree b1, b2;
	double num;
	for (i = 0; i < strlen(ch); i++)
	{
		if (!IsCharacter(ch[i]))//����������
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
		else//���������
		{
			switch (Precede(GetTop(optr), ch[i]))    
			{
			case '<':                
				Push1(optr, ch[i]);               
				break;
			case '>':              
				Pop1(optr, optr1);     //�����ջ��Ԫ�س�ջ
				Pop2(expt, b1);      //	������ջ��ջ��Ԫ�س�ջ
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
		SqStack1 optr;      //�����ջoptr
		SqStack2 expt;        //����ջexpt
		InitStack1(optr);     //��ʼ��ջ
		InitStack2(expt);     //��ʼ��ջ
		Push1(optr, '=');    //���������ջ�׷���һ��'='

		CreateBT(ch, t, optr, expt);       //����������
		double answer = InOrder(t);
		cout << answer << endl;
	}
	return 0;
}
