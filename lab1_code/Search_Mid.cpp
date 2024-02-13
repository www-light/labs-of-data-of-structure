#include <iostream>
using namespace std;
int Search_Mid(int A[], int B[], int n)
{//求解两个升序序列的中位数
	int* c;
	c = new int[n+n];
	int* pa = A, * pb = B, * pc = c;
	int* pa_last = A + n - 1;
	int* pb_last = B + n - 1;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)
		{
			*pc = *pa;
			pc++;
			pa++;
		}
		else
		{
			*pc = *pb;
			pc++;
			pb++;
		}
	}
	while (pa <= pa_last)
	{
		*pc = *pa;
		pc++;
		pa++;
	}
	while (pb <= pb_last)
	{
		*pc = *pb;
		pc++;
		pb++;
	}
	int i = 0;
	while (i < n + 1)
	{
		i++;
	}
	return c[i-2];
}
void Input(int a[], int n)
{//读入序列
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        int* A = new int[n];
        int* B = new int[n];
        Input(A, n);
        Input(B, n);
        cout << Search_Mid(A, B, n) << endl;
    }
	return 0;
}