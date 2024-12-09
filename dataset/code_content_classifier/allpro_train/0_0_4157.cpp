#include <iostream>
#include <string>

using namespace std;

struct Node {
    int key;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int x) {
        Node* newNode = new Node();
        newNode->key = x;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
    }

    void deleteFirst() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void deleteLast() {
        if (tail == nullptr) {
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void deleteKey(int x) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->key == x) {
                if (curr == head) {
                    deleteFirst();
                } else if (curr == tail) {
                    deleteLast();
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                }
                break;
            }
            curr = curr->next;
        }
    }

    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    DoubleLinkedList list;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            int x;
            cin >> x;
            list.insert(x);
        } else if (command == "delete") {
            int x;
            cin >> x;
            list.deleteKey(x);
        } else if (command == "deleteFirst") {
            list.deleteFirst();
        } else if (command == "deleteLast") {
            list.deleteLast();
        }
    }

    list.printList();

    return 0;
}