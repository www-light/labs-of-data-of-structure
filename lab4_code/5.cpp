#include <iostream>
#include <string.h>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

BiTree CreateBiTree(int& pos, char* str)//�����������ڵ�
{// ������������,�Ƚ������ڵ㣬�ٽ����������ٽ���������
    char ch = str[pos];
    pos++;
    if (ch == '0') return NULL;
    BiTree node = new BiTNode();//���յ���������������
    node->data = ch;
    node->lchild = CreateBiTree(pos, str);
    node->rchild = CreateBiTree(pos, str);
    return node;//��󷵻ص�Ϊ���ڵ�
}
int Width(BiTree T)
{// �������T�����
    //ʹ�ò��������������������
    int max_wide = 0;
    int level = 0;//����ڵ���
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        BiTree queue[1000];//�洢������ָ��Ķ���
        int front = 0;int  rear = 0;
        queue[rear++] = T;
        while (front<rear)//ֱ������Ϊ��
        {
            level = rear - front;//����ڵ���
            if (level > max_wide)//������������һ��ڵ�������max_wide
            {
                max_wide = level;
            }
            for (int i = 0; i < level; i++)//��������ڵ�ĺ���
            {
                BiTree node = queue[front++];//��һ������ڵ�,�ͳ���
                if (node->lchild!=NULL)
                {
                    queue[rear++] = node->lchild;//�ýڵ�����ӽ���
                }
                if (node->rchild!=NULL)
                {
                    queue[rear++] = node->rchild;//�ýڵ��Һ��ӽ���
                }
            }
            //cout << 2;
        }
    }
    return max_wide;
}
int main()
{
    char str[1000];
    while (cin >> str)
    {
        if (strcmp(str, "0") == 0) break;
        int pos = 0;                         // ����ַ�������λ��
        BiTree root = CreateBiTree(pos, str);
        cout << Width(root) << endl;
    }
    return 0;
}