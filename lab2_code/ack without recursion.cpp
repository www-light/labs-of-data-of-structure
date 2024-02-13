#include<iostream>
#include<stack>
using namespace std;
#define MAXSIZE 100
int Ack(int m, int n)
{//Ackermann函数的非递归求值
    stack<int> s1;
    stack<int> s2;
    s1.push(m);
    s2.push(n);
    while (!s1.empty())
    {
        while (m != 0)
        {
            if (n == 0) {
                m -=1;
                n = 1;
                s1.push(m);
                s2.push(n);

            }
            else
            {
                n -= 1;
                s1.push(m - 1);
                s2.push(-1);
            }
        }
        n += 1;
        while ((!s1.empty()) && (s2.top() != -1))
        {
            s1.pop();
            s2.pop();
        }
        if (!s1.empty())
        {
            m = s1.top();
            s2.pop();
            s2.push(n);
        }
    }
    return n;
}
int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        if (m == 0 && n == 0) break;
        cout << Ack(m, n) << endl;
    }
    return 0;
}