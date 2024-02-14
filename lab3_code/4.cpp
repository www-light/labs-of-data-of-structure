#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include "cstring"
using namespace std;

#define ASCII_SIZE 256     //ASCII�빲256λ���ɱ�ʾ�����ַ�����Ϊ���ַ�����Ĵ�С
#define MAXLEN 5000			//������󳤶�
typedef struct {
	char* ch;				   //�洢����һά����
	int length;				   //���ĵ�ǰ����   
}HString;
void InputRule(HString ip[], int n)
{//�������n��ip��ַ��ŵ�ip����
    for (int i = 0; i < n; i++) {
        ip[i].ch = new char[MAXLEN];

        char p[MAXLEN] = { 0 };
        fgets(p, sizeof(p), stdin);
        int plen = strlen(p);

        int k = 0;
        for (int j = 0; j < plen; j++) {
            if ((p[j] >= '0' &&p[j] <= '9') || p[j] == '.') {
                ip[i].ch[k] = p[j];
                k++;
            }
        }
        ip[i].ch[k - 1] = '\0';
        ip[i].length = strlen(ip[i].ch);
    }
}
void InputLog(HString& log, int m)
{//�������m����־�ϲ���ŵ�log������log���ܳ���
    log.ch = new char[MAXLEN];
    char* log_record = new char[MAXLEN];
    memset(log.ch, '\0', sizeof(char) * MAXLEN);
    for (int i = 0, j = 0; i < m; i++)
    {
        char s[200];
        fgets(s, sizeof(s), stdin);
        int len = strlen(s);
        int z = 0;
        while (z < len)
        {
            log_record[j] = s[z];
            j++;
            z++;
        }
    }
    strcpy(log.ch, log_record);
    log.length = strlen(log.ch);
}
void GetBC(HString pattern, int*& bc)
{//�õ����ַ�bc����
    int i = 0;
    memset(bc, -1, sizeof(int) * ASCII_SIZE);
    i = 0;
    while (i < strlen(pattern.ch))
    {
        bc[(int)pattern.ch[i]] = i;// // ����ģʽ�����ַ��� ASCII ֵ����¼�ַ���Ӧ��λ��
        i++;
    }
  /*  for (int i = 0; i < pattern.length; i++)
    {
        cout << bc[i];
    }*/
    for (int i = 0; i < ASCII_SIZE; i++) {
        bc[i] = -1;
    }

    for (int i = 0; i < strlen(pattern.ch); i++) {
        int ascii = (int)pattern.ch[i];
        bc[ascii] = i;
    }
}

void GetGS(HString pattern, int*& suffix, bool*& prefix)
{//�õ��ú�׺gs������suffixΪint��������洢��׺�ַ���Ӧǰ���λ�ã�prefixΪbool��������洢�Ƿ����ƥ���ǰ׺�ַ���
//suffix��prefix��ͬ���ɺú�׺����
    int len = strlen(pattern.ch);
    int i = 0;
    for (i = 0; i < len - 1; i++)
    {
        suffix[i] = -1;
        prefix[i] = false;
    }
    i = 0;
    for ( i = 0; i < len - 1; i++)
    {
        int j = i;
        int  q = 0;
        while (j >= 0 && pattern.ch[j] == pattern.ch[len - 1 - q])
        {

            j--;
            q++;
            suffix[q] = j + 1;// ���ºú�׺���飬��¼��׺�ַ���Ӧ��ǰ���λ��
        }
        if (j == -1)
        {
            prefix[q] = true;// ��� j Ϊ -1����ʾ������׺��ƥ�䣬���ö�Ӧλ�õ�ǰ׺Ϊ true
        }
    }
    for (int i = 0; i < len; i++) {
        suffix[i] = -1;
        prefix[i] = false;
    }

    for (int i = 0; i < len - 1; i++) {
        int j = i;
        //������׺u*����
        int k = 0;

        while (j >= 0 && pattern.ch[j] == pattern.ch[len - 1 - k]) {
            j--; k++;
            suffix[k] = j + 1;
        }

        if (j == -1) {
            prefix[k] = true;
        }
    }
}
int GetGSMove(int* suffix, bool* prefix, int bc_pos, int pattern_length)
{//����suffix��prefix���飬���غú�׺�ƶ��Ĵ���
//bc_pos��ʾ���ַ�BC��λ�ã���һλΪ�ú�׺���λ�ã�
    //�ú�׺����
    int k = pattern_length - 1 - bc_pos;
    if (suffix[k] != -1) {
        return bc_pos - suffix[k] + 1;
    }
    for (int i = bc_pos + 2; i < pattern_length; i++) {
        if (prefix[pattern_length = i]) {
            return i;
        }
    }

    return pattern_length;
}
int IndexBM(HString str, HString pattern)
{//��str.ch��ƥ��pattern.ch��ƥ��ɹ����������������Ӵ���һ�γ��ֵ�λ�ã����򷵻�-1��
//�ֱ����ַ�����bc�ͺ��ַ�����suffix��prefix���ֱ�����������Ե��ƶ�λ����ȡ��ֵ��Ϊ�����ƶ�λ��
    if (strlen(pattern.ch) == 0) {
        return -1;
    }

    int* bc = new int[ASCII_SIZE];
    GetBC(pattern, bc);

    int* suffix = new int[10000];
    bool* prefix = new bool[10000];
    GetGS(pattern, suffix, prefix);

    int i = 0;
    while (i <= strlen(str.ch) - strlen(pattern.ch)) {
        int j;
        for (j = strlen(pattern.ch) - 1; j >= 0; j--) {// ��ģʽ��ĩβ��ǰƥ��
            if (str.ch[i + j] != pattern.ch[j]) {
                break;
            }
        }

        if (j < 0) {// ���ģʽ����ȫƥ��
            return i;
        }
        // ���ģʽ��δ��ȫƥ��
        int numB = j - bc[(int)str.ch[i + j]];

        int numG = 0;
        if (j < strlen(pattern.ch) - 1) {
            numG = GetGSMove(suffix, prefix, j, strlen(pattern.ch));
        }
        if (numB >= numG)
        {
            i += numB;
        }
        else if (numB < numG)
        {
            i += numG;
        }
        else
        {
            i += 1;
        }
    }

    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    getchar();
    HString ip[5000];	//ip������n��ip��ַ 
    InputRule(ip, n);	   //����n�й��򣬴ӹ������ҵ����е�ip��ַ��������ip������

    HString log;
    log.ch = (char*)malloc(sizeof(char) * 10000);
    strcpy(log.ch, "");	//��log.ch��ʼ��Ϊ���ַ���
    log.length = 0;
    InputLog(log, m);	//����m����־����m����־�ϲ�Ϊ1������־��������log�У����س���־log�ĳ���

    for (int i = 0; i < n; i++)
    {
        if (IndexBM(log, ip[i]) != -1)		//����ֵ��Ϊ-1��ƥ��ɹ�
        {
            cout << "Intrusion." << endl;
            return 0;
        }
    }
    cout << "No Intrusion." << endl;
    return 0;

}