//Building a binary tree from given postorder and inorder traversals and printing it visually.
#include <iostream>
#include <iomanip>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

int postIndex;

Node* buildTreePostIn(int postorder[], int inorder[], int inStart, int inEnd){
    if(inStart>inEnd) return nullptr;

    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);

    int rootpos;

    for(rootpos = inStart; rootpos <= inEnd; rootpos++){
        if(inorder[rootpos] == rootVal){
            break;
        }
    }

    root->right = buildTreePostIn(postorder, inorder, rootpos+1, inEnd);
    root->left = buildTreePostIn(postorder, inorder, inStart, rootpos-1);
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

int main(){
    int inorder[] = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};

    postIndex = sizeof(postorder)/sizeof(postorder[0]) - 1;
    Node* root = buildTreePostIn(postorder, inorder, 0, sizeof(inorder)/sizeof(inorder[0]) - 1);

    printTreeVisual(root);

    return 0;
}
