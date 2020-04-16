/*
    输入两个不超过整型定义的非负十进制数A和B，输出A+B的m进制数
*/

#include <stdio.h>

int main(){
    long long a, b; //两int数字的和可能会超出int所能表示的最大值
    int m;
    while(scanf("%d", &m) != EOF){
        if(m == 0)  break;
        scanf("%lld%lld", &a, &b);
        a = a + b;
        int ans[50], size = 0;  //ans保存转换得到的各位数字，size表示数字个数
        do{ //至少执行一次，保证数字0正常工作
            ans[size++] = a % m;
            a /= m;
        }while(a != 0);
        for(int i=size-1; i>=0; i--){
            printf("%d", ans[i]);   //打印各位数字
        }
        printf("\n");
    }
    return 0;
}

//求和并转换成m进制数输出