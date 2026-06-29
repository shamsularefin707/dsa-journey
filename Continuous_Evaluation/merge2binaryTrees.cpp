#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
    if(t1 == nullptr) return t2;
    if(t2 == nullptr) return t1;

    t1->val += t2->val;

    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

TreeNode* buildTree(int arr[], int size){
    if (size <= 0 || arr[0] == -1)
        return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < size) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < size && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < size && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}
void printVisual(TreeNode* root, int space = 0, int height = 10){
    if(root == nullptr) return;

    space += height;

    printVisual(root->right, space);

    cout << endl;
    for(int i = height; i < space; i++){
        cout << " ";
    }
    cout << root->val << "\n";

    printVisual(root->left, space);
}

int main(){
    int arr1[] = {1, 3, 2, 5};
    int arr2[] = {2, 1, 3, -1, 4, -1, 7};

    TreeNode* t1 = buildTree(arr1, sizeof(arr1)/sizeof(arr1[0]));
    TreeNode* t2 = buildTree(arr2, sizeof(arr2)/sizeof(arr2[0]));

    cout << "Tree 1:" << endl;
    printVisual(t1);
    cout << "\nTree 2:" << endl;
    printVisual(t2);

    TreeNode* mergedTree = mergeTrees(t1, t2);
    cout << "\nMerged Tree:" << endl;
    printVisual(mergedTree);

    return 0;
}