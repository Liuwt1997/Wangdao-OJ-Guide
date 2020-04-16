/*
    输入一个高度h，输出一个高为h，上底边为h的梯形
*/

#include <stdio.h>

int main(){
    int h;
    while(scanf("%d", &h) != EOF){
        for(int i=1; i<=h; i++){    //h行
            for(int j=1; j<=3*h-2; j++){    //(3h-2)列
                if(j<=2*h-2*i){
                    printf(" ");
                }
                else{
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

//找行和列，空格和*之间的规律