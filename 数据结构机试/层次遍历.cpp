#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

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

void LevelOrderTraverse(BiTree Tree){
    queue<BiTNode *> Q;
    if(Tree){
        Q.push(Tree);   //根节点入队列
    }
    while(!Q.empty()){
        BiTNode *pNode = Q.front(); //取得队首
        Q.pop();    //删除队列首个元素
        visit(pNode);
        if(pNode->lchild){
            Q.push(pNode->lchild);
        }
        if(pNode->rchild){
            Q.push(pNode->rchild);
        }
    }
}

int main(){
    BiTree tree;
    initTree(&tree);
    LevelOrderTraverse(tree);
}