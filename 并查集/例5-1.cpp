/*
    求最少还要加多少条边能使图中的任意两节点连通
*/

#include <stdio.h>
using namespace std;
#define N 1000
int Tree[N];
int findRoot(int x){    //找到某个节点所在树的根节点
    if(Tree[x] == -1)
       return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main(){
    int n, m;
    while(scanf("%d", &n) != EOF && n != 0){
        scanf("%d", &m);
        for(int i=1; i<=n; i++)
            Tree[i] = -1;
        while(m-- != 0){
            int a, b;
            scanf("%d%d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if(a != b)
                Tree[a] = b;    //合并两集合
        }
        int ans = 0;
        for(int i=1; i<=n; i++)
            if(Tree[i] == -1)
                ans++;
        printf("%d\n", ans-1);
    }
    return 0;
}

//并查集求图的连通分量个数
