/*
    n件物品，随便搬2*k件，每搬一次的疲劳度和左右手物品的重量差的平方成正比，如左手3，右手6，则疲劳度为(6-3)^2 = 9。问搬完这2*k件物品后的最佳状态是怎样的？
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff
int list[2001]; //每个物品重量
int dp[1001][2001]; //每个状态
int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF){
        for(int i=1; i<=n; i++){
            scanf("%d", &list[i]);
        }
        sort(list + 1, list + 1 + n);
        for(int i=1; i<=n; i++)
            dp[0][i] = 0;
        for(int i=1; i<=k; i++){
            for(int j=2*i; j<=n; j++){
                if(j > 2 * i)   //最后两个物品可以不配对
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = INF; //最后两件物品必须配对
                if(dp[i][j] > dp[i-1][j-2] + (list[j] - list[j-1]) * (list[j] - list[j-1]))
                    dp[i][j] = dp[i-1][j-2] + (list[j] - list[j-1]) * (list[j] - list[j-1]);
            }
        }
        printf("%d\n", dp[k][n]);
    }
    return 0;
}