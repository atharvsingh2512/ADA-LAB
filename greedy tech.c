#include <stdio.h>

// Structure for item
struct Item {
    int weight;
    int profit;
    float ratio;
};

// Function to sort items by profit/weight ratio
void sort(struct Item items[], int n) {

    struct Item temp;

    for(int i = 0; i < n - 1; i++) {

        for(int j = 0; j < n - i - 1; j++) {

            if(items[j].ratio < items[j + 1].ratio) {

                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Fractional Knapsack Function
float fractionalKnapsack(struct Item items[], int n, int capacity) {

    float totalProfit = 0.0;

    // Sort items by ratio
    sort(items, n);

    for(int i = 0; i < n; i++) {

        // If item can be fully included
        if(items[i].weight <= capacity) {

            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else {

            // Take fraction of item
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    return totalProfit;
}

int main() {

    int n = 3;
    int capacity = 50;

    struct Item items[3] = {

        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };

    // Calculate ratio
    for(int i = 0; i < n; i++) {

        items[i].ratio =
        (float)items[i].profit / items[i].weight;
    }

    float maxProfit =
    fractionalKnapsack(items, n, capacity);

    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}