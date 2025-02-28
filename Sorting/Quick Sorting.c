#include <stdio.h>

// Function prototypes
void quick(int arr[], int left, int right);
int partition(int arr[], int left, int right);

int main() {
    int arr[10], i;
    printf("-Enter 10 elements-\n");

    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Call the quicksort function
    quick(arr, 0, 9);

    printf("Sorted array: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Function to perform the quicksort
void quick(int arr[], int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        quick(arr, left, p - 1);
        quick(arr, p + 1, right);
    }
}

// Function to partition the array
int partition(int arr[], int left, int right) {
    int pivotpt = (left + right) / 2;
    int pivot = arr[pivotpt];
    
    // Swap pivot with the rightmost element
    int temp = arr[pivotpt];
    arr[pivotpt] = arr[right];
    arr[right] = temp;

    pivotpt = right;
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[right] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}
