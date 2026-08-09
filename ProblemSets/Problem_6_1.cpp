#include <iostream>

using namespace std;

enum Color { RED, BLACK };

struct RBTNode {
    int key;
    Color color;
    RBTNode *left, *right, *parent;

    RBTNode(int k) : key(k), color(RED), left(NULL), right(NULL), parent(NULL) {}
};

class RedBlackTree {
private:
    RBTNode* root;

    void rotateLeft(RBTNode*& ptr) {
        RBTNode* rightChild = ptr->right;
        ptr->right = rightChild->left;
        if (ptr->right != NULL) ptr->right->parent = ptr;
        rightChild->parent = ptr->parent;
        if (ptr->parent == NULL) root = rightChild;
        else if (ptr == ptr->parent->left) ptr->parent->left = rightChild;
        else ptr->parent->right = rightChild;
        rightChild->left = ptr;
        ptr->parent = rightChild;
    }

    void rotateRight(RBTNode*& ptr) {
        RBTNode* leftChild = ptr->left;
        ptr->left = leftChild->right;
        if (ptr->left != NULL) ptr->left->parent = ptr;
        leftChild->parent = ptr->parent;
        if (ptr->parent == NULL) root = leftChild;
        else if (ptr == ptr->parent->left) ptr->parent->left = leftChild;
        else ptr->parent->right = leftChild;
        leftChild->right = ptr;
        ptr->parent = leftChild;
    }

    void fixInsert(RBTNode*& ptr) {
        RBTNode* parent = NULL;
        RBTNode* grandParent = NULL;

        while ((ptr != root) && (ptr->color != BLACK) && (ptr->parent->color == RED)) {
            parent = ptr->parent;
            grandParent = ptr->parent->parent;

            if (parent == grandParent->left) {
                RBTNode* uncle = grandParent->right;
                if (uncle != NULL && uncle->color == RED) {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    ptr = grandParent;
                } else {
                    if (ptr == parent->right) {
                        rotateLeft(parent);
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    rotateRight(grandParent);
                    swap(parent->color, grandParent->color);
                    ptr = parent;
                }
            } else {
                RBTNode* uncle = grandParent->left;
                if (uncle != NULL && uncle->color == RED) {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    ptr = grandParent;
                } else {
                    if (ptr == parent->left) {
                        rotateRight(parent);
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    rotateLeft(grandParent);
                    swap(parent->color, grandParent->color);
                    ptr = parent;
                }
            }
        }
        root->color = BLACK;
    }

    void printLevelOrder(RBTNode* node) {
        if (!node) return;
        RBTNode* q[100];
        int head = 0, tail = 0;
        q[tail++] = node;

        while (head < tail) {
            RBTNode* curr = q[head++];
            cout << "Key: " << curr->key 
                 << " | Color: " << (curr->color == RED ? "RED" : "BLACK")
                 << " | Parent: " << (curr->parent ? to_string(curr->parent->key) : "NULL") << "\n";

            if (curr->left) q[tail++] = curr->left;
            if (curr->right) q[tail++] = curr->right;
        }
    }

public:
    RedBlackTree() : root(NULL) {}

    void insert(int key) {
        RBTNode* ptr = new RBTNode(key);
        if (!root) {
            ptr->color = BLACK;
            root = ptr;
            return;
        }

        RBTNode* curr = root;
        RBTNode* parent = NULL;
        while (curr != NULL) {
            parent = curr;
            if (key < curr->key) curr = curr->left;
            else curr = curr->right;
        }

        ptr->parent = parent;
        if (key < parent->key) parent->left = ptr;
        else parent->right = ptr;

        fixInsert(ptr);
    }

    void display() {
        printLevelOrder(root);
    }
};

int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);

    cout << "--- Red-Black Tree Level-Order Output ---\n";
    rbt.display();

    return 0;
}