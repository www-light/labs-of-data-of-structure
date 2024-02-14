#include <iostream>
using namespace std;
int MainElement(int a[], int n)
{//求整数序列a的主元素
    int num = 0;
    int main = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        num = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                num++;
            }
            if (num > n / 2)
            {
                main = a[i];
                flag = 1;
            }
        }
        if (flag == 1)
        {
            return a[i];
        }
    }
    if (flag == 0)
        return -1;
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        int* a = new int[n];
        for (int i = 0; i < n; i++)  //输入数据
        {
            cin >> a[i];
        }
        cout << MainElement(a, n) << endl;   //输出主元素的值
    }
    return 0;
}
