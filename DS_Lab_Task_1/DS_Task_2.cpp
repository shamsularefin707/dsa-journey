//Binary Tree to General Tree
#include <iostream>
#include <iomanip>
using namespace std;

struct BinaryNode{
    int data;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(int val) : data(val), left(nullptr), right(nullptr){}
};

struct GeneralNode{
    int data;
    GeneralNode* children[100]; // Assuming a maximum of 100 children for simplicity
    int childCount;
    GeneralNode(int val) : data(val), childCount(0){
        for(int i = 0; i < 100; i++){
            children[i] = nullptr;
        }
    }
};

GeneralNode* conversion(BinaryNode* binaryNode){
    if(binaryNode == nullptr) return nullptr;

    GeneralNode* child = new GeneralNode(binaryNode->data);
    BinaryNode* current = binaryNode->left;

    while(current != nullptr){
        child->children[child->childCount++] = conversion(current);
        current = current->right;
    }
    
    return child;
}

BinaryNode* buildSampleBinaryTree() {
    BinaryNode* root = new BinaryNode(1);

    root->left = new BinaryNode(2);          // first child of 1
    root->left->right = new BinaryNode(3);   // sibling of 2
    root->left->right->right = new BinaryNode(4); // sibling of 3

    root->left->left = new BinaryNode(5);    // child of 2

    return root;
}

void printGeneralTree(GeneralNode* root, int space = 0, int height = 5){
    if(root == nullptr) return;

    space += height;

    for(int i = height; i < space; i++){
        cout << " ";
    }
    cout << root->data << "\n";

    for(int i = 0; i < root->childCount; i++){
        printGeneralTree(root->children[i], space);
    }
}


int main(){
    BinaryNode* binaryRoot = buildSampleBinaryTree();
    GeneralNode* generalRoot = conversion(binaryRoot);

    cout << "General Tree Representation:\n";
    printGeneralTree(generalRoot);

    return 0;
}