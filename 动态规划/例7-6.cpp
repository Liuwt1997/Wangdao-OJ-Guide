/*
    有一堆柑橘重量为0到2000，总重量不大于2000。从中取出两堆放在扁担的两头且两头的重量相等，问符合条件的每堆重量最大为多少？没有符合条件的分堆方式则输出-1
*/

#include <stdio.h>
#define OFFSET 2000 //偏移值，重量差可能为负
int dp[101][4001];  //dp[i][j]为前i个柑橘被选择后，第一堆比第二堆重j时，两堆的最大重量和
int list[101];  //当前加入柑橘重量为list[i]
#define INF 0x7fffffff
int main(){
    int T;
    int cas = 0;
    scanf("%d", &T);
    while(T-- != 0){
        int n;
        scanf("%d", &n);
        bool HaveZero = false;  //重量为0的柑橘
        int cnt = 0;
        for(int i=1; i<=n; i++){
            scanf("%d", &list[++cnt]);
            if(list[cnt] == 0){ //记录存在重量为0的柑橘并去掉它
                cnt--;
                HaveZero = true;
            }
        }
        n = cnt;
        for(int i=-2000; i<=2000; i++){
            dp[0][i+OFFSET] = -INF;
        }
        dp[0][0+OFFSET] = 0;
        for(int i=1; i<=n; i++){
            for(int j=-2000; j<=2000; j++){ //遍历所有可能的重量差
                int tmp1 = -INF, tmp2 = -INF;   //当前柑橘放在第一堆或第二堆时转移得来的新值
                if(j + list[i] <= 2000 && dp[i-1][j+list[i]+OFFSET] != -INF)   //状态由第一堆转移而来
                    tmp1 = dp[i-1][j+list[i]+OFFSET] + list[i];
                if(j - list[i] >= -2000 && dp[i-1][j-list[i]+OFFSET] != -INF)   //状态由第二堆转移而来
                    tmp2 = dp[i-1][j-list[i]+OFFSET] + list[i];
                if(tmp1 < tmp2) //两者较大值保存至tmp1
                    tmp1 = tmp2;
                if(tmp1 < dp[i-1][j+OFFSET])    //与不放入任何堆做比较
                    tmp1 = dp[i-1][j+OFFSET];
                dp[i][j+OFFSET] = tmp1; //保存为三个状态中的最大值
            }
        }
        printf("CASE %d:", ++cas);
        if(dp[n][0+OFFSET] == 0)
            puts(HaveZero == true ? "0" : "-1");    //存在重量为0的柑橘时可组成两堆0
        else
            printf("%d\n", dp[n][0+OFFSET] / 2);
    }
    return 0;
}