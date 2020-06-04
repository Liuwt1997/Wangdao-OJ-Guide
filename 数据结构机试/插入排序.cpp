#include <stdio.h>

void InsertSort(int a[], int n){
    for(int i=1; i<n; i++){
        int temp = a[i];
        while(i > 0 && temp < a[i-1]){
            a[i] = a[i-1];
            i--;
        }
        a[i] = temp;
    }
}

int main(){
    int a[10] = {2, 4, 1, 5, 7, 9, 10, 22, 3, 8};
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    InsertSort(a, 10);
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}