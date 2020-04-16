/*
    输入两个数，如123*45=1*4+1*5+2*4+2*5+3*4+3*5，求运算结果
*/

#include <stdio.h>
int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        int buf1[20], buf2[20], size1 = 0, size2 = 0;   //buf保存两个整数拆出来的数字，数量为size
        while(a != 0){
            buf1[size1++] = a % 10;
            a /= 10;
        }
        while(b != 0){
            buf2[size2++] = b % 10;
            b /= 10;
        }
        int ans = 0;
        for(int i=0; i<size1; i++){
            for(int j=0; j<size2; j++){
                ans += buf1[i] * buf2[j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

//拆开两整数各个数位上的数字（不断 x%10 取个位数，再x/10右移），再将这些数字两两相乘后求和