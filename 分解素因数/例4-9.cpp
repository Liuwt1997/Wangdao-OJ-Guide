/*
    给定n，a，求最大的k，使n！可以被a^k整除但不能被a^(k+1)整除
*/

#include <stdio.h>
#include <string.h>
bool mark[1010];
int prime[1010];
int primeSize;
void init(){
    for(int i=1; i<=1000; i++){
        mark[i] = false;
    }
    primeSize = 0;
    for(int i=2; i<=1000; i++){
        if(mark[i] == true) continue;   //已被标记过则为非素数，跳过该数
        prime[primeSize++] = i; //未被标记过则得到一个新素数
        if(i >= 1000) continue;
        for(int j=i*i; j<=1000; j+=i){ //将该数的所有倍数标记成非素数
            mark[j] = true;
        }
    }
}

int cnt[1010];  
int cnt2[1010];
int main(){
    int n, a;
    init();
    while(scanf("%d%d", &n, &a) == 2){
        for(int i=0; i<primeSize; i++)
            cnt[i] = cnt2[i] = 0;
        for(int i=0; i<primeSize; i++){
            int temp = n;
            while(temp){
                cnt[i] += temp / prime[i];
                temp /= prime[i];
            }
        }
        int ans = 234233123;
        for(int i=0; i<primeSize; i++){
            while(a % prime[i] == 0){
                cnt2[i]++;
                a /= prime[i];
            }
            if(cnt2[i] == 0)    continue;
            if(cnt[i] / cnt2[i] < ans)
                ans = cnt[i] / cnt2[i];
        }
            printf("%d\n", ans);
        }
    return 0;
}