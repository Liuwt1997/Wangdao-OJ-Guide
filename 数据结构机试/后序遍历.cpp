#include <cstdio>
#include <cstdlib>

typedef struct BiTNode{
    struct BiTNode *lchild;
    struct BiTNode *rchild;
    int data;
}BiTNode, *BiTree;

//初始化一棵树
void initTree(BiTree *T) {
    *T = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->rchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->lchild->rchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}

void visit(BiTNode *node){
    printf("%d", node->data);
}

void PostOrderTraverse(BiTree Tree){
    if(Tree){
        PostOrderTraverse(Tree->lchild);
        PostOrderTraverse(Tree->rchild);
        visit(Tree);
    }
}

//非递归
void PostOrderTraverseNonrecursion(BiTree Tree){
    if(Tree == nullptr){
        return;
    }
    BiTNode *stack1[100];
    BiTNode *stack2[100];
    int top1 = -1, top2 = -1;
    BiTNode *p = Tree;  //根节点
    stack1[++top1] = p;
    while (top1 != -1) {
        p = stack1[top1--];
        stack2[top2++] = p;//栈二是为了保存每遍历顺序的逆序的栈

        //先左后右，右先弹出栈1 然后先进栈2 后出栈2 所以是左 右 根的顺序
        if (p->lchild) {
            stack1[++top1] = p->lchild;
        }
        if (p->rchild) {
            stack1[++top1] = p->rchild;
        }
    }
    //遍历栈二 即访问顺序
    while (top2 != -1) {
        p = stack2[--top2];
        visit(p);
    }
}

int main(){
    BiTree Tree;
    initTree(&Tree);
    PostOrderTraverse(Tree);
    PostOrderTraverseNonrecursion(Tree);
}