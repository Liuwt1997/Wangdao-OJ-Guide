/*
    输入一个整数n，要求输出所有从1到这个整数之间个位为1的素数，如果没有则输出-1
*/

#include <stdio.h>
int prime[10000];   //保存所得素数
int primeSize;  //得到的素数个数
bool mark[10001];    //标记是否为非素数
void init(){
    for(int i=1; i<=10000; i++){
        mark[i] = false;
    }
    primeSize = 0;
    for(int i=2; i<=10000; i++){
        if(mark[i] == true) continue;   //已被标记过则为非素数，跳过该数
        prime[primeSize++] = i; //未被标记过则得到一个新素数
        for(int j=i*i; j<=10000; j+=i){ //将该数的所有倍数标记成非素数
            mark[j] = true;
        }
    }
}

int main(){
    init();
    int n;
    while(scanf("%d", &n) != EOF){
        bool isOutput = false;  
        for(int i=0; i<primeSize; i++){
            if(prime[i] < n && prime[i] % 10 == 1){ 
                if(isOutput == false){  
                    isOutput == true;
                    printf("%d",prime[i]);  //第一个数字前不加空格
                }
                else printf(" %d",prime[i]);
            }
        }
        if(isOutput == false){
            printf("-1\n");
        }
        else printf("\n");
    }
    return 0;
}

//先预处理区间内的所有素数，再依次比较输出