/*
    求正整数N的质因数的个数（相同的质因数需要重复计算）
*/

#include <stdio.h>
bool mark[100001];
int prime[100001];
int primeSize;
void init(){
    for(int i=1; i<=100000; i++){
        mark[i] = false;
    }
    primeSize = 0;
    for(int i=2; i<=100000; i++){
        if(mark[i] == true) continue;   //已被标记过则为非素数，跳过该数
        prime[primeSize++] = i; //未被标记过则得到一个新素数
        if(i >= 1000) continue;
        for(int j=i*i; j<=100000; j+=i){ //将该数的所有倍数标记成非素数
            mark[j] = true;
        }
    }
}

int main(){
    init();
    int n;
    while(scanf("%d", &n) != EOF){
        int ansPrime[30];   //分解出的质因数
        int ansSize = 0;    //分解出的质因数的个数
        int ansNum[30]; //质因数对应的幂指数
        for(int i=0; i<primeSize; i++){
            if(n % prime[i] == 0){
                ansPrime[ansSize] = prime[i];
                ansNum[ansSize] = 0;
                while(n % prime[i] == 0){
                    ansNum[ansSize]++;
                    n /= prime[i];
                }
                ansSize++;
                if(n == 1) break;
            }
        }
        if(n != 1){
            ansPrime[ansSize] = n;
            ansNum[ansSize++] = 1;
        }
        int ans = 0;
        for(int i=0; i<ansSize; i++){
            ans += ansNum[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}

//求出区间内的所有素数，依次测试这些素数能否整除N，若能则代表为N的一个质因数；不断用N除以该素数，直到不能再整除为止，统计其幂指数