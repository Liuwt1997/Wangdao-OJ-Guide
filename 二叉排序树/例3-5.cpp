/*
    建立二叉排序树，并进行前中后序遍历
*/

#include <stdio.h>
#include <string.h>

struct BiTree{
    BiTree *lchild, *rchild;
    int data;
}Tree[101];

int loc;

BiTree *creat(){
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

void postOrder(BiTree *T){
    if(T->lchild != NULL)
        postOrder(T->lchild);
    if(T->rchild != NULL)
        postOrder(T->rchild);
    printf("%d", T->data);
}

void inOrder(BiTree *T){
    if(T->lchild != NULL)
        inOrder(T->lchild);
    printf("%d", T->data);
    if(T->rchild != NULL)
        inOrder(T->rchild);
}

void preOrder(BiTree *T){
    printf("%d", T->data);
    if(T->lchild != NULL)
        preOrder(T->lchild);
    if(T->rchild != NULL)
        preOrder(T->rchild);
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
    while(scanf("%d", &n) != EOF){
        loc = 0;
        BiTree *T = NULL;   //根节点
        for(int i=0; i<n; i++){
            int x;
            scanf("%d", &x);
            T = Insert(T, x);   
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}