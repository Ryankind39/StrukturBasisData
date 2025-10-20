#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    return prev;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};

    cout << "Linked list sebelum dibalik: ";
    printLinkedList(head);

    // Membalik linked list
    head = reverseLinkedList(head);

    cout << "Linked list setelah dibalik: ";
    printLinkedList(head);

    return 0;
}