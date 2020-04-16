/*
    有一个储蓄罐，告知其空时的重量和当前重量，并给定一些钱币的价值和相应的重量，求储蓄罐中最少有多少现金？
*/

#include <stdio.h>
#define INF 0x7fffffff
int min(int a, int b){
    return a < b ? a : b;
}
struct E{
    int w;
    int v;
}list[501];
int dp[10001];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int tmp, s; //储蓄罐空的重量和装满的重量
        scanf("%d%d", &tmp, &s);
        s -= tmp;   //钱币重量
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d%d", &list[i].v, &list[i].w);
        }
        for(int i=0; i<=s; i++){
            dp[i] = INF;
        }
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=list[i].w; j<=s; j++){
                if(dp[j-list[i].w] != INF)
                    dp[j] = min(dp[j], dp[j-list[i].w] + list[i].v);
            }
        }
        if(dp[s] != INF)
            printf("min: %d\n", dp[s]);
        else
            puts("impossible");
    }
    return 0;
}

//完全背包（每个物品的数量可以有任意多）