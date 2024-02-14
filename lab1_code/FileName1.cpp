#include <iostream>
#include <string>
using namespace std;
typedef struct LNode
{
	int coe;    //ϵ��coe
	int exp;    //ָ��exp
	struct LNode* next;
}LNode, * LinkList;
void CreatePolynomial(LinkList& L, int n)//�ص�
{//��ָ��exp�Ӵ�С�����ʽ
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
		while (q && q->exp >s->exp)//���������ָ����ǰ���ָ�����бȽ�
		{
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;
	}
}
void OutputPolynomial(LinkList L)
{//�������ʽ
	if (!L || !L->next) cout << 0;
	LinkList p = L->next;     //p�Ƕ���ʽ����Ĺ���ָ��,��ʼ��Ϊ��Ԫ���
	while (p)
	{
		if (p == L->next)     //pָ����Ԫ���ʱ������ָ��������������ʽ
		{
			if (p->exp != 0)
				cout << p->coe << "x^" << p->exp;
			else
				cout << p->coe;
		}
		else      //pָ���������ʱ������ϵ����������ָ��������������ʽ
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
LinkList Add(LinkList LA, LinkList LB)//�ص�
{//����ʽ�ļӷ�����
	LinkList p1 = LA->next;
	LinkList p2 = LB->next;
	LinkList LC;//�¶���ʽ��ͷ�ڵ�
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
		else//β�巨
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
{//����ʽ�ļ���
	LinkList p = LB->next;
	while (p)
	{
		p->coe *= -1;
		p = p->next;
	}
	OutputPolynomial(Add(LA, LB));
}
void Mul(LinkList LA, LinkList LB)//�ص�
{//����ʽ�ĳ˷�
	LinkList LC;    //Ŀ�����ʽ����LC
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
{//����ʽ��������
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
			p = p->next;//����ɾ����Ҳ��ǰ��
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
{//�����ַ�ѡ�����ʽ�ļӷ����������˷���������
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
	int n;    //�ܼ���n������
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
