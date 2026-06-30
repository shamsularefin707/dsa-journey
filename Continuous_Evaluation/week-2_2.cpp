//MergeSort using recursion and iteration
#include <iostream>

using namespace std;

// Utility function to find the minimum of two values
int min(int x, int y) { 
    return (x < y) ? x : y; 
}

// Merge function used by both recursive and iterative versions
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary raw arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// ---- 1. RECURSIVE MERGE SORT ----
void mergeSortRecursive(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortRecursive(arr, l, m);
        mergeSortRecursive(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// ---- 2. ITERATIVE MERGE SORT (BOTTOM-UP SUBARRAY LOOP) ----
void mergeSortIterative(int arr[], int n) {
    // curr_size shifts from 1 to 2, 4, 8, etc.
    for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        // Pick starting point of different subarrays of current size
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            // Find ending point of left subarray
            int mid = min(left_start + curr_size - 1, n - 1);

            // Find ending point of right subarray
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            // Merge subarrays arr[left_start...mid] and arr[mid+1...right_end]
            merge(arr, left_start, mid, right_end);
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
    int data1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(data1) / sizeof(data1[0]);

    cout << "Original Array 1: ";
    printArray(data1, n1);

    mergeSortRecursive(data1, 0, n1 - 1);
    cout << "Sorted with Recursive Merge Sort: ";
    printArray(data1, n1);

    cout << "---------------------------------------" << endl;

    int data2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = sizeof(data2) / sizeof(data2[0]);

    cout << "Original Array 2: ";
    printArray(data2, n2);

    mergeSortIterative(data2, n2);
    cout << "Sorted with Iterative Merge Sort: ";
    printArray(data2, n2);

    return 0;
}