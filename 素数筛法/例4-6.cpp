/*
    给定一个数n，要求判断其是否为素数
*/
#include <stdio.h>
#include <math.h>

bool judge(int x){
    if(x <= 1)
        return false;
    int bound = (int)sqrt(x) + 1;   //计算枚举上界，为防止double带来的精度损失，宁愿多枚举一个数
    for(int i=2; i<bound; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}

int main(){
    int x;
    while(scanf("%d", &x) != EOF)
        puts(judge(x) ? "yes" : "no");
    return 0;
}

//依次测试大于1但不大于其平方根的数字能否整数它