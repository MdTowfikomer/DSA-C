#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int arr[], int low, int high){
    int pivot = arr[high];

    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i + 1;
}


void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partion(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);

    }
}

void printArr(int arr[], int n){
    for(int i= 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}



int main(){
    int arr[] = {24, 9, 29, 14, 19, 27};
    int n = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, n-1);

    printArr(arr, n);

}
