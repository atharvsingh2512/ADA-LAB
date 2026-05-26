#include <stdio.h>
#include <stdbool.h>

#define LEFT 0
#define RIGHT 1

// Find largest mobile element
int getMobile(int perm[], int dir[], int n) {

    int mobilePrev = 0;
    int mobileIndex = -1;

    for(int i = 0; i < n; i++) {

        if(dir[i] == LEFT && i != 0) {
            if(perm[i] > perm[i - 1] && perm[i] > mobilePrev) {
                mobilePrev = perm[i];
                mobileIndex = i;
            }
        }

        if(dir[i] == RIGHT && i != n - 1) {
            if(perm[i] > perm[i + 1] && perm[i] > mobilePrev) {
                mobilePrev = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Print permutation
void printPermutation(int perm[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Johnson–Trotter algorithm
void johnsonTrotter(int n) {

    int perm[n];
    int dir[n];

    // Initialize
    for(int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while(true) {

        int mobileIndex = getMobile(perm, dir, n);

        if(mobileIndex == -1)
            break;

        // swap based on direction
        if(dir[mobileIndex] == LEFT) {
            swap(&perm[mobileIndex], &perm[mobileIndex - 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex - 1]);
            mobileIndex--;
        }
        else {
            swap(&perm[mobileIndex], &perm[mobileIndex + 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex + 1]);
            mobileIndex++;
        }

        // reverse direction of larger elements
        for(int i = 0; i < n; i++) {
            if(perm[i] > perm[mobileIndex]) {
                dir[i] = (dir[i] == LEFT) ? RIGHT : LEFT;
            }
        }

        printPermutation(perm, n);
    }
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Permutations:\n");

    johnsonTrotter(n);

    return 0;
}