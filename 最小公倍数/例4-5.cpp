/*
    给定两个正整数，计算这两个数的最小公倍数
*/

#include <stdio.h>

int main(){
    int a, b, temp, c;
    while(scanf("%d%d", &a, &b) != EOF){
        c = a * b;
        while(b){
            temp = a % b;
            a = b;
            b = temp;
        }
    printf("%d\n", c/a);
    }
    return 0;
}


//最小公倍数=a*b/最大公约数