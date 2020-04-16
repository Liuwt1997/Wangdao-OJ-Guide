/*
    判断两序列是否为同一二叉排序树
*/

#include <stdio.h>
#include <string.h>

struct BiTree{
   BiTree *lchild, *rchild;
   int data; 
}Tree[110];

int loc;
char str1[25], str2[25];    //将后序与中序得到的字符串连接起来
int size1, size2;   //保存在字符数组中遍历得到的字符个数
char *str;  //当前字符串
int *size;  //当前字符串的字符个数

BiTree *creat(){
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

void postOrder(BiTree *T){
    if(T->lchild != NULL)
        postOrder(T->lchild);
    if(T->rchild != NULL)
        postOrder(T->rchild);
    str[(*size)++] = T->data + '0'; //节点中的字符放入当前字符
}

void inOrder(BiTree *T){
    if(T->lchild != NULL)
        inOrder(T->lchild);
    str[(*size)++] = T->data + '0';
    if(T->rchild != NULL)
        inOrder(T->rchild);
}

BiTree *Insert(BiTree *T, int x){   //插入数字
    if(T == NULL){
        T = creat();
        T->data = x;
        return T;
    }
    else if(x < T->data)
        T->lchild = Insert(T->lchild, x);
    else if(x > T->data)
        T->rchild = Insert(T->rchild, x);
    return T;
}

int main(){
    int n;
    char tmp[12];
    while(scanf("%d", &n) != EOF && n != 0){
        loc = 0;
        BiTree *T = NULL;
        scanf("%s", tmp);
        for(int i=0; tmp[i] != 0; i++){
            T = Insert(T, tmp[i] - '0');
        }
        size1 = 0;
        str = str1;
        size = &size1;
        postOrder(T);
        inOrder(T);
        str1[size1] = 0;
        while(n-- != 0){
            scanf("%s", tmp);
            BiTree *T2 = NULL;
            for(int i=0; tmp[i] != 0; i++){
                T2 = Insert(T2, tmp[i] - '0');
            }
            size2 = 0;
            str = str2;
            size = &size2;
            postOrder(T2);
            inOrder(T2);
            str2[size2] = 0;
            puts(strcmp(str1, str2) == 0 ? "YES" : "NO");
        }
    }
    return 0;
}

//构建二叉排序树，并进行中序+后序（前序）的遍历，比较遍历结果

