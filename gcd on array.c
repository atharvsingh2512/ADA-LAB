#include <stdio.h>

// Function to find GCD of two numbers
int gcd(int a, int b) {

    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

// Function to find GCD of array
int gcdArray(int arr[], int n) {

    int result = arr[0];

    for(int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
    }

    return result;
}

int main() {

    int arr[] = {24, 36, 60};
    int n = 3;

    printf("GCD of array = %d", gcdArray(arr, n));

    return 0;
}