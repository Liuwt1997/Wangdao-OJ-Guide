/*
    给前序和中序，求后序
*/

#include <stdio.h>
#include <string.h>

struct BiTree {
    BiTree *lchild, *rchild;
    char c;
}Tree[50];

int loc;    //已经分配的节点个数
char strpre[30], strmid[30];    //保存前序和中序遍历结果字符串

BiTree *creat() {   //申请一个结点
    Tree[loc].lchild = Tree[loc].rchild = NULL; 
    return &Tree[loc++];    //返回指向该结点的指针
}

void postOrder(BiTree *T){  //后序遍历
    if(T->lchild != NULL)
        postOrder(T->lchild);
    if(T->rchild != NULL)
        postOrder(T->rchild);
    printf("%c", T->c);
}

BiTree *build(int s1, int e1, int s2, int e2){  //由前序和中序还原二叉树
    BiTree* ret = creat();  //根节点
    ret->c = strpre[s1];    //根节点为前序中第一个字符
    int rootIdx;
    for(int i=s2; i<=e2; i++){  //查找根节点字符在中序中的位置
        if(strmid[i] == strpre[s1]){
            rootIdx = i;
            break;
        }
    }
    if(rootIdx != s2)  //左子树不为空
        ret->lchild = build(s1+1, s1+(rootIdx-s2), s2, rootIdx-1);
    if(rootIdx != e2)  //右子树不为空
        ret->rchild = build(s1+(rootIdx-s2)+1, e1, rootIdx+1, e2);
    return ret;
}

int main(){
    while(scanf("%s", strpre) != EOF){
        scanf("%s", strmid);
        loc = 0;
        int L1 = strlen(strpre);
        int L2 = strlen(strmid);
        BiTree *T = build(0, L1-1, 0, L2-1);
        postOrder(T);
        printf("\n");
    }
    return 0;
}

//二叉树的建立（根据遍历结果还原二叉树）、二叉树的遍历
