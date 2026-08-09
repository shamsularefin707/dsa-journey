#include <iostream>
#include <string>

using namespace std;

struct PatientRecord {
    long long nationalID;
    int triageScore;
};

void countingSortForRadix(PatientRecord arr[], int n, long long exp) {
    PatientRecord output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i].nationalID / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i].nationalID / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(PatientRecord arr[], int n) {
    long long maxID = arr[0].nationalID;
    for (int i = 1; i < n; i++) {
        if (arr[i].nationalID > maxID) maxID = arr[i].nationalID;
    }

    for (long long exp = 1; maxID / exp > 0; exp *= 10) {
        countingSortForRadix(arr, n, exp);
    }
}

void countingSortTriage(PatientRecord arr[], int n) {
    PatientRecord output[100];
    int count[6] = {0};

    for (int i = 0; i < n; i++) {
        count[arr[i].triageScore]++;
    }

    for (int i = 1; i <= 5; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i].triageScore] - 1] = arr[i];
        count[arr[i].triageScore]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    PatientRecord records[5] = {
        {100234, 3}, {100112, 1}, {100543, 2}, {100001, 1}, {100099, 5}
    };

    radixSort(records, 5);

    cout << "Sorted by National ID (Radix Sort):\n";
    for (int i = 0; i < 5; i++) {
        cout << "NID: " << records[i].nationalID << " | Triage: " << records[i].triageScore << "\n";
    }

    countingSortTriage(records, 5);

    cout << "\nSorted by Triage Score (Counting Sort):\n";
    for (int i = 0; i < 5; i++) {
        cout << "NID: " << records[i].nationalID << " | Triage: " << records[i].triageScore << "\n";
    }

    return 0;
}