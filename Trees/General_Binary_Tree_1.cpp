//Unordered Tree, Manual Construction

#include <iostream>
#include <iomanip>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr){}
};

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
    // Manually construct:
    //          1
    //        /   \
    //       2      3
    //      / \      \
    //     4   5      6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Tree constructed successfully\n";
    cout << endl;

    printTreeVisual(root);

    return 0;
}
