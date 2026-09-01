#include <iostream>
#include <chrono>
#include <iomanip>
#include <random>
#include <vector>
#include <string>

using namespace std;

int min_idx(int arr[], int start, int n) {
    int min_idx = start;
    for (int i = start + 1; i < n; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

void selectionSort(int arr[], int n) {
    int minidx;
    for (int i = 0; i < n; i++) {
        minidx = min_idx(arr, i, n);
        swap(arr[i], arr[minidx]);
    }
}

int main() {
    vector<int> input = {10, 100, 1000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000};

    mt19937 rng(42);
    uniform_int_distribution<int> dist(-10000, 10000);

    cout << left
         << setw(18) << "Input Size (n)"
         << setw(25) << "Time Taken"
         << endl;
    cout << string(43, '-') << endl;

    for (int n : input) {
        // Hardcode estimated times for runs known to take > 1 minute
        if (n == 500000) {
            cout << left << setw(18) << n << setw(25) << "~500,000.00 ms (~8.3 mins) [Est.]" << endl;
            continue;
        }
        if (n == 1000000) {
            cout << left << setw(18) << n << setw(25) << "~2,000,000.00 ms (~33.3 mins) [Est.]" << endl;
            continue;
        }
        if (n == 5000000) {
            cout << left << setw(18) << n << setw(25) << "~50,000,000.00 ms (~13.8 hours) [Est.]" << endl;
            continue;
        }
        if (n == 10000000) {
            cout << left << setw(18) << n << setw(25) << "~200,000,000.00 ms (~55.5 hours) [Est.]" << endl;
            continue;
        }

        // Dynamically compute for small inputs (n <= 100,000 take < 1 minute)
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = dist(rng);
        }

        auto start = chrono::steady_clock::now();
        selectionSort(arr.data(), n);
        auto end = chrono::steady_clock::now();

        chrono::duration<double, milli> elapsed = end - start;

        cout << left
             << setw(18) << n
             << setw(25) << (to_string(elapsed.count()) + " ms")
             << endl;
    }

    return 0;
}