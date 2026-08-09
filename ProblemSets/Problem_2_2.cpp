#include <iostream>
#include <string>

using namespace std;

struct Book {
    int accessionID;
    string title;
};

int findLowerBound(Book arr[], int n, int min_id) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].accessionID >= min_id) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int findUpperBound(Book arr[], int n, int max_id) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].accessionID <= max_id) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

void rangeQueryBinary(Book arr[], int n, int min_id, int max_id) {
    int lb = findLowerBound(arr, n, min_id);
    int ub = findUpperBound(arr, n, max_id);

    if (lb != -1 && ub != -1 && lb <= ub) {
        cout << "Books in range [" << min_id << ", " << max_id << "] (Binary Search):\n";
        for (int i = lb; i <= ub; i++) {
            cout << "ID: " << arr[i].accessionID << " | Title: " << arr[i].title << "\n";
        }
    } else {
        cout << "No books found in range.\n";
    }
}

void rangeQueryLinear(Book arr[], int n, int min_id, int max_id) {
    cout << "Books in range [" << min_id << ", " << max_id << "] (Linear Search):\n";
    for (int i = 0; i < n; i++) {
        if (arr[i].accessionID >= min_id && arr[i].accessionID <= max_id) {
            cout << "ID: " << arr[i].accessionID << " | Title: " << arr[i].title << "\n";
        }
    }
}

int main() {
    Book catalog[10] = {
        {101, "DS Intro"}, {105, "Algo Design"}, {112, "OS Concepts"},
        {120, "DB Systems"}, {125, "Networking"}, {130, "AI Principles"},
        {142, "ML Guide"}, {150, "Web Dev"}, {165, "Cyber Security"}, {180, "Cloud Computing"}
    };

    int min_id = 110, max_id = 145;

    rangeQueryBinary(catalog, 10, min_id, max_id);
    cout << "\n";
    rangeQueryLinear(catalog, 10, min_id, max_id);

    return 0;
}