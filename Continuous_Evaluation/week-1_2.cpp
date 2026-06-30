//Recursive Binary Search
#include <iostream>

using namespace std;

// Recursive function to perform binary search on a raw array
int recursiveBinarySearch(int arr[], int low, int high, int target) {
    // Base Case: Element is not present in the array
    if (low > high) {
        return -1;
    }
    
    // Prevent integer overflow
    int mid = low + (high - low) / 2;
    
    // Case 1: Target found
    if (arr[mid] == target) {
        return mid;
    }
    
    // Case 2: Target is smaller, look left
    if (arr[mid] > target) {
        return recursiveBinarySearch(arr, low, mid - 1, target);
    }
    
    // Case 3: Target is larger, look right
    return recursiveBinarySearch(arr, mid + 1, high, target);
}

int main() {
    int data[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(data) / sizeof(data[0]); // Calculate size of the array
    int target = 23;
    
    int resultIndex = recursiveBinarySearch(data, 0, n - 1, target);
    
    if (resultIndex != -1) {
        cout << "Element " << target << " found at index: " << resultIndex << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }
    
    return 0;
}