#include <stdio.h>

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void SelectSort(int a[], int n){
    int i, j, min;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(min != i){
            swap(&a[i], &a[min]);
        }
    }
}

int main(){
    int a[10] = {2, 4, 1, 5, 7, 9, 10, 22, 3, 8};
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    SelectSort(a, 10);
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}