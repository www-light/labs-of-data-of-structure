#include<iostream>
#define MAXSIZE 100
using namespace std;
void Insert(char s[], char t[], int pos, int LenS, int LenT)
{//字符串的插入
    for (int i = 0; i < LenS; i++)
    {
        if (i+1 == pos)
        {
            int j = LenS-1;
            while (j>=pos-1)
            {
                s[j+LenT] = s[j];
                j--;
            }
            break;
        }
    }
    int i = pos-1;
    int j = 0;
    while ( j < LenT)
    {
        s[i] = t[j];
        j++;
        i++;
    }
    s[LenS + LenT] = '\0';
    cout << s;
}
int main()
{
    int pos;
    while (cin >> pos)    	              //输入插入位置pos
    {
        if (pos <= 0) break;
        char s[MAXSIZE], t[MAXSIZE];
        cin >> s >> t;            	     //输入字符串s和t
        int LenS = 0, LenT = 0;
        while (s[LenS] != '\0') LenS++;  //求字符串s的长度LenS
        while (t[LenT] != '\0') LenT++;  //求字符串t的长度LenT
        if (pos > LenS) break;           //插入位置非法
        Insert(s, t, pos, LenS, LenT);
    }
    return 0;
}