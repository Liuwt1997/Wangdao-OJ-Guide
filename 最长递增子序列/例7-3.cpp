/*
    一种导弹拦截系统第一发炮弹能够达到任意的高度，但是以后每一发炮弹都不能高于前一发的高度。问这套系统最多能拦截多少导弹
*/

#include <stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}
int list[26];   //导弹
int dp[26]; //保存以第i个导弹结尾的最长不增子序列长度
int main() {
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i=1; i<=n; i++){
            scanf("%d", &list[i]);
        }
        for(int i=1; i<=n; i++){
            int tmax = 1;
            for(int j=1; j<i; j++){
                if(list[j] >= list[i]){
                    tmax = max(tmax, dp[j] + 1);
                }
            }
            dp[i] = tmax;
        }
        int ans = 1;
        for(int i=1; i<=n; i++){    //找到以每一个元素结尾的最长不增子序列中的最大值
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}



//即求最长不增子序列