//Binary Tree from Level-Order array
//-1 marks nullptr
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildFromLevelOrder(int arr[], int n){
    if(n == 0 || arr[0] == -1) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < n){
        Node* curr = q.front();
        q.pop();

        //left child
        if(arr[i] != -1 && i < n){
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        //right child
        if(arr[i] != -1 && i < n){
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
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

int main(){
    int arr[] = {1, 2, 3, 4, 5, -1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = buildFromLevelOrder(arr, n);
    cout << "Tree constructed successfully\n";
    cout << endl;

    printTreeVisual(root);

    return 0;
}
