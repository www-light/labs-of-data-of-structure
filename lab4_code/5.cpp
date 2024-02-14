#include <iostream>
#include <string.h>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

BiTree CreateBiTree(int& pos, char* str)//参数不给根节点
{// 先序建立二叉树,先建立根节点，再建立左子树再建立右子树
    char ch = str[pos];
    pos++;
    if (ch == '0') return NULL;
    BiTree node = new BiTNode();//按照的是先序建立二叉树
    node->data = ch;
    node->lchild = CreateBiTree(pos, str);
    node->rchild = CreateBiTree(pos, str);
    return node;//最后返回的为根节点
}
int Width(BiTree T)
{// 求二叉树T最大宽度
    //使用层序遍历来求二叉树最大宽度
    int max_wide = 0;
    int level = 0;//当层节点数
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        BiTree queue[1000];//存储二叉树指针的队列
        int front = 0;int  rear = 0;
        queue[rear++] = T;
        while (front<rear)//直到队列为空
        {
            level = rear - front;//计算节点数
            if (level > max_wide)//如果队列里的这一层节点数大于max_wide
            {
                max_wide = level;
            }
            for (int i = 0; i < level; i++)//遍历当层节点的孩子
            {
                BiTree node = queue[front++];//给一个当层节点,就出队
                if (node->lchild!=NULL)
                {
                    queue[rear++] = node->lchild;//该节点的左孩子进队
                }
                if (node->rchild!=NULL)
                {
                    queue[rear++] = node->rchild;//该节点右孩子进队
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
        int pos = 0;                         // 标记字符串处理位置
        BiTree root = CreateBiTree(pos, str);
        cout << Width(root) << endl;
    }
    return 0;
}