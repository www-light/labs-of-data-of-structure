#include<iostream>
#include<string.h>
using namespace std;
int IndexSubstring(string s1, string s2)
{//查找子串第一次出现的位置
	int i = 0;
	int j = 0;
	while (i <= s1.length() && j <= s2.length())
	{
		if (s1[i] == s2[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j > s2.length())
	{
		return i - s2.length();
	}
	else
	{
		return -1;
	}
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (s1 == "0" && s2 == "0") break;
		int pos = IndexSubstring(s1, s2);
		cout << pos << endl;
	}
	return 0;
}