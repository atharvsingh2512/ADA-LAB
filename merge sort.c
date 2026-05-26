#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high) {

    int i, j, k;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    // Copy data to temp arrays
    for(i = 0; i < n1; i++)
        L[i] = arr[low + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    // Merge the temp arrays
    while(i < n1 && j < n2) {

        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {

    if(low < high) {

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n - 1);

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted elements:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken = %f seconds\n", cpu_time);

    return 0;
}