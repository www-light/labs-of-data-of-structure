#include<iostream>
#include<cstring>
using namespace std;
void Count(string c, int b[])
{//ͳ���ַ����ֵ�Ƶ��
    int count=0;
    for (int i = 0; i < c.length(); i++)
    {
        if (isdigit(c[i]))
        {
            b[(int)c[i] - 48]++;//����0~9
        }
        else
        {
            b[(int)c[i] - 65 + 10]++;//����a~b
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
                char ch =char(temp);//��ԭΪ�ַ�
                cout << ch << ":" << b[i] << endl;
            }
        }
    }
}
int main()
{
    string c;     //�洢������ַ���
    while (cin >> c)
    {
        if (c == "0") break;
        int* b = new int[36] {0};        	//�洢��Ӧ�ַ��ĸ���
        Count(c, b);
    }
    return 0;
}