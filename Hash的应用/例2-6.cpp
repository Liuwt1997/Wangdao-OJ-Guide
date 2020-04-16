/*
    给n个整数，按从大到小的顺序输出其中前m大的数
*/

#include <stdio.h>

#define OFFSET 500000   //数组非负，加偏移量表示实际数字与数组下标之间的对应关系
int  Hash[1000001];    //大内存空间在函数体外定义

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i=-500000; i<=500000; i++){
            Hash[i+OFFSET] = 0; //初始化，均标记为未出现
        }
        for(int i=0; i<n; i++){
            int x;
            scanf("%d", &x);
            Hash[x+OFFSET] = 1; //标记为出现
        }
        for(int i=500000; i>=-500000; i--){ //降序遍历前m大的数
            if(Hash[i+OFFSET] == 1){
                printf("%d", i);
                m--;
                if(m != 0){
                    printf(" ");    //注意输出格式
                }
                else{               
                    printf("\n"); 
                    break;  //输出完毕退出 
                }
            }
        }
    }
    return 0;
}

//数字量庞大，不能用排序解决；输入数字在有限区间，与数组下标对应；负数加偏移量映射到数组