#include <stdio.h>

int b[10];

void Merge(int a[], int low, int mid, int high){
    int i, j, k;
    for(k=low; k<=high; k++){
        b[k] = a[k];    //复制到b中
    }
    for(i=low, j=mid+1, k=i; i<=mid && j<=high; k++){
        if(b[i] <= b[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];
    }
    while(i <= mid)
        a[k++] = b[i++];
    while(j <= high)
        a[k++] = b[j++];
}

void MergeSort(int a[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge(a, low, mid, high);
    }
}

int main(){
    int a[10] = {2, 4, 1, 5, 7, 9, 10, 22, 3, 8};
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    MergeSort(a, 0, 9);
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}