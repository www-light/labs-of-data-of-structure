#include<iostream>
#include<cstring>
#define MAXSIZE 100
using namespace std;
void Reverse(char* a, int n)
{//�ݹ�ʵ���ַ���������洢
	if (strlen(a)/2==n)
	{
		return;
	}
	else
	{
		char temp = a[strlen(a) - n];
		a[strlen(a) - n] =a[n-1];
		a[n - 1] = temp;
		Reverse(a, n-1);
	}
}
int main()
{
	char a[MAXSIZE];
	while (cin >> a)
	{
		if (strcmp(a, "0") == 0) break;
		int i = 0;
		while (a[i] != '\0') i++;  //ͳ���ַ���
		Reverse(a, i);
		cout << a << endl;  //����ַ�����
	}
	return 0;
}