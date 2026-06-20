// C++ program to demonstrate deletion in a Binary Search Tree (BST)

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

Node* findMin(Node* root){
    while(root->left != nullptr && root != nullptr){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == nullptr) return root;

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key > root-> data){
        root->right = deleteNode(root->right, key);
    }else{
        if(root->left == nullptr){// Case with only right child or no child
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){// Case with only left child
            Node* temp = root->left;
            delete root;
            return temp;
        }else{// Case with two children
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}


int main(){
    int values[] = {20, 10, 30, 5, 15, 25, 35};

    Node* root = constructBSTFromArray(values, sizeof(values)/sizeof(values[0]));
    cout << "Binary Search Tree constructed successfully\n";
    cout << endl;
    printTreeVisual(root);

    cout << "\nInorder Traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;

    int keyToDelete = 10;
    root = deleteNode(root, keyToDelete);
    cout << "\nInorder Traversal after deleting " << keyToDelete << ": ";
    inorderTraversal(root);
    printTreeVisual(root);
    cout << endl;

    return 0;
}
