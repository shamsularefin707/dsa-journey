//Bubble Sort using loops and recursion
#include <iostream>

using namespace std;

// Utility function to swap two elements
void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// ---- ITERATIVE BUBBLE SORT ----
void bubbleSortIterative(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Optimization to stop early if array is already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapElements(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

// ---- RECURSIVE BUBBLE SORT ----
void bubbleSortRecursive(int arr[], int n) {
    // Base case
    if (n == 1) return;

    // One pass of bubble sort. After this pass, the largest element is shifted to the end.
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swapElements(arr[i], arr[i + 1]);
        }
    }

    // Check largest element fixed, recur for remaining array
    bubbleSortRecursive(arr, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bubbleSortIterative(arr1, n1);
    cout << "Bubble Sort Iterative: ";
    printArray(arr1, n1);

    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    bubbleSortRecursive(arr2, n2);
    cout << "Bubble Sort Recursive: ";
    printArray(arr2, n2);

    return 0;
}