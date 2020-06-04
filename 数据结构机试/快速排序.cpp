#include <stdio.h>

int Partition(int a[], int low, int high){
    int pivot = a[low];
    while(low < high){
        while(low < high && a[high] > pivot)    --high;
        a[low] = a[high];
        while(low < high && a[low] < pivot) ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void QUickSort(int a[], int low, int high){
    if(low < high){
        int par = Partition(a, low, high);
        QUickSort(a, par + 1, high);
        QUickSort(a, low, par - 1);
    }
}

int main(){
    int a[10] = {2, 4, 1, 5, 7, 9, 10, 22, 3, 8};
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    QUickSort(a, 0, 9);
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
