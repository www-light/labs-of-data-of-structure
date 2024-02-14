#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cstring"
#include<stdlib.h>
using namespace std;


#define MAXLEN 5000			//������󳤶�
typedef struct {
	char* ch;			//�洢����һά����
	int length;				//���ĵ�ǰ����   
}HString;


void InputRule(HString ip[], int n)//������
{//����n�����򣬲������е�n��ip��ַ��ŵ�ip���� 
    char  p[200];//�������
    int a = 0, b = 0;
    for (int i = 0; i <n; i++)
    {
        ip[i].ch = new char[MAXLEN];
    }
   for (int i = 0; i < n; i++)
    {
        fgets(p, sizeof(p), stdin);
        for (int j = 0; j <= sizeof(p); j++)//add ip address to ip's array
        {
            if (p[j] == ':' && p[j - 1] == 'p')//judge the length of ip adress
            {
                a = j + 1;
            }
            if (p[j] == ' ' && p[j + 1] == 'm')
            {
                b = j - 1;
            }
        }
            for (int j = a, m = 1; j <= b; j++, m++)
            {
                ip[i].ch[m] = p[j];
                ip[i].length = b - a + 1;
            }
    }
  /* for (int i = 0; i < n; i++)
   {
       for (int j = 1; j <= ip[i].length; j++)
       {
           cout << ip[i].ch[j];
      }
       cout << endl;
   }*/
}

void InputLog(HString& log, int m)//������
{//����m����־�����ϲ���ŵ�log
    int z = 0;
    log.ch = new char[MAXLEN];
    /*char* log_record = new char[MAXLEN];
    log.ch[0] = '\0';*/
    for (int i = 0; i < m; i++)//�ϲ�m��log
    {
        char s[200] = { 0 };
        fgets(s, sizeof(s), stdin);
        int len = strlen(s);
        strcat(log.ch, s);
       // cout << endl;
    }
    log.length = (int)strlen(log.ch);
}

void GetNext(HString pattern, int* &next)
{//��ģʽ��pattern��next����ֵ����������next
    int len = strlen(pattern.ch);
    next = new int[100000];
    int i = 1;
    next[1] =0;
    int j = 0;
    while (i < pattern.length)
    {
        if(j==0||pattern.ch[i]==pattern.ch[j])
           {
                ++j;
                ++i;
                next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int IndexKMP(HString target, HString pattern, int*next)
{//KMPƥ���㷨,targetΪ������patternΪ�Ӵ���
//ƥ��ɹ����������������Ӵ���һ�γ��ֵ�λ�ã����򷵻�-1��
//����GetNext������ȡģʽ����next����
    GetNext(pattern, next);
   /* for (int i = 1; i <= pattern.length; i++)
    {
        cout << next[i] << " ";
    }*/
    int i = 1;
    int j = 1;
    while (i <= target.length && j <= pattern.length)
    {
       if (j==0||target.ch[i] == pattern.ch[j])
        {
            ++i;
            ++j;
       }
        else 
        {
            j = next[j];
        }
    }
    if (j >= pattern.length)
    {
        return i - pattern.length;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    getchar();


    HString ip[5000];//ip������n��ip��ַ 

    InputRule(ip, n);

    HString log;
    log.ch = (char*)malloc(sizeof(char) * 10000);
    strcpy(log.ch, "");
    log.length = 0;
    InputLog(log, m);

    for (int i = 0; i < n; i++)
    {
        int* next = new int[ip[i].length];
        if (IndexKMP(log, ip[i], next) != -1)
        {
            cout << "Intrusion." << endl;
            return 0;
        }
    }
    cout << "No Intrusion." << endl;
    return 0;

}