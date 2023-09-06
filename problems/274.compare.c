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
    srand(time(0));

    // Fill the array with random numbers
    for(int i = 0; i < length; i++) {
        arr[i] = rand() % 10000;  // generate numbers in the range 0-99
    }

    return arr;
}

int cmp(int *a, int *b)
{
    return *a - *b;
}

int hIndex(int *citations, int citationsSize)
 {
    qsort(citations, citationsSize, sizeof(int), cmp);
    int h = 0, i = citationsSize - 1;
    while (i >= 0 && citations[i] > h) {
        h++;
        i--;
    }
    return h;
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