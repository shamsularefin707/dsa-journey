//Iterative implementation of Binary Search Tree (BST) in C++
 
#include <iostream>
#include <iomanip>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

Node* insert(Node* root, int val){
    if(root == nullptr){
        return new Node(val);
    }

    Node* current = root;
    Node* parent = nullptr;

    while(current != nullptr){
        parent = current;

        if(val < current->data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }

    if(val < parent->data){
        parent->left = new Node(val);
    }
    else{
        parent->right = new Node(val);
    }

    return root;
}


void printTreeVisual(Node* root, int space = 0, int height = 5) {
    // Base case
    if (root == nullptr) return;

    // Increase distance between levels
    space += height;

    // Process right child first (prints at the top)
    printTreeVisual(root->right, space);

    // Print current node after spaces
    cout << endl;
    for (int i = height; i < space; i++) {
        cout << " ";
    }
    cout << root->data << "\n";

    // Process left child (prints at the bottom)
    printTreeVisual(root->left, space);
}

Node* constructBSTFromArray(int arr[], int n) {
    Node* root = nullptr;
    for(int i = 0; i < n; ++i) {
        root = insert(root, arr[i]);
    }
    return root;
}

int main(){

    int values[] = {50, 30, 70, 20, 40, 60, 80};

    Node* root = constructBSTFromArray(values, sizeof(values)/sizeof(values[0]));
    cout << "Binary Search Tree constructed successfully\n";
    cout << endl;
    printTreeVisual(root);

    return 0;
}
