/*
    对输入的n个数进行排序并输出
*/
#include <stdio.h>

void BubbleSort(int a[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(){
    int n, a[100];
    while(scanf("%d", &n)!=EOF){    //成功完成输入并对n赋值，则scanf函数的返回值为1，直到末尾end of file
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
    }
    BubbleSort(a, n);
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    return 0;
}

//冒泡排序