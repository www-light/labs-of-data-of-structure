#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAXSIZE 2000
//- - - - - ���Ķ�ʽ˳��洢�ṹ- - - - - 
typedef struct
{
	char* ch;				//���Ƿǿմ����򰴴�������洢��������chΪNULL   
	int length;			//���ĵ�ǰ����   
}HString;

int IndexBF(HString S, HString T, int pos)
{//����ģʽT������S�е�pos���ַ���ʼ��һ�γ��ֵ�λ�á��������ڣ��򷵻�ֵΪ0 
 //���У�T�ǿգ�1��pos��StrLength(S) 
	int i = pos;
	int j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i-1] == T.ch[j-1])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j >= T.length)
	{
		return i - T.length + 1;
	}
	else
	{
		return 0;
	}
}


bool VirusDetection(HString Virus, HString Person)
{//�ж��Ƿ�ƥ�䣬������ԣ�����true�����򷵻�false 
//ģʽƥ���㷨����Index_BF���� 
	HString temp;
	int len = Virus.length;
	for (int i = len, j = 0; j < len, i < 2 * len; i++, j++)
	{
		Virus.ch[i] = Virus.ch[j];
	}//widen  the length of virus
	Virus.length = 2 * len;
	temp.ch = new char[1000];
	temp.length = len;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			temp.ch[j] = Virus.ch[i+j];
		}
		if (IndexBF(Person, temp, 1))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int num, m, flag, i, j; char Vir[1000];
	HString Virus, Person;
	char a[MAXSIZE], b[MAXSIZE];//a���벡����DNA���У�b�����˵�DNA����
	while (cin >> a >> b)
	{
		Virus.ch = new char[1000];
		Person.ch = new char[1000];
		if (strcmp(a, "0") == 0 && strcmp(b, "0") == 0)
			break;
		strcpy(Virus.ch, a);
		strcpy(Person.ch, b);
		Virus.length = strlen(Virus.ch);
		Person.length = strlen(Person.ch);
		if (VirusDetection(Virus, Person))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}//while
	return 0;
}

