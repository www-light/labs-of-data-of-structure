#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct {
    int* elem;       //存储空间的基地址
    int length;      //当前长度
}SqList;
void InitList_Sq(SqList& L, int n) {
    //构造顺序表
    L.elem = new int[n];
    L.length = n;
}
void DeleteItem(SqList& A, int item) {
    //删除顺序表A中所有值为item的元素
    int i = 0;
    int temp = 0;
    while (i < A.length)
    {
        if (A.elem[i] == item)
        {
            temp = i;
            while (i < A.length)
            {
                A.elem[i] = A.elem[i + 1];
                i++;
            }
            i = temp;
            A.length--;
        }
        if (A.elem[i] == item)
            continue;
        else
        i++;
    }
}
void PrintA(SqList A)
{//输出数组元素
    for (int i = 0; i < A.length - 1; i++)
        cout << A.elem[i] << " ";
    cout << A.elem[A.length - 1] << endl;
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        SqList A;
        InitList_Sq(A, n);
        for (int i = 0; i < n; i++)
            cin >> A.elem[i];
        int item;
        cin >> item;
        DeleteItem(A, item);
        PrintA(A);
    }
    return 0;
}