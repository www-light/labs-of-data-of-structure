#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef struct
{//��������������ʽ
	int weight;               //����Ȩֵ
	int parent, lchild, rchild;  //����˫�ס����ӡ��Һ��ӵ��±�
}HTNode, * HuffmanTree;       //��̬��������洢��������
typedef char** HuffmanCode;   //������������
//��Ҫ��ɼ����Ƶ�������������������ú�����顢���������롢���ַ����Ĺ���������
int Search(char a[], char ch)
{//�����������ַ�ch���ڵ�λ�ã����������±꣬���򷵻�-1
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
{//��ASCII��ð������
	//��CharFrequency()�������Ѿ��ź�
}
void Select_min(HuffmanTree HT, int n, int& s1, int& s2)
{// ��HT[k](1��k��i-1����ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ�㣬������������HT�е����s1��s2
	int min1 = MAXSIZE; int min2 = MAXSIZE;
	int min1_i, min2_i;
	//���ҵ�һ��˫���±�Ϊ0��
	//cout << n << endl;
	for (int i = 1; i <= n; i++)//����s1
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
	for (int i = 1; i <= n; i++)//��s2
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
{//�����������HT
	if (n <= 1)
	{
		return;
	}
	m = 2 * n - 1;//����Ҷ�ڵ�ͷ�֧�ڵ�
	HT = new  HTNode[m + 1];
	//��ʼ�� 
	for (int i = 1; i <= m; ++i)//���г�ʼ���������˫�ס����Һ��ӵ��±궼��ʼΪ0
	{
		HT[i].parent = 0;//
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		HT[i].weight=b[i-1];//����Ƶ��ֵΪҶ�ӽڵ��Ȩֵ
		/*cout <<"weignt"<< HT[i].weight;*/
	}
	//��ʼ�������󣬿�ʼ������������
	
	int s1 = 0;
	int s2 = 0;
	for (int i = n + 1; i <= m; i++)//n����ǰΪҶ�ӽڵ㣬��n�Ժ�ʼ�� 
	{
		Select_min(HT, i - 1,s1, s2);//ѡ������Ȩֵ��С�Ľڵ� 
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
{//��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��
	HC = new char* [n + 1];
	char* cd = new char[n];//��ʱ��ű���
	cd[n - 1] = '\0';//��ʱ��Ź��������� 
	int start = 0;
	int c = 0;
	int parent_node = 0;
	for (int i = 1; i <= n; i++)
	{
		start = n - 1;
		c = i;//��Ҷ�ӽڵ㿪ʼ���ݣ����Ŵ�
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
			c = parent_node;//���˫�׽ڵ��Ϊ���ӽڵ�
			parent_node = HT[parent_node].parent;//����Ѱ�������˫�׽ڵ㡱�ĺ��ӽڵ�
		}
		HC[i] = new char[n - start];//Ϊ�������������ռ�
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}
void CharFrequency(char ch[], char a[], int b[], int& j)
{//ͳ�ƴ�Ƶ
	int temp[MAXSIZE] = { 0};
	int i = 0;
	for (int i = 0; i < strlen(ch); i++)//�����Ƶ
	{
		temp[ch[i] - 97+1]++;
	}
	i = 0;
	int z = 0;
	while (i <= 26)//��Ƶ�ʺ��ַ���������a,b
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
{//������������Ĵ洢�ṹ����̬
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
{//���ÿ���ַ��Ĺ���������
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
		j = 0;      //jͳ�Ʋ�ͬ�ַ�������

		CharFrequency(ch, a, b, j);   //ͳ�ƴ�Ƶ
		Sort(a, b, j);     //��ASCII��ð������
		for (i = 0; a[i] != '\0'; i++)   //���ͳ�Ƴ������ַ��ͳ���Ƶ��
		{
			if (a[i + 1] != '\0')
				cout << a[i] << ":" << b[i] << " ";
			else
				cout << a[i] << ":" << b[i] << endl;
		}
		//�����������

		CreateHuffmanTree(HT, i, b);    //�����������HT
		PrintHT(HT);      //������������Ĵ洢�ṹ����̬
		//����������
		HuffmanCode HC;    //�����HC
		CreateHuffmanCode(HT, HC, j);
		PrintHC(HC, a, j);    //���ÿ���ַ��Ĺ���������
		int k;
		for (i = 0; ch[i] != '\0'; i++)    //����������ַ���
		{
			for (k = 0; k < j; k++)
			{
				if (ch[i] == a[k])
					cout << HC[k + 1];
			}
		}
		cout << endl;
		cout << ch << endl;//����������ַ�������������ַ�����ͬ��
	}
	return 0;
}
