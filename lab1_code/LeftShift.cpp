#include <iostream>
using namespace std;
void Reverse(int R[], int left, int right)
{//������R�е�����ԭ������

}
void LeftShift(int R[], int n, int p)
{//������Ϊn������R�е�����ѭ������p��λ��

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (i - p >= 0)
        {
            arr[i-p] = R[i];
        }
        else if(i-p<0)
        {
            arr[i-p+n] = R[i];
        }
   }
    for (int i = 0; i < n; i++)
    {
        R[i] = arr[i];
    }
}
void PrintA(int R[], int n)
{//������������е�����
    for (int i = 0; i < n; i++)//the output of circulation
    {
        cout << R[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        int* R = new int[n];
        for (int i = 0; i < n; i++)  //��������
        {
            cin >> R[i];
        }
        int p;          //p����R�е�����ѭ������p��λ��
        cin >> p;
        LeftShift(R, n, p);         //�����ѭ������
        PrintA(R, n);            //�������
    }
    return 0;
}