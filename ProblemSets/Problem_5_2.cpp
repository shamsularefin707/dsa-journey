#include <iostream>
#include <string>

using namespace std;

struct BSTNode {
    int key;
    string fileName;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int k, string name) : key(k), fileName(name), left(NULL), right(NULL) {}
};

BSTNode* insert(BSTNode* root, int key, string name) {
    if (!root) return new BSTNode(key, name);
    if (key < root->key) root->left = insert(root->left, key, name);
    else if (key > root->key) root->right = insert(root->right, key, name);
    return root;
}

BSTNode* findMin(BSTNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

BSTNode* deleteNode(BSTNode* root, int key) {
    if (!root) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        BSTNode* temp = findMin(root->right);
        root->key = temp->key;
        root->fileName = temp->fileName;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int countLeafNodes(BSTNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countInternalNodes(BSTNode* root) {
    if (!root || (!root->left && !root->right)) return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

void inorder(BSTNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " (" << root->fileName << ") ";
        inorder(root->right);
    }
}

int main() {
    BSTNode* root = NULL;
    root = insert(root, 50, "doc1");
    root = insert(root, 30, "doc2");
    root = insert(root, 70, "doc3");
    root = insert(root, 20, "doc4");
    root = insert(root, 40, "doc5");

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Leaf Nodes: " << countLeafNodes(root) << "\n";
    cout << "Internal Nodes: " << countInternalNodes(root) << "\n";

    root = deleteNode(root, 30);
    cout << "Inorder after deleting 30: ";
    inorder(root);
    cout << "\n";

    return 0;
}