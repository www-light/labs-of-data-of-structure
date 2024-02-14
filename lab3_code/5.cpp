#include<iostream>
#include<cstring>
using namespace std;
void Count(string c, int b[])
{//统计字符出现的频度
    int count=0;
    for (int i = 0; i < c.length(); i++)
    {
        if (isdigit(c[i]))
        {
            b[(int)c[i] - 48]++;//处理0~9
        }
        else
        {
            b[(int)c[i] - 65 + 10]++;//处理a~b
        }
    }
    for (int i = 0; i <35; i++)
    {
        if (b[i] != 0)
        {
            if (i < 10)
            {
                cout << i << ":" << b[i] << endl;
            }


            else if (i >= 10)
            {
                int temp = 65+i-10 ;
                char ch =char(temp);//还原为字符
                cout << ch << ":" << b[i] << endl;
            }
        }
    }
}
int main()
{
    string c;     //存储输入的字符串
    while (cin >> c)
    {
        if (c == "0") break;
        int* b = new int[36] {0};        	//存储对应字符的个数
        Count(c, b);
    }
    return 0;
}