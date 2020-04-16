/*
    输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出-1）
*/

#include <stdio.h>

int main(){
    int n, x, a[200];
    while(scanf("%d", &n) != EOF){
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        scanf("%d", &x);
        for(int i=0; i<n; i++){
            if(a[i] == x){
                printf("%d", i);
                return 0;
            }
        }
        printf("%d\n", -1);
    }
    return 0;
}