#include <iostream>
using namespace std;
void Partition(int a[], int n)
{//将正整数构成的集合划分为两个不相交的子集A1和A2
    for (int i = 0; i < n - 1; i++)//sort the array
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    if (n%2==0)
    {
        // distribute the num of array eqally
    // make the num of each array min
        int* MinArr = new int[n / 2];
        int* MaxArr = new int[n / 2 ];
        for (int i = 0, j = 0; i < n / 2, j < n / 2; i++, j++)
        {
            MinArr[j] = a[i];
        }
        for (int i = n / 2, j = 0; i < n, j < n / 2; i++, j++)
        {
            MaxArr[j] = a[i];
        }
        //print the array
        for (int i = 0; i < n / 2; i++)
        {
            if (i != 0)
                cout << " ";
            cout << MinArr[i];
        }
        cout << endl;
        for (int i = 0; i < n / 2; i++)
        {
            if (i != 0)
                cout << " ";
            cout << MaxArr[i];
        }
        cout << endl;
    }
    else
    {// distribute the num of array eqally
    // make the num of each array min
        int* MinArr = new int[n / 2];
        int* MaxArr = new int[n / 2+1];
        for (int i = 0, j = 0; i < n / 2, j < n / 2; i++, j++)
        {
            MinArr[j] = a[i];
        }
//print the array
        for (int i = n / 2, j = 0; i < n, j < n / 2+1; i++, j++)
        {
            MaxArr[j] = a[i];
        }
        for (int i = 0; i < n / 2; i++)
        {
            if (i != 0)
                cout << " ";
            cout << MinArr[i];
        }
        cout << endl;
        for (int i = 0; i < n / 2+1; i++)
        {
            if (i != 0)
                cout << " ";
            cout << MaxArr[i];
        }
        cout << endl;
    }
    
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
        Partition(a, n);
    }
    return 0;
}