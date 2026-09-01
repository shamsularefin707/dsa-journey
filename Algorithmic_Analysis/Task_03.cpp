//Analysis of O(nlogn) via Merge Sort
#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <random>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int n1 = mid -left +1;
    int n2 = right - mid;
    vector<int>L(n1);
    vector<int>R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid+j+1];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}
void mergeSort(int arr[], int left, int right){
    if(left >= right) return;

    int mid = left + (right-left)/2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid,right);
}

int main(){
    vector<int> input = {10, 100, 1000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000};
    mt19937 rng(42);
    uniform_int_distribution<int> dist(-10000, 10000);
    cout << left
         << setw(15) << "Input Size (n)"
         << setw(20) << "Time Taken (ms)"
         << setw(25) << "Move Count"
         << endl;
    cout << string(43, '-') << endl;

    for(int n: input){
        vector<int>arr(n);
        for(int i = 0; i<n; i++){
            arr[i] = dist(rng);
        }

        auto start = chrono::steady_clock::now();
        mergeSort(arr.data(), 0,arr.size()-1);
        auto end = chrono::steady_clock::now();

        chrono::duration<double, milli> elapsed = end-start;

        cout << left 
             << setw(15) << n
             << setw(20) << elapsed.count()
             << endl;

    }

    return 0;
}