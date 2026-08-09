#include <iostream>
using namespace std;

// Helper function to find the maximum element in the array
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Stable Counting Sort subroutine to sort arr[] according to the digit represented by exp
void countingSortByDigit(int arr[], int n, int exp) {
    int output[n];    // Output array
    int count[10] = {0}; // Base-10 digit counts initialized to 0

    // 1. Store count of occurrences of each digit at current exp place
    for (int i = 0; i < n; ++i) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // 2. Compute cumulative counts so count[i] has actual position of this digit in output[]
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // 3. Build the output array from right to left to preserve stability
    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 4. Copy sorted output array back into original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Main function to perform Radix Sort
void radixSort(int arr[], int n) {
    if (n <= 1) return;

    // 1. Find the maximum number to determine the number of digits
    int maxVal = getMax(arr, n);

    // 2. Perform Counting Sort for every digit (exp = 1 for 1s, 10 for 10s, 100 for 100s, etc.)
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, n, exp);
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    radixSort(arr, n);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}