#include <stdio.h>

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

//第一个元素为a[1]
void AdjustDown(int a[], int k, int n){
    a[0] = a[k];    //暂存
    for(int i=2*k; i<=n; i*=2){
        if(i<n && a[i]<a[i+1])
            i++;    //看看谁孩子大
        if(a[0] >= a[i])    break;
        else{
            a[k] = a[i];
            k = i;  //以便下次调整
        }
    }
    a[k] = a[0];
}

void BuildMaxHeap(int a[], int n){
    for(int i=n/2; i>0; i--){
        AdjustDown(a, i, n);
    }
}

void HeapSort(int a[], int n){
    BuildMaxHeap(a, n); //建立大根堆
    for(int i=n; i>1; i--){
        swap(&a[i], &a[1]);   //和堆底元素交换
        AdjustDown(a, 1, i-1);
    }
}


int main(){
    int a[10] = {2, 4, 1, 5, 7, 9, 10, 22, 3, 8};
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    HeapSort(a, 10);
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}