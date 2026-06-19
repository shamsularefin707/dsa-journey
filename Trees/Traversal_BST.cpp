//Preorder, Inorder and Postorder traversal of Binary Search Tree (BST) in C++
#include <iostream>
#include <iomanip>
#include <queue>
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

    if(val < root-> data){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
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

Node* constructBSTFromArray(int arr[], int n){
    Node* root = nullptr;
    for(int i = 0; i < n; i++){
        root = insert(root, arr[i]);
    }
    return root;
}

void preorderTraversal(Node* root){
    if(root == nullptr) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root){
    if(root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(root ==  nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr); // Level marker

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == nullptr){
            if(!q.empty()){
                q.push(nullptr); // Add marker for next level
                cout << endl; // New line for next level
                continue;
            }
            else{
                break; // No more nodes to process
            }
        }

        cout << curr->data << " ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
int main(){
    int values[] = {20, 10, 30, 5, 15, 25, 35};

    Node* root = constructBSTFromArray(values, sizeof(values)/sizeof(values[0]));
    cout << "Binary Search Tree constructed successfully\n";
    cout << endl;
    printTreeVisual(root);

    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "\nInorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "\nLevel-order Traversal: \n";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
