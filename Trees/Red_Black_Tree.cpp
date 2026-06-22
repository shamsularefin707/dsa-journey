#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

enum Color { RED, BLACK };

struct RBNode{
    int data;
    Color color;
    RBNode* left,* right,* parent;

    RBNode(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr){}
};

class RBTree{
    public:
    RBNode* root;
    RBNode* NIL;
    RBTree(){
        NIL = new RBNode(0);
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL->parent = NIL;
        root = NIL;
    }
  

    void leftRotate(RBNode* x){ //Right-Right Case
        RBNode* y = x->right;
        x->right = y->left;
        y->parent = x->parent;

        if(y->left != NIL){
            y->left->parent = x;
        }
        if(x->parent == NIL){
            root = y;
        }else if(x == x->parent->left){
            x->parent->left = y;
        }else{
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(RBNode* x){ //Left-Left Case
        RBNode* y = x->left;
        x->left = y->right;
        y->parent = x->parent;
        if(y->right != NIL){
            y->right->parent = x;
        }
        if(x->parent == NIL){
            root = y;
        }else if(x == x->parent->right){
            x->parent->right = y;
        }else{
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insertFixup(RBNode* z){
        while(z->parent->color == RED){
            if(z->parent == z->parent->parent->left){ // Z->parent is left child
                RBNode* uncle = z->parent->parent->right;
                if(uncle->color == RED){ //Case 1: Uncle is RED
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else{ //Case 2 and Case 3: Uncle is BLACK
                    if(z == z->parent->right){ //Case 2: Z is right child
                        z = z->parent;
                        leftRotate(z);
                    }                 
                    //Case #3: Z is left child
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent); 
                }
            }else{ // Z->parent is right child
                RBNode* uncle = z->parent->parent->left;
                if(uncle->color == RED){ // Case 1: Uncle is RED
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }else{ // Case 2 and Case 3: Uncle is BLACK
                    if(z == z->parent->left){ // Case 2: Z is left child
                        z = z->parent;
                        rightRotate(z);
                    }else{ // Case 3: Z is right child
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        leftRotate(z->parent->parent);
                    }

                }
            }
        }
        root->color = BLACK;
    }

    
    


    void insert(int val){
        RBNode* z = new RBNode(val);
        z->color = RED;
        z->left = z->right = NIL;

        RBNode* y = NIL;
        RBNode* x = root;

        while(x != NIL){
            y = x;

            if(z->data < x->data){
                x = x->left;
            }
            else if(z->data > x->data){
                x = x->right;
            }else{
                delete z;
                return;
            }
        }
        z->parent = y;
        if(y == NIL){
            root = z;
        }else if(z->data < y->data){
            y->left = z;
        }else{
            y->right = z;
        }

        insertFixup(z);
    }

    void printTreeVisual(RBNode* node, string indent, bool last){
        if(node != NIL){
            cout << indent;
            if(last){
                cout << "R----";
                indent += "     ";
            }else{
                cout << "L----";
                indent += "|    ";
            }
            cout << node->data << "(" << (node->color == RED ? "RED" : "BLACK") << ")" << endl;
            printTreeVisual(node->left, indent, false);
            printTreeVisual(node->right, indent, true);
        }
    }
};


int main(){
    RBTree tree;
    int arr[] = {10, 20, 30, 15, 25, 5, 1};
    for(int val : arr){
        tree.insert(val);
    }

    cout << "Red-Black Tree Visualization:" << endl;
    tree.printTreeVisual(tree.root, "", true);

    return 0;
}
