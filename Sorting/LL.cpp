#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    Node* insertAtHead(int val){
        if(head == nullptr){
            head = new Node(val);
            return head;
        }
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* insertAtTail(int val){
        if(head == nullptr){
            head =  new Node(val);
            return head;
        }
        Node* curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = new Node(val);
        return head;
    }

    Node* insertAtPosition(int val, int pos){
        if(pos == 0){
            return insertAtHead(val);
        }
        Node* curr = head;
        for(int i = 0; i < pos-1 && curr != nullptr;i++){
            curr = curr->next;
        }
        if(curr == nullptr){
            return head;
        }
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        return head;
    }

    void printList(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    Node* deletehead(){
        if(head == nullptr){
            return nullptr;
        }
        Node* temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
    Node* deleteTail(){
        if(head ==  nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return head;
        }
        Node* curr =head;
        while(curr->next->next != nullptr){
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
        return head;
    }
    Node* deleteAtPosition(int pos){
        if(pos == 0){
            return deletehead();
        }
        Node* curr = head;
        for(int i = 0; i < pos-1 && curr != nullptr; i++){
            curr = curr->next;
        }
        if(curr == nullptr || curr->next == nullptr){
            return head;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return head;
    }
};

int main(){
    LinkedList ll;
    ll.insertAtHead(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtPosition(4, 1);
    ll.printList();
    ll.deletehead();
    ll.printList();
    ll.deleteTail();
    ll.printList();
    ll.deleteAtPosition(1);
    ll.printList();
    return 0;
}

