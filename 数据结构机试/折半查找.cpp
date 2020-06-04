#include <stdio.h>

int BinarySearch(int a[], int low, int high, int key){
    while(low <= high){
        int mid = (low + high) / 2;
        if(a[mid] == key)
            return mid;
        else if(a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int A[10] = {-100, 1, 3, 6, 7, 9, 10, 100, 1000, 10000};
    printf("下标为->%d", BinarySearch(A, 0, 9, 1000));
    return 0;
}