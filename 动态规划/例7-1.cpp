/*
    N阶楼梯，一次可以走两阶或一阶，问有多少种上楼方式？
*/

#include <stdio.h>
long long F[91];
int main(){
    F[1] = 1;
    F[2] = 2;
    for(int i=3; i<=90; i++)
        F[i] = F[i-1] + F[i-2];
    int n;
    while(scanf("%d", &n) != EOF)
        printf("%lld\n", F[n]);
    return 0;
}