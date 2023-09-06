#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateRandomArray(int length) {
    // Allocate memory for the array
    int* arr = (int*)malloc(length * sizeof(int));

    if(arr == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Seed the random number generator
    // srand(time(0));
    srand(0);

    // Fill the array with random numbers
    for(int i = 0; i < length; i++) {
        arr[i] = rand() % 10000;  // generate numbers in the range 0-99
    }

    return arr;
}

// #include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int idx) {
    int largest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != idx) {
        swap(&arr[idx], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--)
        heapify(arr, n, i);
}

int heapSort(int arr[], int n) {
    buildHeap(arr, n);

    for (int i=n-1; i>=0; i--) {
        if (arr[0] < n-i) return n-i-1;

        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
    return n;
}


int hIndex(int* citations, int citationsSize){
    int rst;
    // buildHeap(citations, citationsSize);
    return heapSort(citations, citationsSize);

}

void printArray(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

#define N 2000000
int main(){
	int *a;
    int hi;
    clock_t start, end;
    long cpu_time_used;

    a = generateRandomArray(N);
    // printArray(a, N);
    start = clock();
    hi = hIndex(a, N);
    end = clock();
    cpu_time_used = ((long) (end - start)); // / CLOCKS_PER_SEC;

    printf("hIndex=%d, time cost = %ld\n", hi, cpu_time_used);

}