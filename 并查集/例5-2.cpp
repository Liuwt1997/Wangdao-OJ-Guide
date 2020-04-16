/*
    有N对好友，若A与B使朋友，B与C是朋友，则认为A与C是朋友。找出一个人数最多的集合，该集合中任意两人之间都是朋友，输出该最大人数
*/

#include <stdio.h>
using namespace std;
#define N 10000001
int Tree[N];
int findRoot(int x){
    if(Tree[x] == -1)
        return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int sum[N]; //以结点i为根的树的结点个数


int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i=1; i<N; i++){
            Tree[i] = -1;
            sum[i] = 1;
        }
        while(n-- != 0){
            int a, b;
            scanf("%d%d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if(a != b){
                Tree[a] = b;
                sum[b] += sum[a];
            }
        }
        int ans = 1;
        for(int i=1; i<=N; i++)
            if(Tree[i] == -1 && sum[i] > ans)
                ans = sum[i];
        printf("%d\n", ans);
    }
    return 0;
}



//并查集+标记元素个数