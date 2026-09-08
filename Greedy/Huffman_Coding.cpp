#include <bits/stdc++.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    char ch;
    int freq;
    Node* left, *right;

    Node(char character, int frequency){
        ch = character;
        freq = frequency;
        left = right = nullptr;

    }
};

struct compare{
    bool operator()(Node *left, Node *right){
        return left->freq > right->freq;
    }
};

void generateCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCodes){
    if(root == nullptr){
        return;
    }

    if(!root->left && !root->right){
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}


void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main(){
    cout << "Enter Text: ";
    string text;
    getline(cin, text);

    if(text.empty()){
        cout << "Empty String!\n";
    }
    unordered_map<char, int> freqMap;
    for(char ch: text){
        freqMap[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for(auto pair: freqMap){
        minHeap.push(new Node(pair.first, pair.second));
    }

    if(minHeap.size() == 1){
        Node* singleNode = minHeap.top();
        minHeap.pop();

        Node* root = new Node('\0', singleNode->freq);
        root->left = singleNode;
        minHeap.push(root);
    }

    while(minHeap.size() > 1){
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* combined = new Node('\0', left->freq+right->freq);
        combined->left = left;
        combined->right = right;

        minHeap.push(combined);
    }

    Node* root = minHeap.top();

    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    cout << "\n--- Huffman Codes ---\n";

    for(auto pair: huffmanCodes){
        if(pair.first == ' '){
            cout << " ' ' (space): " << pair.second << "\n";
        }
        else{
            cout << "'" << pair.first << "': " << pair.second << "\n";
        }
    }

    cout << "\n-----Output-----\n";
    cout << "Encoded Bitstring: ";

    for(char ch: text){
        cout << huffmanCodes[ch];
    }
    cout << endl;

    freeTree(root);
    return 0;
}




