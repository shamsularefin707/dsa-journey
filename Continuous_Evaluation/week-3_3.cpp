//Insertion Sort using loops and recursion
#include <iostream>

using namespace std;

// ---- ITERATIVE INSERTION SORT ----
void insertionSortIterative(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ---- RECURSIVE INSERTION SORT ----
void insertionSortRecursive(int arr[], int n) {
    // Base case
    if (n <= 1) return;

    // Sort first n-1 elements recursively
    insertionSortRecursive(arr, n - 1);

    // Insert last element at its correct position in sorted array
    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    insertionSortIterative(arr1, n1);
    cout << "Insertion Sort Iterative: ";
    printArray(arr1, n1);

    int arr2[] = {12, 11, 13, 5, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    insertionSortRecursive(arr2, n2);
    cout << "Insertion Sort Recursive: ";
    printArray(arr2, n2);

    return 0;
}