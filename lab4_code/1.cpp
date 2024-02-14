#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef struct
{//哈夫曼树结点的形式
	int weight;               //结点的权值
	int parent, lchild, rchild;  //结点的双亲、左孩子、右孩子的下标
}HTNode, * HuffmanTree;       //动态分配数组存储哈夫曼树
typedef char** HuffmanCode;   //定义编码表类型
//需要完成计算词频、哈夫曼哈夫曼树建好后的数组、哈夫曼编码、该字符串的哈夫曼编码
int Search(char a[], char ch)
{//查找数组中字符ch所在的位置，返回数组下标，否则返回-1
	char* p = a;
	int i = 0;
	while (*p != '\0')
	{
		if (*p == ch)
		{
			return i;
		}
		i++;
	}
	return -1;
}
void Sort(char a[], int b[], int len)
{//按ASCII码冒泡排序
	//在CharFrequency()函数中已经排好
}
void Select_min(HuffmanTree HT, int n, int& s1, int& s2)
{// 在HT[k](1≤k≤i-1）中选择两个其双亲域为0且权值最小的结点，并返回它们在HT中的序号s1和s2
	int min1 = MAXSIZE; int min2 = MAXSIZE;
	int min1_i, min2_i;
	//先找到一个双亲下标为0的
	//cout << n << endl;
	for (int i = 1; i <= n; i++)//先找s1
	{
		if (HT[i].parent == 0)
		{
			if (HT[i].weight < min1)
			{
				min1 = HT[i].weight;  
				min1_i = i;            
			}
		}
	}
	s1 = min1_i;
	//cout << s1 << " ";
	for (int i = 1; i <= n; i++)//找s2
	{
		if (HT[i].parent == 0 && i != s1)
		{
			if (HT[i].weight < min2)
			{
				min2 = HT[i].weight;
				min2_i = i;
			}
		}
	}
	s2 = min2_i;
	//cout << s2 << " ";
	//cout << endl;
}
int m;
void CreateHuffmanTree(HuffmanTree& HT, int n, int b[])
{//构造哈夫曼树HT
	if (n <= 1)
	{
		return;
	}
	m = 2 * n - 1;//包括叶节点和分支节点
	HT = new  HTNode[m + 1];
	//初始化 
	for (int i = 1; i <= m; ++i)//进行初始化，将标记双亲、左右孩子的下标都初始为0
	{
		HT[i].parent = 0;//
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		HT[i].weight=b[i-1];//将词频赋值为叶子节点的权值
		/*cout <<"weignt"<< HT[i].weight;*/
	}
	//初始化结束后，开始创建哈夫曼树
	
	int s1 = 0;
	int s2 = 0;
	for (int i = n + 1; i <= m; i++)//n及以前为叶子节点，从n以后开始建 
	{
		Select_min(HT, i - 1,s1, s2);//选择两个权值最小的节点 
		//cout << "s1" << s1 << "s2" << s2 << endl;
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		//cout << i << ":" << HT[i].parent << endl;
		//cout << i << endl;
	}
}
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
{//从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
	HC = new char* [n + 1];
	char* cd = new char[n];//暂时存放编码
	cd[n - 1] = '\0';//暂时存放哈夫曼编码 
	int start = 0;
	int c = 0;
	int parent_node = 0;
	for (int i = 1; i <= n; i++)
	{
		start = n - 1;
		c = i;//从叶子节点开始回溯，倒着存
		parent_node = HT[i].parent;
		while (parent_node != 0)
		{
			--start;
			if (HT[parent_node].lchild == c)
			{
				cd[start] = '0';
			}
			else
			{
				cd[start] = '1';
			}
			c = parent_node;//这个双亲节点成为孩子节点
			parent_node = HT[parent_node].parent;//继续寻找这个“双亲节点”的孩子节点
		}
		HC[i] = new char[n - start];//为哈夫曼编码分配空间
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}
void CharFrequency(char ch[], char a[], int b[], int& j)
{//统计词频
	int temp[MAXSIZE] = { 0};
	int i = 0;
	for (int i = 0; i < strlen(ch); i++)//计算词频
	{
		temp[ch[i] - 97+1]++;
	}
	i = 0;
	int z = 0;
	while (i <= 26)//将频率和字符赋给数组a,b
	{
		if (temp[i] != 0)
		{
			b[z] = temp[i];
			a[z] = char(96 + i);
			z++;
		}
		i++;
	}
	j = z;
	a[z] = '\0';
	b[z] = '\0';
	/*for (int i = 0; i < z; i++)
	{
		cout << b[i];
	}*/
}
void PrintHT(HuffmanTree HT)
{//输出哈夫曼树的存储结构的终态
	//int i = 1;
	//while (HT[i].weight != '\0')
	//{
	//	i++;
	//}
	//int len = i;
	cout << m << endl;
	for (int i = 1; i<=m; i++)
	{
		cout << i << " " << HT[i].weight << " " << HT[i].parent << " " << HT[i].lchild <<" "<< HT[i].rchild<<endl;
	}
}
void PrintHC(HuffmanCode HC, char a[], int j)
{//输出每个字符的哈夫曼编码
	for (int i = 1; i <= j; i++)
	{
		if (i != j)
		{
			cout << a[i - 1] << ":" << HC[i] << " ";
		}
		else
		{
			cout << a[i - 1] << ":" << HC[i];
		}
		
	}
	cout << endl;
}
int main()
{
	char ch[MAXSIZE];
	int i, j;
	while (cin >> ch)
	{
		if (ch[0] == '0') break;
		HuffmanTree HT;
		char a[MAXSIZE] = { '\0' };
		int b[MAXSIZE] = { 0 };
		j = 0;      //j统计不同字符的数量

		CharFrequency(ch, a, b, j);   //统计词频
		Sort(a, b, j);     //按ASCII码冒泡排序
		for (i = 0; a[i] != '\0'; i++)   //输出统计出来的字符和出现频率
		{
			if (a[i + 1] != '\0')
				cout << a[i] << ":" << b[i] << " ";
			else
				cout << a[i] << ":" << b[i] << endl;
		}
		//构造哈夫曼树

		CreateHuffmanTree(HT, i, b);    //构造哈夫曼树HT
		PrintHT(HT);      //输出哈夫曼树的存储结构的终态
		//哈夫曼编码
		HuffmanCode HC;    //编码表HC
		CreateHuffmanCode(HT, HC, j);
		PrintHC(HC, a, j);    //输出每个字符的哈夫曼编码
		int k;
		for (i = 0; ch[i] != '\0'; i++)    //输出编码后的字符串
		{
			for (k = 0; k < j; k++)
			{
				if (ch[i] == a[k])
					cout << HC[k + 1];
			}
		}
		cout << endl;
		cout << ch << endl;//输出解码后的字符串（与输入的字符串相同）
	}
	return 0;
}
