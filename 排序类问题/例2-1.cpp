/*
    对输入的n个数进行排序并输出
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int x, int y){return x > y; }  //降序排序

int main(){
    int n;
    int a[10000];
    while (scanf("%d", &n)!=EOF){
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a+n);   //c++自带的快速排序库函数
        for(int i=0; i<n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");        
        sort(a, a+n, cmp);  //重载的降序排序
        for(int i=0; i<n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}

//重载sort函数（sort函数只能用小于运算符来定序，小者在前）