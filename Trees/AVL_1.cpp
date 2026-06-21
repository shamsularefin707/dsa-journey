#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

struct AVLNode{
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1){}
};

int height(AVLNode* node){
    if(node == nullptr) return 0;
    return node->height;
}

int getBalance(AVLNode* node){
    if(node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

int updateHeight(AVLNode* node){
    if(node == nullptr) return 0;
    return 1 + max(height(node->left), height(node->right));
}

/*
      y                x
     / \              / \
    x   T3    ───►   T1  y
   / \                  / \
  T1 T2                T2 T3

*/

AVLNode* rightRotate(AVLNode* y){ //Left-Left Case
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x; //New root
}

AVLNode* leftRotate(AVLNode* x){ //Right-Right Case
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y; //New root
}

AVLNode* insertAVL(AVLNode* node, int val){

    if(node == nullptr) return new AVLNode(val);

    if(val < node->data){
        node->left = insertAVL(node->left, val);
    }else if(val > node->data){
        node->right = insertAVL(node->right, val);
    }else{
        return node;
    }

    updateHeight(node);

    int balance = getBalance(node);

    if(balance > 1 && val < node->left->data){ // Left-Left Case
        return rightRotate(node);
    }
    if(balance < -1 && val > node->right->data){ // Right-Right Case
        return leftRotate(node);
    }
    if(balance > 1 && val > node->left->data){ //Left-Right Case
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance < -1 && val < node->right->data){ //Right-Left Case
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

AVLNode* minValueNode(AVLNode* node){
    AVLNode* curr = node;

    while(curr->left) curr = curr->left;

    return curr;
}

AVLNode* deleteAVL(AVLNode* root, int val){
    if(!root) return root;

    if(val < root->data){
        root->left = deleteAVL(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteAVL(root->right, val);
    }else{
        if(!root->left || !root->right){
            AVLNode* temp = root->left? root->left : root->right;

            if(!temp){
                temp = root;
                root = nullptr;
            }else{
                *root = *temp; // Copy the contents of the non-empty child
            }
        }else{
            AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteAVL(root->right, temp->data);
        }
    }

    if(!root) return root;

    updateHeight(root);
    int balance = getBalance(root);

    if(balance > 1 && getBalance(root->left) >= 0){ //Left-Left Case
        return rightRotate(root);
    }
    if(balance < -1 && getBalance(root->right) <= 0){ //Right-Right Case
        return leftRotate(root);
    }
    if(balance > 1 && getBalance(root->left) < 0){ //left-right case
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && getBalance(root-> right) >= 0){ //right-left case
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printTreeVisual(AVLNode* root, int space = 0, int height = 5) {
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

AVLNode* search(AVLNode* root, int key){
    if(root == nullptr || root->data == key) return root;
    else if(key < root->data) return search(root->left, key);
    else return search(root->right, key);
} 

void preorderTraversal(AVLNode* root){
    if(!root) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(AVLNode* root){
    if(!root) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(AVLNode* root){
    if(!root) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(AVLNode* root){
    if(!root) return;

    queue<AVLNode*> q;
    q.push(root);

    while(!q.empty()){
        AVLNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}
int main(){
    int values[] = {30, 20, 40, 10, 25, 80, 50, 90};
    int n = sizeof(values)/sizeof(values[0]);

    AVLNode* avlRoot = nullptr;
    for(int i = 0; i < n; i++){
        avlRoot = insertAVL(avlRoot, values[i]);
    }

    printTreeVisual(avlRoot); // Reusing the same print function for AVL tree

    deleteAVL(avlRoot, 20);
    cout << "\nAfter deleting 20:\n";
    printTreeVisual(avlRoot);
    
    return 0;
}
