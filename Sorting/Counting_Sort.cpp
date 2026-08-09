#include <iostream>
using namespace std;

// Function to perform Counting Sort on an array
void countingSort(int arr[], int n) {
    if (n <= 0) return;

    // 1. Find min and max elements to handle positive/negative range
    int minVal = arr[0];
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int range = maxVal - minVal + 1;

    // 2. Dynamic allocations for dynamic array sizes
    int* count = new int[range](); // Initialized to 0
    int* output = new int[n];

    // 3. Store the frequency of each element
    for (int i = 0; i < n; ++i) {
        count[arr[i] - minVal]++;
    }

    // 4. Calculate cumulative counts (prefix sum)
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    // 5. Build output array in reverse to preserve stability
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // 6. Copy sorted elements back into original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }

    // Clean up dynamically allocated memory
    delete[] count;
    delete[] output;
}

int main() {
    int arr[] = {4, -2, 2, 8, 3, 3, -2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    countingSort(arr, n);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}