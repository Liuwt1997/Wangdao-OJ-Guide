/*
    输入一个正整数N，输出N的阶乘(0<=N<=1000)
*/

#include <stdio.h>
#include <string.h>
struct bitInteger{
    int digit[1000];
    int size;
    void init(){
        for(int i=0; i<1000; i++)
            digit[i] = 0;
        size = 0;
    }
    void set(int x){    //小的整数设置大的高精度整数
        init();
        do{
            digit[size++] = x % 10000;
            x /= 10000;
        }while(x != 0);
    }
    void output(){
        for(int i=size-1; i>=0; i--){
            if(i != size - 1)
                printf("%04d", digit[i]);
            else
                printf("%d", digit[i]);
        }
        printf("\n");
    }
    bitInteger operator * (int x) const {
        bitInteger ret;
        ret.init();
        int carry = 0;
        for(int i=0; i<size; i++){
            int tmp = x * digit[i] + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ret.digit[ret.size++] = tmp;
        }
        if(carry != 0)
            ret.digit[ret.size++] = carry;
        return ret;
    }
}a;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        a.init();
        a.set(1);
        for(int i=1; i<=n; i++)
            a = a * i;
        a.output();
    }
    return 0;
}

//高精度乘法