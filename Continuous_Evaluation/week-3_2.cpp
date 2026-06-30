//Selection Sort using recursion and loop
#include <iostream>

using namespace std;

void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// ---- ITERATIVE SELECTION SORT ----
void selectionSortIterative(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swapElements(arr[min_idx], arr[i]);
    }
}

// ---- RECURSIVE SELECTION SORT ----
void selectionSortRecursive(int arr[], int n, int index = 0) {
    // Base case: when starting index reaches the end
    if (index == n) return;

    // Find the minimum element in the unsorted subarray
    int min_idx = index;
    for (int j = index + 1; j < n; j++) {
        if (arr[j] < arr[min_idx]) {
            min_idx = j;
        }
    }

    // Swap the found minimum element with the current index element
    swapElements(arr[min_idx], arr[index]);

    // Recur for the remaining unsorted subarray
    selectionSortRecursive(arr, n, index + 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {29, 10, 14, 37, 13};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    selectionSortIterative(arr1, n1);
    cout << "Selection Sort Iterative: ";
    printArray(arr1, n1);

    int arr2[] = {29, 10, 14, 37, 13};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    selectionSortRecursive(arr2, n2);
    cout << "Selection Sort Recursive: ";
    printArray(arr2, n2);

    return 0;
}