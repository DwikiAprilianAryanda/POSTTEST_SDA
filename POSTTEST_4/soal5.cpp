#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node *&head_ref) {
    // Hanya berjalan jika ada 2 node atau lebih
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    if (head_ref->next == head_ref->prev) {    // Kasus khusus jika hanya ada 2 node, tukar saja head dan tail
        head_ref = head_ref->next;
        return;
    }

    // Simpan pointer ke node-node penting
    Node* old_head = head_ref;
    Node* old_tail = head_ref->prev;
    Node* head_next = old_head->next; // node setelah head
    Node* tail_prev = old_tail->prev; // node sebelum tail

    // 1. Sambungkan node sebelum tail (tail_prev) dengan head lama.
    // ... tail_prev <-> head ...
    tail_prev->next = old_head;
    old_head->prev = tail_prev;

    // 2. Sambungkan node setelah head (head_next) dengan tail lama.
    // ... tail <-> head_next ...
    head_next->prev = old_tail;
    old_tail->next = head_next;
    
    // 3. Sambungkan head lama dan tail lama satu sama lain.
    // ... head <-> tail ...
    old_head->next = old_tail;
    old_tail->prev = old_head;

    // 4. Update head_ref. Head yang baru adalah tail yang lama.
    head_ref = old_tail;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head); // Expected output: 5 2 3 4 1

    return 0;
}