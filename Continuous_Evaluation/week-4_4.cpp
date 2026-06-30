//mergeSort using Stack
#include <iostream>

using namespace std;

// Standard merge utility function
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

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
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

// Struct to represent a stack frame
struct MergeFrame {
    int low;
    int high;
    int stage; // 0 = Divide/Process, 1 = Ready to Merge
};

// Merge Sort using an explicit array-based stack of structs
void mergeSortUsingStack(int arr[], int n) {
    // A stack size of 2 * n is more than enough to safely hold pending frames
    MergeFrame stack[2 * n];
    int top = -1;

    // Push the initial array range into the stack
    stack[++top] = {0, n - 1, 0};

    while (top >= 0) {
        MergeFrame current = stack[top--];

        // Base case: segment has 1 or 0 elements
        if (current.low >= current.high) {
            continue;
        }

        int mid = current.low + (current.high - current.low) / 2;

        if (current.stage == 0) {
            // STEP 1: Push the execution commands onto our LIFO stack.
            // Because it's a stack, we push the merge command first so it executes LAST.
            
            // Push merge command for current range
            stack[++top] = {current.low, current.high, 1};
            
            // Push right subproblem command
            stack[++top] = {mid + 1, current.high, 0};
            
            // Push left subproblem command
            stack[++top] = {current.low, mid, 0};
        } 
        else if (current.stage == 1) {
            // STEP 2: Subproblems have popped and executed; perform the physical merge
            merge(arr, current.low, mid, current.high);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int data[] = {45, 21, 89, 12, 6, 77, 14};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Original Array: ";
    printArray(data, n);

    mergeSortUsingStack(data, n);

    cout << "Sorted Array (Merge Sort with Stack): ";
    printArray(data, n);

    return 0;
}