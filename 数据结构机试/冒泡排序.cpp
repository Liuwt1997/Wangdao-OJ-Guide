#include <stdio.h>

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void BubbleSort(int a[], int n){
    int flag;   //这一趟排序是否发生元素交换
    for(int i=0; i<n-1; i++){
        flag = false;
        for(int j=n-1; j>i; j--){
            if(a[j-1] > a[j]){
                swap(&a[j-1], &a[j]);
                flag = true;
            }
        }
        if(flag == false)   //这一趟未发生元素交换，已经有序
            return;
    }
}

int main(){
    int a[10] = {2, 4, 1, 5, 7, 9, 10, 22, 3, 8};
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    BubbleSort(a, 10);
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}