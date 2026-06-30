//QuickSort using Stack
#include <iostream>

using namespace std;

// Utility function to swap two elements
void swapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function (Lomuto partition scheme)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swapElements(arr[i], arr[j]);
        }
    }
    swapElements(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort using an explicit array-based stack
void quickSortUsingStack(int arr[], int n) {
    // Create an auxiliary stack array to store low and high indices
    int stack[n];
    int top = -1;

    // Push initial values of low and high to the stack
    stack[++top] = 0;      // low
    stack[++top] = n - 1;  // high

    // Keep popping from the stack while it is not empty
    while (top >= 0) {
        // Pop high and low boundaries
        int high = stack[top--];
        int low = stack[top--];

        // Set pivot element at its correct sorted position
        int pi = partition(arr, low, high);

        // If there are elements on the left side of pivot, push boundaries to stack
        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        // If there are elements on the right side of pivot, push boundaries to stack
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int data[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Original Array: ";
    printArray(data, n);

    quickSortUsingStack(data, n);

    cout << "Sorted Array (Quick Sort with Stack): ";
    printArray(data, n);

    return 0;
}