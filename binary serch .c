#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {

    while(low <= high) {

        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(key < arr[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int main() {

    int arr[] = {10, 20, 30, 40, 50};
    int key = 40;
    int n = 5;

    int result = binarySearch(arr, 0, n - 1, key);

    if(result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}