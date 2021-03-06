/*
    求最小生成树及权值和
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 101
int Tree[N];
int findRoot(int x){
    if(Tree[x] == -1)
        return x;
    else{
        int tmp = (findRoot(Tree[x]));
        Tree[x] = tmp;
        return tmp;
    }
}

struct Edge{
    int a, b, cost;
    bool operator < (const Edge &A) const{  //使边按照权值从小到大排列
        return cost < A.cost;
    }
}edge[6000];

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        for(int i=1; i<=n*(n-1)/2; i++)
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
        sort(edge+1, edge+1+n*(n-1)/2);
        for(int i=1; i<=n; i++)
            Tree[i] = -1;
        int ans = 0;
        for(int i=1; i<=n*(n-1)/2; i++){
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if(a != b){
                Tree[a] = b;
                ans += edge[i].cost;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

