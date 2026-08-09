#include <iostream>
#include <string>

using namespace std;

struct DLLNode {
    string text;
    int lineNum;
    int charCount;
    DLLNode* prev;
    DLLNode* next;
};

struct SLLNode {
    string text;
    int charCount;
    SLLNode* next;
};

class DocumentEditor {
public:
    DLLNode* head;
    DLLNode* tail;
    SLLNode* clipboardHead;

    DocumentEditor() : head(NULL), tail(NULL), clipboardHead(NULL) {}

    void insertLine(int index, string text) {
        DLLNode* newNode = new DLLNode{text, 0, (int)text.length(), NULL, NULL};
        if (!head) {
            head = tail = newNode;
        } else if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            DLLNode* curr = head;
            for (int i = 0; i < index - 1 && curr->next; i++) curr = curr->next;
            newNode->next = curr->next;
            newNode->prev = curr;
            if (curr->next) curr->next->prev = newNode;
            else tail = newNode;
            curr->next = newNode;
        }
        reindex();
    }

    void deleteLine(int index) {
        if (!head) return;
        DLLNode* curr = head;
        for (int i = 0; i < index && curr; i++) curr = curr->next;
        if (!curr) return;

        if (curr->prev) curr->prev->next = curr->next;
        else head = curr->next;

        if (curr->next) curr->next->prev = curr->prev;
        else tail = curr->prev;

        delete curr;
        reindex();
    }

    void swapLines(DLLNode* node1, DLLNode* node2) {
        if (!node1 || !node2 || node1 == node2) return;
        string tempText = node1->text;
        int tempCharCount = node1->charCount;
        node1->text = node2->text;
        node1->charCount = node2->charCount;
        node2->text = tempText;
        node2->charCount = tempCharCount;
    }

    void cutToClipboard(int index) {
        DLLNode* curr = head;
        for (int i = 0; i < index && curr; i++) curr = curr->next;
        if (!curr) return;

        SLLNode* clipNode = new SLLNode{curr->text, curr->charCount, clipboardHead};
        clipboardHead = clipNode;

        deleteLine(index);
    }

    void pasteFromClipboard(int index) {
        if (!clipboardHead) return;
        SLLNode* temp = clipboardHead;
        insertLine(index, temp->text);
        clipboardHead = clipboardHead->next;
        delete temp;
    }

    void reindex() {
        DLLNode* curr = head;
        int idx = 1;
        while (curr) {
            curr->lineNum = idx++;
            curr = curr->next;
        }
    }

    void printDoc() {
        DLLNode* curr = head;
        cout << "--- Document ---\n";
        while (curr) {
            cout << "Line " << curr->lineNum << " [" << curr->charCount << " chars]: " << curr->text << "\n";
            curr = curr->next;
        }
    }
};

int main() {
    DocumentEditor doc;
    doc.insertLine(0, "First Line");
    doc.insertLine(1, "Second Line");
    doc.insertLine(2, "Third Line");
    doc.printDoc();

    doc.cutToClipboard(1);
    cout << "\nAfter Cut Line 2:\n";
    doc.printDoc();

    doc.pasteFromClipboard(0);
    cout << "\nAfter Paste at Top:\n";
    doc.printDoc();

    return 0;
}