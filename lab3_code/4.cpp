#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include "cstring"
using namespace std;

#define ASCII_SIZE 256     //ASCII码共256位，可表示所有字符，作为坏字符数组的大小
#define MAXLEN 5000			//串的最大长度
typedef struct {
	char* ch;				   //存储串的一维数组
	int length;				   //串的当前长度   
}HString;
void InputRule(HString ip[], int n)
{//将输入的n个ip地址存放到ip数组
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
{//将输入的m条日志合并存放到log，返回log的总长度
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
{//得到坏字符bc数组
    int i = 0;
    memset(bc, -1, sizeof(int) * ASCII_SIZE);
    i = 0;
    while (i < strlen(pattern.ch))
    {
        bc[(int)pattern.ch[i]] = i;// // 根据模式串中字符的 ASCII 值，记录字符对应的位置
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
{//得到好后缀gs，其中suffix为int类型数组存储后缀字符对应前面的位置，prefix为bool类型数组存储是否存在匹配的前缀字符串
//suffix和prefix共同构成好后缀数组
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
            suffix[q] = j + 1;// 更新好后缀数组，记录后缀字符对应的前面的位置
        }
        if (j == -1)
        {
            prefix[q] = true;// 如果 j 为 -1，表示整个后缀都匹配，设置对应位置的前缀为 true
        }
    }
    for (int i = 0; i < len; i++) {
        suffix[i] = -1;
        prefix[i] = false;
    }

    for (int i = 0; i < len - 1; i++) {
        int j = i;
        //公共后缀u*长度
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
{//利用suffix和prefix数组，返回好后缀移动的次数
//bc_pos表示坏字符BC的位置（后一位为好后缀起点位置）
    //好后缀长度
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
{//在str.ch中匹配pattern.ch，匹配成功返回主串中所含子串第一次出现的位置，否则返回-1。
//分别求坏字符数组bc和好字符数组suffix、prefix，分别计算两个策略的移动位数，取大值作为最终移动位数
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
        for (j = strlen(pattern.ch) - 1; j >= 0; j--) {// 从模式串末尾向前匹配
            if (str.ch[i + j] != pattern.ch[j]) {
                break;
            }
        }

        if (j < 0) {// 如果模式串完全匹配
            return i;
        }
        // 如果模式串未完全匹配
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
    HString ip[5000];	//ip数组存放n个ip地址 
    InputRule(ip, n);	   //输入n行规则，从规则中找到所有的ip地址，保存至ip数组中

    HString log;
    log.ch = (char*)malloc(sizeof(char) * 10000);
    strcpy(log.ch, "");	//将log.ch初始化为空字符串
    log.length = 0;
    InputLog(log, m);	//输入m行日志，将m行日志合并为1个长日志并保存至log中，返回长日志log的长度

    for (int i = 0; i < n; i++)
    {
        if (IndexBM(log, ip[i]) != -1)		//返回值不为-1则匹配成功
        {
            cout << "Intrusion." << endl;
            return 0;
        }
    }
    cout << "No Intrusion." << endl;
    return 0;

}