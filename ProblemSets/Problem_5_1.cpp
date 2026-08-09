#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct FCNSNode {
    string name;
    int size;
    FCNSNode* firstChild;
    FCNSNode* nextSibling;

    FCNSNode(string n, int s) : name(n), size(s), firstChild(NULL), nextSibling(NULL) {}
};

int calculateTotalSize(FCNSNode* root) {
    if (!root) return 0;
    int total = root->size;
    total += calculateTotalSize(root->firstChild);
    total += calculateTotalSize(root->nextSibling);
    return total;
}

int calculateHeight(FCNSNode* root) {
    if (!root) return 0;
    int childHeight = calculateHeight(root->firstChild);
    int siblingHeight = calculateHeight(root->nextSibling);
    return max(1 + childHeight, siblingHeight);
}

int main() {
    FCNSNode* root = new FCNSNode("RootFolder", 0);
    FCNSNode* f1 = new FCNSNode("File1.txt", 50);
    FCNSNode* f2 = new FCNSNode("SubFolder", 0);
    FCNSNode* f3 = new FCNSNode("File2.txt", 100);

    root->firstChild = f1;
    f1->nextSibling = f2;
    f2->firstChild = f3;

    cout << "Total Size: " << calculateTotalSize(root) << " KB\n";
    cout << "Tree Height: " << calculateHeight(root) << "\n";

    return 0;
}