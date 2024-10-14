#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to compare two items based on value/weight ratio (for qsort)
int compare(const void* a, const void* b) {
    double r1 = ((struct Item*)a)->value / (double)((struct Item*)a)->weight;
    double r2 = ((struct Item*)b)->value / (double)((struct Item*)b)->weight;
    return (r2 > r1) - (r2 < r1);  // Descending order
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int W, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);  // Sort items by ratio
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (W >= items[i].weight) {  // Take the whole item
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {  // Take the fraction of the item that fits
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;  // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int W = 50;  // Knapsack capacity
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);

    double maxValue = fractionalKnapsack(W, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
