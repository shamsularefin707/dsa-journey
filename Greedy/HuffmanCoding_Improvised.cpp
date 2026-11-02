#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include<queue>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare{
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};
bool isLeaf(Node* node){
    return !node->left && !node->right;
}

map<char, int> countFreq(const string& text){
    map<char, int> freq;
    for(char c: text){
        freq[c]++;
    }
    return freq;
}

// Build the Huffman tree from the input text
Node* buildHuffmanTree(map<char, int>& freq){
    if(freq.empty()) return nullptr;
    priority_queue<Node*, vector<Node*>, Compare> pq;
    
    for(auto& pair: freq){
        pq.push(new Node(pair.first, pair.second));
    }

    while(pq.size()>1){
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('\0', left->freq+right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    return pq.top();
}

void generateCodes(Node* root, const string& str, map<char, string>& codes){
    if(!root) return;

    if(root->ch != '\0'){
        codes[root->ch] = str.empty()? "0" : str;  // Handle the case of a single character
        return;
    }

    generateCodes(root->left, str + "0", codes);
    generateCodes(root->right, str + "1", codes);
}

string encode(const string& text, map<char, string>& codes){
    string encodedStr = "";
    for(char c: text){  
        encodedStr += codes[c];
    }
    return encodedStr;
}

string decode(Node* root, const string& encodedStr, int totalChars){
    string decodedStr = "";

    if(!root) return decodedStr;

    if(isLeaf(root)){
        return string(totalChars, root->ch);   // one char per bit
    }   
    Node* current = root;

    for(char bit: encodedStr){
        if(bit == '0'){
            current = current->left;
        } else {
            current = current->right;
        }

        if(!current->left && !current->right){
            decodedStr += current->ch;
            current = root;
        }
    }

    return decodedStr;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

//readfile
string readFile(const string& filename){
    ifstream file(filename, ios::binary);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
void writeFile(const string& filename, const string& data){
    ofstream file(filename, ios::binary);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    file << data;
}
//packBits -> real Bytes
string packBytes(const string& bits){
    string bytes = "";
    for(size_t i = 0; i < bits.size(); i += 8){
        unsigned char byte = 0;
        for(int j = 0; j < 8; j++){
            byte <<= 1;
            if(i+j < bits.size() && bits[i+j] == '1'){
                byte |= 1;
            }
        }
        bytes += (char)byte;
    }
    return bytes;
}
//unpackBytes -> real Bytes
string unpackBytes(const string& bytes){
    string bits = "";
    for(char c: bytes){
        unsigned char byte = (unsigned char)c;
        for(int i = 7; i >= 0; i--){
            bits += ((byte >> i) & 1) ? '1' : '0';
        }
    }
    return bits;
}

void encodedFile(const string& inputFile, const string& outputFile){
    string text = readFile(inputFile);

    map<char, int> freq = countFreq(text);
    Node* root = buildHuffmanTree(freq);
    map<char, string> codes;
    generateCodes(root, "", codes);

    cout << "Huffman Codes:\n";
    for(auto& pair: codes){
        cout << pair.first << ": " << pair.second << endl;
    }

    string encodedStr = encode(text, codes);
    ofstream outFile(outputFile, ios::binary);

    //header
    int count = freq.size();
    outFile.write((char*)&count, sizeof(count));
    for(auto& pair: freq){
        outFile.write((char*)&pair.first, sizeof(pair.first));
        outFile.write((char*)&pair.second, sizeof(pair.second));
    }

    //data
    string packedData = packBytes(encodedStr);
    outFile.write(packedData.c_str(), packedData.size());
    outFile.close();

    cout << "Original size: " << text.size() << " bytes" << endl;
    cout << "Encoded size: " << 4+count*5 +packedData.size() << " bytes" << endl; // 4 bytes for count, 5 bytes per char-freq pair
    freeTree(root);
}

void decodedFile(const string& inputFile, const string& outputFile){
    ifstream in(inputFile, ios::binary);
    if(!in){
        cout << "Cannot open " << inputFile << endl;
        return;
    }
    int count = 0;
    in.read((char*)&count, sizeof(count));

    map<char, int> freq;

    int totalChars = 0;
    for(int i = 0; i < count; i++){
        char c;
        int f;
        in.read((char*)&c, sizeof(c));
        in.read((char*)&f, sizeof(f));
        freq[c] = f;
        totalChars += f;
    }

    Node* root = buildHuffmanTree(freq);
    stringstream buffer;
    buffer << in.rdbuf();
    string encodedStr = unpackBytes(buffer.str());

    string decodedStr = decode(root, encodedStr, totalChars);
    writeFile(outputFile, decodedStr);
    cout << "Decoded size: " << decodedStr.size() << " bytes" << endl;
    freeTree(root);

}
int main(){
    int choice;
    string inputFile, outputFile;

    cout << "1. Encode a file\n";
    cout << "2. Decode a file\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Input file name: ";
    cin >> inputFile;
    cout << "Output file name: ";
    cin >> outputFile;

    if(choice == 1){
        encodedFile(inputFile, outputFile);
    } else if(choice == 2){
        decodedFile(inputFile, outputFile);
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}