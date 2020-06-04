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
void preOrderTraverse(BiTree Tree){
    if(Tree){
        visit(Tree);
        preOrderTraverse(Tree->lchild);
        preOrderTraverse(Tree->rchild);
    }
}

//非递归
void preOrderTraverseNonrecursion(BiTree Tree){
    if(Tree == nullptr){
        return;
    }
    if(Tree){
        BiTNode *stack[100];
        int top = -1;
        BiTNode *p = Tree;
        stack[++top] = p;   //根节点入栈
        while(top != -1){
            p = stack[top--];   //出栈
            visit(p);

            //先右后左入栈，则出栈时会先访问左孩子
            if(p->rchild){
                stack[++top] = p->rchild;
            }
            if(p->lchild){
                stack[++top] = p->lchild;
            }
        }
    }
}

int main(){
    BiTree tree;
    initTree(&tree);
    preOrderTraverse(tree);
    preOrderTraverseNonrecursion(tree);
}