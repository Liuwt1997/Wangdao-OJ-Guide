/*
    输入两个正整数，求其最大公约数
*/

#include <stdio.h>

int main(){
    int a, b, temp;
    while(scanf("%d%d", &a, &b) != EOF){
        while(b){
            temp = a % b;
            a = b;
            b = temp;
        }
        printf("%d\n", a);
    }
    return 0;
}

//欧几里得算法求最大公约数：全为零则不存在；若a、b其中之一为零，则最大公约数为非零的那个；若都不为零，则使新a=b，新b=a%b，然后重复该过程求得最大公约数