/*
    求A^B的最后三位数表示的整数
*/

#include <stdio.h>
int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        if(a == 0 && b == 0)    break;
        int ans = 1;
        while(b != 0){
            if(b % 2 == 1){
                ans *= a;
                ans %= 1000;    //取后三位
            }
            b /= 2;
            a *= a; //a的多次方
            a %= 1000;
        }
        printf("%d\n", ans);
    }
    return 0;
}

//计算过程的所有中间结果仅保存后三位数