//merging two sorted arrays

#include <iostream>

using namespace std;

// Function to merge two sorted arrays into a third array
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0; // Index for arr1
    int j = 0; // Index for arr2
    int k = 0; // Index for merged array
    
    // Traverse both arrays and copy the smaller element
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of arr1, if any
    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of arr2, if any
    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int arrayA[] = {1, 3, 5, 7};
    int n1 = sizeof(arrayA) / sizeof(arrayA[0]); // Calculate size of arrayA
    
    int arrayB[] = {2, 4, 6, 8, 10};
    int n2 = sizeof(arrayB) / sizeof(arrayB[0]); // Calculate size of arrayB
    
    // Create destination array to hold the merged elements
    int result[n1 + n2];
    
    mergeSortedArrays(arrayA, n1, arrayB, n2, result);
    
    cout << "Merged Array: ";
    for (int i = 0; i < (n1 + n2); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}