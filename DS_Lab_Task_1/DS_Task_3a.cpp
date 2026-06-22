#include <iostream>
#include <iomanip>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i; // Assume the root is the largest
    int left = 2*i+1; //left child
    int right = 2*i+2; //right child

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildMaxHeap(int arr[], int n){
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr,n);
    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

int extractMax(int arr[], int& n){
    if(n <= 0){
        cout << "Heap is empty\n";
        return -1;
    }
    int max = arr[0];
    arr[0] = arr[n-1];
    n--;
    heapify(arr,n,0);
    return max;
}

void increaseKey(int arr[], int i, int newVal){
    if(newVal < arr[i]){
        cout << "New value is smaller than current value\n";
        return;
    }

    arr[i] = newVal;
    int parent = (i-1)/2; 
    while(i>0){
        int parent = (i-1)/2;
        if(arr[i] > arr[parent]){
            swap(arr[i], arr[parent]);
            i = parent;
        }else{
            break;
        }
    }
}

void printVisual(int arr[], int n, int i, string indent, bool last){
    if(i < n){
        cout << indent;
        if(last){
            cout << "R----";
            indent += "     ";
        }else{
            cout << "L----";
            indent += "|    ";
        }
        cout << arr[i] << endl;
        printVisual(arr,n,2*i+1,indent,false);
        printVisual(arr,n,2*i+2,indent,true);
    }
}

int main(){
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    buildMaxHeap(arr,n);
    cout << "Max Heap: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    printVisual(arr,n,0,"",true);
    heapSort(arr,n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
