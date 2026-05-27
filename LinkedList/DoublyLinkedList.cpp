#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), prev(nullptr), next(nullptr){}
};

class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    int size;

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0){}


    //Insert at Head
    void insertAtHead(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at head." << endl;
        size++;
    }

    void insertAtTail(int value){
        Node* newNode = new Node(value);
        if(tail == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Inserted " << value << " at tail." << endl;
        size++;
    }

    void insertAtPosition(int value, int position){
        if(position < 0 || position > size){
            cout << "Invalid Position." << endl;
            return;
        }
        
        if(position == 0){
            insertAtHead(value);
            return;
        }
        if(position == size){
            insertAtTail(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head;

        for(int i = 0; i < position-1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
        cout << "Inserted " << value << " at position " << position << "." << endl;
    }

    void insertAfterValue(int afterValue, int value){
        Node* current = head;
        while(current != nullptr){
            if(current->data == afterValue){
                Node* newNode = new Node(value);
                newNode->next = current->next;
                newNode->prev = current;
                current->next = newNode;
                if(newNode->next != nullptr){
                    newNode->next->prev = newNode;
                }
                if(current == tail){
                    tail = newNode;
                }
                size++;
                cout << "Inserted " << value << " after " << afterValue << "." << endl;
                return;

            }
            current = current->next;
        }
        cout << "Value " << afterValue << " not found in the list." << endl;
    }

    void display(){
        Node* current = head;
        while(current != nullptr){
            cout << current->data << " " << "<-> ";
            current = current->next;

        }
        cout << "nullptr" << endl;
        return;
    }


    void deleteAtHead(){
        if(!head){
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head){
            head->prev = nullptr;
        }
        delete temp;
        size--;
        cout << "Deleted head node." << endl;
    }

    void deleteAtTail(){
        if(tail == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        if(tail-> prev == nullptr){
            delete tail;
            tail = nullptr;
            head = nullptr;
            size--;
            cout << "Deleted tail node." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp; //clear the memory of the old tail node
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
        if(position == size - 1){
            deleteAtTail();
            return;
        }
        Node* current = head;
        for(int i = 0; i < position; i++){
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
        cout << "Deleted node at position " << position << "." << endl;
    }

    void deleteValue(int value){
        Node* current = head;
        while(current != nullptr){
            if(current->data == value){
                if(current == head){
                    deleteAtHead();
                }
                else if(current == tail){
                    deleteAtTail();
                }
                else{
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    size--;
                    cout << "Deleted node with value " << value << "." << endl;
                }
            }
            current = current->next;
        }
    }

    Node* findMid(Node* left, Node* right){
        if(left == nullptr) return nullptr;
        Node* slow = left;
        Node* fast = left;
        // Move fast two steps and slow one step until fast reaches or passes right
        while(fast != right && fast->next != nullptr && fast->next != right){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    bool binarySearch(int value){
        Node* left = head;
        Node* right = tail;
        // loop while sublist [left..right] is non-empty
        while(left != nullptr && right != nullptr && left != right->next){
            Node* mid = findMid(left, right);
            if(mid == nullptr) break;
            if(mid->data == value){
                cout << "Value " << value << " found in the list." << endl;
                return true;
            }
            else if(mid->data < value){
                left = mid->next;
            }
            else{
                right = mid->prev;
            }
        }
        cout << "Value " << value << " not found in the list." << endl;
        return false;
    }

    ~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
}
};



int main(){
    DoublyLinkedList list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtPosition(15, 1);
    list.insertAfterValue(15, 17);
    list.display();


    list.binarySearch(15);
}
