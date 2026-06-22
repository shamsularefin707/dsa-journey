#include <iostream>
#include <iomanip>
using namespace std;

void heapify(int arr[], int n, int i){
    int smallest = i; // Assume the root is the smallest
    int left = 2*i+1; //left child
    int right = 2*i+2; //right child

    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(arr,n,smallest);
    }
}

void buildMinHeap(int arr[], int n){
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    buildMinHeap(arr,n);
    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

int extractMin(int arr[], int& n){
    if(n <= 0){
        cout << "Heap is empty\n";
        return -1;
    }

    int min = arr[0];
    arr[0] = arr[n-1];
    n--;
    heapify(arr,n,0);
    return min;
}

void decreaseKey(int arr[], int i, int newVal){
    if(newVal > arr[i]){
        cout << "New value is larger than current value\n";
        return;
    }

    arr[i] = newVal;
    while(i > 0){
        int parent = (i-1)/2;
        if(arr[i] < arr[parent]){
            swap(arr[i], arr[parent]);
            i = parent;
        }else{
            break;
        }
    }
}


void printHeap(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
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
    int arr[] = {10, 20, 15, 30, 40, 8, 50, 99, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printHeap(arr,n);

    buildMinHeap(arr,n);
    cout << "Min-Heap: ";
    printHeap(arr,n);

    cout << "Visual representation of Min-Heap:\n";
    printVisual(arr,n,0,"",true);

    int min = extractMin(arr,n);
    cout << "Extracted min: " << min << endl;
    cout << "Min-Heap after extraction: ";
    printHeap(arr,n);

    decreaseKey(arr,2,5);
    cout << "Min-Heap after decreasing key: ";
    printHeap(arr,n);

    return 0;
}
