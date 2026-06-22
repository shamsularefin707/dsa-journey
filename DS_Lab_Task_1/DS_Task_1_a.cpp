//Building a binary tree from given preorder and inorder traversals and printing it visually.
#include <iostream>
#include <iomanip>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

int preIndex = 0;
Node* buildTreePreIn(int preorder[], int inorder[], int inStart, int inEnd){
    if(inStart > inEnd) return nullptr;
    
    int rootVal = preorder[preIndex++];
    Node* root = new Node( rootVal );
    int rootpos;
    for(rootpos = inStart; rootpos <= inEnd; rootpos++){
        if(inorder[rootpos] == rootVal){
            break;
        }
    }

    root->left = buildTreePreIn(preorder, inorder, inStart, rootpos-1);
    root->right = buildTreePreIn(preorder, inorder, rootpos+1, inEnd);
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
    int preorder[] = {1, 2, 4, 5, 3, 6};

    Node* root = buildTreePreIn(preorder, inorder, 0, sizeof(inorder)/sizeof(inorder[0]) - 1);

    printTreeVisual(root);

    return 0;
}
