/*
    有一个容量为V的背包和若干物品，这些物品有体积w和价值v，要求用这个背包装下价值尽可能多的物品，求该最大价值
*/

#include <stdio.h>
#define INF 0x7fffffff
int max(int a, int b){
    return a > b ? a : b;
}
struct E{
    int w; 
    int v;
}list[101];
int dp[101][1001];  //dp[i][j]表示前i个物品组成的总体积不大于j的最大价值和
int main(){
    int s, n;
    while(scanf("%d%d", &s, &n) != EOF){
        for(int i=1; i<=n; i++){
            scanf("%d%d", &list[i].w, &list[i].v);
        }
        for(int i=0; i<=s; i++){
            dp[0][i] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=s; j>=list[i].w; j--){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-list[i].w] + list[i].v);
            }
            for(int j=list[i].w-1; j>=0; j--){
                dp[i][j] = dp[i-1][j];
            }
        }
        printf("%d\n", dp[n][s]);
    }
    return 0;
}

//0-1背包(背包中有0个该物品或者1个)