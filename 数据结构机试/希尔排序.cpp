#include <stdio.h>

//数组下标从1开始，a[0]存放的元素无效
void ShellSort(int a[], int n){
    int i, j, dk;
    for(dk=n/2; dk>=1; dk/=2){
        for(i=dk+1; i<=n; i++){
            if(a[i] < a[i-dk]){
                int temp = a[i];
                for(j=i-dk; j>0 && temp<a[j]; j-=dk){
                    a[j+dk] = a[j];
                }
                a[j+dk] = temp;
            }
        }
    }
}

int main(){
    int a[10] = {2, 4, 1, 5, 7, 9, 10, 22, 3, 8};
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    ShellSort(a, 10);
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}