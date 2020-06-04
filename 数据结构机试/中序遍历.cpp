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

//递归
void InOrderTraverse(BiTree Tree){
    if(Tree){
        InOrderTraverse(Tree->lchild);
        visit(Tree);
        InOrderTraverse(Tree->rchild);
    }
}

/*
非递归：先扫描根结点的所有左结点并将它们一一进栈，然后出栈一个结点*p并访问
它，扫描该结点右孩子结点将其进栈，再扫描右孩子的所有左结点一一进栈，直到栈
空为止。
*/
void InOrderTraverseNonrecursion(BiTree Tree){
    if(Tree == nullptr){
        return;
    }
    BiTNode *stack[100];
    int top = -1;
    BiTNode *p = Tree;
    while(p != nullptr || top != -1){
        if(p){
            stack[++top] = p;
            p = p->lchild;
        } else{
            p = stack[top--];
            visit(p);
            p = p->rchild;
        }
    }
}

int main(){
    BiTree tree;
    initTree(&tree);
    InOrderTraverse(tree);
    InOrderTraverseNonrecursion(tree);
}