#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int curr  = i;
        int prev = i - 1;
        while(prev >= 0 && arr[curr] < arr[prev]){
            arr[prev+1] = arr[prev];
        }
        arr[prev+1] = arr[curr];
    }
}

int main(){
    int arr[] = {11,9,5,31,22,11,2,90,99,101,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}