#include <iostream>
using namespace std;

int min_idx(int arr[], int start, int n){
    int min_idx = start;
    for(int i = start + 1; i < n; i++){
        if(arr[i] < arr[min_idx]){
            min_idx = i;
        }
    }
    return min_idx;
}
void selectionSort(int arr[], int n){
    int minidx;
    for(int i = 0; i < n; i++){
        minidx = min_idx(arr, i, n);
        swap(arr[i], arr[minidx]);
    }
}

int main(){
    int arr[] = {11,9,5,31,22,11,2,90,99,101,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

