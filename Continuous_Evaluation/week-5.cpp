//Linked List
#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList{
    Node* head;
    int size;
    public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList(){ // Destructor to free memory
        Node* current = head;
        while(current != nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void insertAtHead(int value){
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
        size++;
        cout << "Inserted " << value << " at head." << endl;
    }

    void insertAtTail(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        } else{
            Node* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
        cout << "Inserted " << value << " at tail." << endl;
    }

    void insertAtPosition(int value, int position){
        Node* newNode = new Node(value);
        if(position < 0 || position > size){
            cout << "Invalid position." << endl;
            delete newNode; // Free memory if position is invalid
            return;
        }

        if(position == 0){
            newNode->next = head;
            head = newNode;
            size++;
            cout << "Inserted " << value << " at position " << position << "." << endl;
            return;
        }
        else{
            Node* current = head;
            for(int i = 0; i < position-1; i++){
                current =  current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
            cout << "Inserted " << value << " at position " << position << "." << endl;
        }
    }


    void traverse(){
        Node* current = head;
        while(current != nullptr){
            cout << current->data << " ";
            cout << "-> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }


    void deleteAtHead(){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        cout << "Deleted head node." << endl;
    }

    void deleteAtTail(){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        if(head-> next == nullptr){
            delete head;
            head = nullptr;
            size--;
            cout << "Deleted tail node." << endl;
            return;
        }
        Node* current = head;

        while(current->next->next != nullptr){
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        size--;
        cout << "Deleted tail node." << endl;
    }

    void deleteAtPosition(int position){
        if(position < 0 || position >= size){
            cout << "Invalid Position." << endl;
            return;
        }
        if(position == 0){
            deleteAtHead();
            return;
        }

        Node* current = head;
        for(int i = 0; i < position-1; i++){
            current = current->next;
        }
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
        cout << "Deleted node at position " << position << "." << endl;
    }

    Node* search(int value){
        Node* current = head;
        while(current != nullptr){
            if(current->data == value){
                cout << "Value " << value << " found in the list." << endl;
                return current;
            }
            current = current->next;
        }
        cout << "Value " << value << " not found in the list." << endl;
        return nullptr;
    }

    void reverse(){
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev =  current;
            current = next;
        }
        head = prev;
        cout << "List reversed." << endl;
    }


    Node* getMid(Node* head){
        if(head == nullptr) return nullptr;
        Node* slow = head;
        Node* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* left, Node* right){
        Node dummy(0);
        Node* tail = &dummy;

        while(left && right){
            if(left->data <= right->data){
                tail->next = left;
                left = left->next;
            }
            else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        // attach the remaining nodes
        tail->next = left ? left : right;

        return dummy.next;
    }

    Node* mergeSort(Node* head){
        if(head == nullptr || head->next == nullptr) return head;
        Node* mid =  getMid(head);
        Node* rightHead = mid->next;
        mid->next = nullptr; // Split the list into two halves
        
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

        return merge(left, right);
    }

    Node* buildList(initializer_list<int> values){
        Node* head = nullptr;
        Node* tail = nullptr;
        for(int value : values){
            Node* newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
        return head;
    }

    void binarySearch(int value){
        Node* left = head;
        Node* right = nullptr;

        while(left != right){
            Node* mid = getMid(left);
            if(mid == nullptr) break;
            if(mid->data == value){
                cout << "Value " << value << " found in the list." << endl;
                return;
            }
            else if(mid->data < value){
                left = mid->next;
            }
            else{
                right = mid;
            }
        }
        cout << "Value " << value << " not found in the list." << endl;
    }
};



int main(){
    LinkedList list;
    Node* head = list.buildList({-19,38, 27, 43, 3, 9,-220, 82, 10});

    head = list.mergeSort(head);

    // Print sorted list
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;

    return 0;
}
