#include <iostream>
#include <string>

using namespace std;

struct Book {
    int accessionID;
    string title;
    long long timestamp;
};

long long comparisonCount = 0;

void insertionSort(Book arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        Book key = arr[i];
        int j = i - 1;
        while (j >= low) {
            comparisonCount++;
            if (arr[j].accessionID > key.accessionID) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

int medianOfThree(Book arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low].accessionID > arr[mid].accessionID) swap(arr[low], arr[mid]);
    if (arr[low].accessionID > arr[high].accessionID) swap(arr[low], arr[high]);
    if (arr[mid].accessionID > arr[high].accessionID) swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high - 1]);
    return arr[high - 1].accessionID;
}

int partition(Book arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = low;
    int j = high - 1;
    while (true) {
        while (arr[++i].accessionID < pivot) { comparisonCount++; }
        while (arr[--j].accessionID > pivot) { comparisonCount++; }
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[high - 1]);
    return i;
}

void hybridSort(Book arr[], int low, int high) {
    if (high - low + 1 < 10) {
        insertionSort(arr, low, high);
    } else {
        int pivotIndex = partition(arr, low, high);
        hybridSort(arr, low, pivotIndex - 1);
        hybridSort(arr, pivotIndex + 1, high);
    }
}

void bubbleSort(Book arr[], int n) {
    comparisonCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisonCount++;
            if (arr[j].accessionID > arr[j + 1].accessionID) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(Book arr[], int n) {
    comparisonCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisonCount++;
            if (arr[j].accessionID < arr[minIdx].accessionID) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int n = 15;
    Book books[15];

    for (int i = 0; i < n; i++) {
        books[i].accessionID = (i * 37 + 13) % 100;
        books[i].title = "Book " + to_string(books[i].accessionID);
        books[i].timestamp = 100000 + i;
    }

    comparisonCount = 0;
    hybridSort(books, 0, n - 1);

    cout << "Hybrid Sorted Array (Accession IDs):\n";
    for (int i = 0; i < n; i++) {
        cout << books[i].accessionID << " ";
    }
    cout << "\nHybrid Sort Comparisons: " << comparisonCount << "\n";

    return 0;
}