/*
C++ program to construct a Binary Search Tree (BST) from an array of values 
and perform inorder traversal and search operation
*/

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

    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

Node* constructBSTFromArray(int arr[], int n){
    Node* root = nullptr;
    for(int i = 0; i < n; i++){
        root = insert(root, arr[i]);
    }
    return root;
}


void printTreeVisual(Node* root, int space = 0, int height = 5){
    if(root == nullptr) return;

    space += height;

    printTreeVisual(root->right, space);
    cout << endl;

    for(int i = height; i < space; i++){
        cout << " ";
    }
    cout << root->data << "\n";

    printTreeVisual(root->left, space);

    cout << endl;
}

void inorderTraversal(Node* root){
    if(root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

bool search(Node* root, int key){
    if(root == nullptr) return false;

    if(root->data == key) return true;
    
    if(key < root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

int main(){
    int values[] = {20, 10, 30, 5, 15, 25, 35};

    Node* root = constructBSTFromArray(values, sizeof(values)/sizeof(values[0]));
    cout << "Binary Search Tree constructed successfully\n";
    cout << endl;
    printTreeVisual(root);

    cout << "\nInorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    int keyToSearch = 15;
    if(search(root, keyToSearch)){
        cout << "Key " << keyToSearch << " found in the BST.\n";
    }
    else{
        cout << "Key " << keyToSearch << " not found in the BST.\n";
    }

    return 0;
}
