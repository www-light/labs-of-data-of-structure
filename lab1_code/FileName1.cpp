#include <iostream>
#include <string>
using namespace std;
typedef struct LNode
{
	int coe;    //系数coe
	int exp;    //指数exp
	struct LNode* next;
}LNode, * LinkList;
void CreatePolynomial(LinkList& L, int n)//重点
{//按指数exp从大到小存多项式
	L = new LNode;
	L->next = NULL;
	LinkList pre = new LNode;
	LinkList q = new LNode;
	for (int i = 1; i <= n; i++)
	{
		LinkList s = new LNode;
		cin >> s->coe >> s->exp;//new expression
		pre = L;//previos
		q = L->next;//currrent
		while (q && q->exp >s->exp)//将输入的新指数和前面的指数进行比较
		{
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;
	}
}
void OutputPolynomial(LinkList L)
{//输出多项式
	if (!L || !L->next) cout << 0;
	LinkList p = L->next;     //p是多项式链表的工作指针,初始化为首元结点
	while (p)
	{
		if (p == L->next)     //p指向首元结点时，根据指数的情况输出多项式
		{
			if (p->exp != 0)
				cout << p->coe << "x^" << p->exp;
			else
				cout << p->coe;
		}
		else      //p指向其他结点时，根据系数的正负和指数的情况输出多项式
		{
			if (p->coe > 0) cout << "+";
			if (p->exp != 0)
				cout << p->coe << "x^" << p->exp;
			else
				cout << p->coe;
		}
		p = p->next;
	}
	cout << endl;
}
LinkList Add(LinkList LA, LinkList LB)//重点
{//多项式的加法运算
	LinkList p1 = LA->next;
	LinkList p2 = LB->next;
	LinkList LC;//新多项式的头节点
	CreatePolynomial(LC, 0);
	LinkList p3;
	p3 = LC;
	int sum = 0;
	while (p1 && p2)//traverse all the Node
	{
		if(p1->exp==p2->exp)//eqality
		{
			sum = p1->coe + p2->coe;
			if (sum != 0)
			{
				p1->coe = sum;
				p3->next = p1;//add p1 to the linklist L3
				p3 = p1;
				p1 = p1->next;
				p2 = p2->next;
			}
			else
			{
				 p1 = p1->next; 
				 p2 = p2->next; 
			}
		}
		else if (p1->exp < p2->exp)
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
		else//尾插法
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
	}
	p3->next = p1 ? p1 : p2;
	return LC;
}
void Minus(LinkList LA, LinkList LB)
{//多项式的减法
	LinkList p = LB->next;
	while (p)
	{
		p->coe *= -1;
		p = p->next;
	}
	OutputPolynomial(Add(LA, LB));
}
void Mul(LinkList LA, LinkList LB)//重点
{//多项式的乘法
	LinkList LC;    //目标多项式链表LC
	CreatePolynomial(LC, 0);
	LinkList pa = LA->next;
	LinkList pb = LB->next;
	LinkList temp;//save the intermediate result
	CreatePolynomial(temp, 0);
	while (pa)
	{
		while (pb)
		{
			LinkList p = new LNode;
			p->coe = pa->coe * pb->coe;
			p->exp = pa->exp + pb->exp;
			temp->next = p;
			LC = Add(LC, temp);//add the result to LC
			pb = pb->next;
		}
		pa = pa->next;
	}
	OutputPolynomial(LC);
}
void Diff(LinkList L)
{//多项式的求导运算
	LinkList p;
	p = L;
	while (p)
	{
		p->coe *= p->exp;
		p->exp--;
		if (p->exp < 0)
		{
			LinkList del = new LNode;
			del = p;
			p = p->next;//既是删除，也是前进
			delete del;
		}
		else
		{
			p = p->next;
		}

	}
	OutputPolynomial(L);
}
void Opt(LinkList& LA, LinkList& LB, string s)
{//依据字符选择多项式的加法、减法、乘法和求导运算
	if (s == "+") OutputPolynomial(Add(LA, LB));
	if (s == "-") Minus(LA, LB);
	if (s == "*") Mul(LA, LB);
	if (s == "'")
	{
		Diff(LA);
		Diff(LB);
	}
}
 int main()
{
	int n;    //总计有n组数据
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		LinkList LA, LB;
		CreatePolynomial(LA, a);
		CreatePolynomial(LB, b);
		string s;
		cin >> s;
		Opt(LA, LB, s);
	}
	return 0;
}
