//Quicksort using recursive and iterative methods

#include <iostream>

using namespace std;

// Utility function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function used by both recursive and iterative versions
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// RECURSIVE QUICK SORT 
void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSortRecursive(arr, low, pi - 1);  // Left side
        quickSortRecursive(arr, pi + 1, high); // Right side
    }
}

// ITERATIVE QUICK SORT 
void quickSortIterative(int arr[], int low, int high) {
    // Create an auxiliary stack array to store low and high indices
    int stack[high - low + 1];
    int top = -1;

    // Push initial values of low and high to stack
    stack[++top] = low;
    stack[++top] = high;

    // Keep popping from stack while it is not empty
    while (top >= 0) {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];

        // Set pivot element at its correct position
        int pi = partition(arr, low, high);

        // If there are elements on the left side of pivot, push to stack
        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        // If there are elements on the right side of pivot, push to stack
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int data1[] = {4, 2, 8, 5, 1, 9, 6};
    int n1 = sizeof(data1) / sizeof(data1[0]);
    
    cout << "Original Array 1: ";
    printArray(data1, n1);
    
    quickSortRecursive(data1, 0, n1 - 1);
    cout << "Sorted with Recursive Quick Sort: ";
    printArray(data1, n1);

    cout << "---------------------------------------" << endl;

    int data2[] = {23, 12, 99, 4, 15, 3, 8};
    int n2 = sizeof(data2) / sizeof(data2[0]);
    
    cout << "Original Array 2: ";
    printArray(data2, n2);
    
    quickSortIterative(data2, 0, n2 - 1);
    cout << "Sorted with Iterative Quick Sort: ";
    printArray(data2, n2);

    return 0;
}