#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two numbers
void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {

        if(arr[j] < pivot) {

            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {

    if(low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int n, i;
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generate random numbers
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    start = clock();

    quickSort(arr, 0, n - 1);

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Elements:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken = %f seconds\n", cpu_time);

    return 0;
}