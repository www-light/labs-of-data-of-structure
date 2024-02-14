#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
#define MAXLEN 5000			//������󳤶�
typedef struct {
	char* ch;			//�洢����һά����
	int length;				//���ĵ�ǰ����   
}HString;
//�����ַ���������
//3 3
//protocol:tcp ip : 225.93.118.39 msg : "Network intrusion detected."
//protocol : tcp ip : 152.213.218.150 msg : "Network intrusion detected."
//protocol : tcp ip : 181.164.101.231 msg : "Network intrusion detected."
//Proto Recv - Q Send - Q Local - Address Foreign - Address State
//tcp 0 0 36.51.200.67 : 95403 40.56.49.213 : 29716 LAST_ACK
//tcp 0 0 215.142.133.153 : 49323 106.54.135.230 : 18487 CLOSED
void InputRule(HString ip[], int n)
{//����n�����򣬲������е�n��ip��ַ��ŵ�ip���� 
    char  p[200];//�������
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        ip[i].ch = new char[MAXLEN];
    }
    for (int i = 0; i < n; i++)
    {
        fgets(p, sizeof(p), stdin);
        for (int j = 0; j < sizeof(p); j++)//add ip address to ip's array
        {
            if (p[j] == ':' && p[j - 1] == 'p')//judge the length of ip adress
            {
                a = j + 1;
            }
            if (p[j] == ' ' && p[j + 1] == 'm')
            {
                b = j - 1;
            }
            for (int j = a, m = 0; j <= b; j++, m++)
            {
                ip[i].ch[m] = p[j];
                ip[i].length = b - a + 1;
                ip->ch[m+1] = '\0';
            }
        }
    }
}

void InputLog(HString& log, int m)
{//����m����־�����ϲ���ŵ�log
    int z = 0;
    log.ch = new char[MAXLEN];
   char *log_record=new char[MAXLEN];
    for (int i = 0,j=0; i < m; i++)
    {
        char s[200];
        fgets(s, sizeof(s), stdin);
        int len = strlen(s);
        z = 0;
        while (z <len)
        {
            //cout << s[z]<<" ";
            log_record[j] = s[z];
            j++;
            z++;
        }
       // cout << endl;
    }
    strcpy(log.ch, log_record);
    log.length = strlen(log.ch);
}

int IndexBF(HString S, HString T)//log is main string ,ip is pattern string
{//��ģʽƥ���㷨,SΪ����(Ŀ�괮)��TΪ�Ӵ�(ģʽ��)��
//ƥ��ɹ����������������Ӵ���һ�γ��ֵ�λ�ã����򷵻�-1��
    int i = 0, j = 0;
    while (i < S.length && j < T.length)
    {
        if (S.ch[i] == T.ch[j])
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
    if (j >= T.length)
    {
        return 2;
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

        if (IndexBF(log, ip[i]) != -1)
        {
            cout << "Intrusion." << endl;
            return 0;
        }
    }
    cout << "No Intrusion." << endl;
    return 0;

}