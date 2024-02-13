#include<iostream>
using namespace std;
#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
	int* base;
	int* top;
	int stacksize;
}SqStack;
Status InitSqStack(SqStack& S)
{//ջ�ĳ�ʼ��
	S.base = new int[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, int e)
{//��ջ
	if (S.top - S.base != MAXSIZE)
	{
		*S.top = e;
		S.top++;
		return OK;
	}
	return OK;
}
Status Pop(SqStack& S)
{//��ջ
	--S.top;
		return OK;
}
Status GetTop(SqStack S)
{//ȡջ��Ԫ��
	if (S.top != S.base)
	{
		return *(S.top - 1);
	}
	return ERROR;
}
void InOutS(SqStack& S, int a[], int n)
{//��ջ�ͳ�ջ�Ļ�������
	for (int i = 0; i < n; i++) {
		if (a[i] != -1)
			Push(S, a[i]);
		else {
			if (S.top != S.base) {
				cout << GetTop(S) << endl;
				Pop(S);
			}
			else {
				cout << "POP ERROR" << endl;
				break;
			}
		}
	}
}
//5
//1 2 - 1 - 1 1
//5
//1 - 1 - 1 2 2
//30
//1 8 8 9 90 90 - 1 90 0 8 - 2 89 - 3 5 - 4532 - 1 89 - 1 8 8 79 789 67 8 - 1 - 1 9 7 - 1 844
//10
//342 - 1 34 - 1 3482 237849 89 - 1 7892 784
//7
//2 4 7 - 1 - 1 5 - 1
//5
//1 - 3 2 3 - 1
//2
//- 1 - 1
//4
//- 1 0 1 2
//9
//1 2 3 4 - 1 - 1 - 1 - 1 - 1
//0
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		SqStack S;
		InitSqStack(S);
		int* a=new int[n];
		for (int i = 0; i < n; i++) cin >> a[i];  //��������
		InOutS(S, a, n);
	}
	return 0;
}
